#include <stdio.h>
#include <regex.h>
#include <string.h>
void tokenize(char c){
  switch(c){};

}
int parse(char* input){
  printf("now entering parsing stage...\n");
  printf("input was %s\n", input);
  int i;
  for (i = 0; i < strlen(input); i++ ){
  printf("%d char of input is %c\n", i, input[i]);
  tokenize(input[i]);

  }

  return 0;
}


