#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int find_is(char str[]){
    int n=strlen(str);
    for(int i=0;i<n;i++){
        if(str[i]=='i'&&str[i+1]=='s') return i;
    }
    return -1;
}

int find_a(char str[]){
    int n=strlen(str);
    for(int i=0;i<n;i++){
        if(str[i]=='a') return i;
    }

    return -1;
}

int main()
{
    char str[100];
    printf("Enter string: ");
    scanf("%[^\n]%*c",str);
    if(find_a(str)>=0 && find_is(str)>=0) {
        printf("index of is: %d",find_is(str));
        printf("\nindex of a: %d",find_a(str));
        
    }
    else{
        printf("-1");
    }
    return 0;
}
