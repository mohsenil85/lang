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
  printf("welcome to the repl\n^C to end\n");
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
        word[i] = 0;
        break;
      }
      //printf("now parsing this char:  %c\n", (char)input);
      word[i] = input;
      if (i == buffer_size - 1){
        buffer_size = buffer_size + buffer_size;
        //printf("*****************buffer expanded!***************\n");
        word = (char*) realloc(word, buffer_size);
        if (word == 0) quit();
      }
      i++;
      
    }
    printf("sending word %s to get parsed...\n", word);
    //printf("parsing...\n");
    parse(word);
/*
    if (strcmp(word, "quit") == 0){
      done = true;
      break;
    }

*/
  }//end big while
  free(word);
  return 0;

}

