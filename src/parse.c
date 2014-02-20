#include <stdio.h>
#include <string.h>

#include "../lib/hash.c"
#include "../lib/strmap.h"
/*
   StrMap *hash_table;
   char buf[255];
   int result;

   hash_table = sm_new(10);
   if (hash_table == NULL ){
   printf("Error allocating memory!\n")
   }


   int hash_input(char * input){
   uint32_t  h  = SuperFastHash(input, (int)strlen((input)));
   return (int) h;
   if (strcmp("bob", input) == 0){
   printf("%lu", strlen(input));
   return 0;
   } else {
   printf("%lu", strlen(input));
   return 1;
   }
   }

*/
void tokenize(char * input){


  printf("tokenized = %s\n", input);

}
int parse(){
  int i = 0;
  while (true){
    //printf("top of loop 2...\n");
    int input = getchar();
    if (isspace(input) || input == EOF) {
      word[i] = 0;
      break;
    }
    //printf("now parsing this char: %c\n", (char)input);
    word[i] = input;
    if (i == buffer_size - 1){
      buffer_size = buffer_size + buffer_size;
      //printf("*****************buffer expanded!***************\n");
      word = (char*) realloc(word, buffer_size);
      if (word == 0) quit();
    }
    i++;

  }
  printf("\nsending word %s to get parsed...\n", word);
  //printf("parsing...\n");
  parse(word);
  if (strcmp(word, "quit") == 0){
    done = true;
    break;
  }
  //printf("now entering parsing stage...\n");
  //  tokenize(hash_input(input));
  tokenize(input);

  return 0;
}
