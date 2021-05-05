/*Lillian Tatka -- CSE374 HW4 -- 2021-05-05*/
/*MAKE LEET*/
/*This program takes a text file, translates it to "leet" and prints the result as well as wordcount of file.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void checkArguments(int num_args);
FILE * openFile(const char * filename);
int * wordCount(FILE *fileptr);
void replaceChars(FILE *fileptr, int * result);


int main( int argc, char *argv[] ) {

  
  checkArguments(argc);

  char *filename =argv[1];
  FILE *fileptr = openFile(filename);
  int *wordcount = wordCount(fileptr);
  
  replaceChars(fileptr, wordcount);
  printf("FILE STATS:\n");
  printf(" %d %d %d %s\n", *wordcount, *(wordcount+1), *(wordcount+2), filename);
  free(wordcount);
  fclose(fileptr);
  return 0;
}


/*
 *Check that the arguments are properly supplied: exactly one filename
 *IN: int num_args, the number of arguments supplied at runtime 
 *EXCEPTION: exit with error if the arguments are incorrect
 */
void checkArguments(int num_args) {
  if( num_args < 2 ) {
    fprintf(stderr, "Too few arguments.\n");
    exit(EXIT_FAILURE);
  }
  else if( num_args > 2 ) {
    fprintf(stderr, "Too many arguments.\n");
    exit(EXIT_FAILURE);
  }    
}


FILE * openFile(const char * filename) {
  //Check that file exists
  if(!access(filename, F_OK) == 0) {
    fprintf(stderr, "%s does not exist.\n", filename);
    exit(EXIT_FAILURE);
  }
  //Check that we can open the file
  FILE *fileptr = fopen(filename, "r");
  if(fileptr == NULL) {
    fprintf(stderr, "Error opening the file.\n");
    exit(EXIT_FAILURE);
  }
  return fileptr;
}

/*
 *Count the number of lines, words, and characters in a given file
 *IN: a pointer to the filename
 *OUT: a pointer to an int array containing the counts
 */
int * wordCount(FILE *fileptr) {
  
  int wordcount = 0;
  int linecount = 0;
  int charcount = 0;
  char curr_ch = getc(fileptr); //current character in the supplied file

  // Read through each character and count lines, words, characters
  while(curr_ch != EOF) {
    charcount++;
    if(curr_ch == ' ' || curr_ch == '\n'){
      wordcount++;
      if(curr_ch == '\n') {
	linecount++;
      }
    }
    curr_ch = getc(fileptr);
  }
  fseek(fileptr, 0, SEEK_SET);

  // Construct result array and return pointer
  int *countarray = (int *) malloc(3 * sizeof(int));
  countarray[0] = linecount;
  countarray[1] = wordcount;
  countarray[2] = charcount;

  return countarray;
  
}

/*
 *Translate the file contents into leet text and print the result
 *IN: a pointer to the filename, a pointer to a wordcount result array
 *EXCEPTION: exit with error if unable to open the file
 */
void replaceChars(FILE *fileptr, int * result) {
  char curr_ch = getc(fileptr); // The current character in the supplied file
  int newstr_index = 0; // The next index in the new string
  char * newString = (char *) malloc(*(result+2) * sizeof(char));
  
  // Read character by character and add to newString
  while(curr_ch != EOF) {
    
    if(curr_ch == 'a'){
      *(newString + newstr_index) = 'A';
    }
    else if(curr_ch == 's' || curr_ch == 'S'){
      *(newString + newstr_index) = '$';
    }
    else if(curr_ch == 'o' || curr_ch == 'O'){
      *(newString + newstr_index) = '*';
    }
    else if(curr_ch == 'e'){
      *(newString + newstr_index) = '3';
    }
    else if(curr_ch == 't'){
      *(newString + newstr_index) = '7';
    }
    else {
       *(newString + newstr_index) = curr_ch;
    }
    // Increment current character and index
    curr_ch = getc(fileptr);
    newstr_index++;
  }
  fseek(fileptr, 0, SEEK_SET);
  printf("%s\n", newString);
  free(newString);

}




