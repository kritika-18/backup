#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insert(char *main, char *sub, int loc){
    int n=strlen(main);
    int m=strlen(sub);
    char temp[n+m];
    
   
    strncpy(temp,main,loc);
    
    int i=0;
    for(int j=loc;sub[i]!='\0';j++){
        temp[j]=sub[i];
        i++;
    }
    
    i=loc;
    for(int j=loc+m;main[i]!='\0';j++){
        temp[j]=main[i];
        i++;
    }
    
    printf("\nFinal string: %s",temp);
}

int main(){
    char main[100];
    char sub[100];
    printf("Enter main string: ");
    scanf("%[^\n]%*c",main);
    
    printf("\nEnter sub string: ");
    scanf("%[^\n]%*c",sub);
    
    int loc;
    printf("\nEnter the location: ");
    scanf("%d",&loc);
    
    insert(main,sub,loc);
	return 0;
}


