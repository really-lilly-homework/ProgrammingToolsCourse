/*Lillian Tatka -- CSE374 HW4 -- 2021-05-05*/
/*Word Count*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define MAX_LENGTH 100 //Maximum string size
#define MAX_INPUT 500


void checkFileExists(const char * filename) {
  if(!access(filename, F_OK) == 0) {
    fprintf(stderr, "%s does not exist.\n", filename);
    exit(EXIT_FAILURE);
  }
}

void checkArguments(int argc) {
  if( argc < 2 ) {
    fprintf(stderr, "Too few arguments.\n");
    exit(EXIT_FAILURE);
  }
  else if( argc > 2 ) {
    fprintf(stderr, "Too many arguments.\n");
    exit(EXIT_FAILURE);
  }    
}

void wordCount(const char * filename) {
  FILE *fp = fopen(filename, "r");
  if(fp == NULL) {
    fprintf(stderr, "Error opening the file.\n");
    exit(EXIT_FAILURE);
  }

  int wordcount = 0;
  int linecount = 0;
  int charcount = 0;
  char ch = getc(fp);
  

  while(ch != EOF) {
    charcount++;
    if(ch == ' ' || ch == '\n'){
      wordcount++;
      if(ch == '\n') {
	linecount++;
      }
    }
    ch = getc(fp);
  }

  printf(" %d %d %d %s\n", linecount, wordcount, charcount, filename);
  
}




int main( int argc, char *argv[] ) {

  checkArguments(argc);
 
  char* filename = argv[1];
  checkFileExists(filename);

  FILE *fp = fopen(filename, "r");
  if(fp == NULL) {
    fprintf(stderr, "Error opening the file.\n");
    exit(EXIT_FAILURE);
  }

  wordCount(filename);

  
  return 0;
}
