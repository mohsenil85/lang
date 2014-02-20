#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#include "parse.h"

void quit(){
  fprintf(stderr, "memory exhausted");
  exit(1);
}

void header(){
  printf("\n*****************************************************\n");
  printf("\nwelcome to the repl\ntype 'quit' to end\n");
}
void tailer(){
  printf("\n*****************************************************\n");
  printf("bye!\n");
  printf("\n");
}

int repl(){
  int input;
  bool done = false;
  int buffer_size = 64;
  char* word = (char*) malloc(buffer_size);
  if (word == 0) quit();
  
  header();

  while(!done){ 

    //printf("starting...\n");
    printf("\n>  ");
    while (true){
      //printf("top of loop...\n");
      input = getchar();
      if (input == EOF)  break; 
      if (!isspace(input)){
        ungetc(input, stdin);
        break;
      }
    }

  parse(word);
  }//end big while
  tailer();
  free(word);
  return 0;

}

