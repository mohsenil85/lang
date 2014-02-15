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
  printf("welcom\n quit to end\n");
}

int repl(){
  int input;
  bool done = false;
  int buffer_size = 64;
  char* line = (char*) malloc(buffer_size);
  if (line == 0) quit();
  
  header();

  while(!done){ 

    //printf("starting...\n");
    while (true){
      //printf("top of loop...\n");
      input = getchar();
      if (input == EOF)  break; 
      if (!isspace(input)){
        ungetc(input, stdin);
        break;
      }
    }

    int i = 0;
    while (true){
      //printf("top of loop 2...\n");
      int input = getchar();
      if (isspace(input) || input == EOF) {
        line[i] = 0;
        break;
      }
      //printf("now parsing this char:  %c\n", (char)input);
      line[i] = input;
      if (i == buffer_size - 1){
        buffer_size = buffer_size + buffer_size;
        //printf("*****************buffer expanded!***************\n");
        line = (char*) realloc(line, buffer_size);
        if (line == 0) quit();
      }
      i++;
      
    }
    //printf("parsing...\n");
    parse(line);

    if (strcmp(line, "quit") == 0){
      done = true;
      break;
    }

  }//end big while
  free(line);
  return 0;

}
