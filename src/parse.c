#include <stdio.h>
#include <string.h>

#include "../lib/strmap.h"

int hash_input(char * input){
  if (strcmp("bob", input) == 0){
    return 0;
  } else {
    return 1;
  }
}

void tokenize(int hashed_input){

  switch(hashed_input){
    case 0:
      printf("bob was here!\n");
      break;
    default:
      printf("bob was not here!\n");
      break;
  }

}
int parse(char* input){
  //printf("now entering parsing stage...\n");
  tokenize(hash_input(input));
  return 0;
}
