/*Lillian Tatka -- CSE374 HW4 -- 2021-05-05*/
/*Word Count*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
 * Check if a file exists by trying to open it.
 * return 1 if it exists.
 * return 0 if it does not exist.
*/
int checkFileExists(const char * filename) {
  if(access(filename, F_OK) == 0) {
    return 1;
  }
  else {
    printf(printf("File %s does not exist.", filename));
    return 0;
  }
}

/*
 * Check if the correct number of arguments is supplied
 * Returns 0 if true.
 * Returns 1 if the number of arguments is incorrect.
*/
int checkArguments(int argc) {
  if( argc < 2 ) {
    printf("Too few arguments.");
    return 1;
  }
  else if( argc > 2 ) {
    printf("Too many arguments.");
    return 1;
  }
    return 0;    
}




int main( int argc, char ** argv ) {
 
  int correctArgs = checkArguments(argc);
  if(correctArgs != 0) {
    return 1;
  }
    
  char* filename = argv[1];
  int exists = checkFileExists(filename);
  if(!exists) {
    return 1;
  }


  

  return 0;
}
