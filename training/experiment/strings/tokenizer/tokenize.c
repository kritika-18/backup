#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void tokenizer(char str[]){
  char *token=strtok(str," ");
  int count=0;
  while(token!=NULL){
      count++;
    printf("%s ",token);
    token=strtok(NULL," ");
    
  }
  printf("%d", count);
}

int main()
{
    char str[100];
    printf("Enter string: ");
   scanf("%[^\n]%*c",str);//takes complete input including spaces
    // gets(str);
    tokenizer(str);
    //printf("No of words: ",tokenizer(str));
    return 0;
}
