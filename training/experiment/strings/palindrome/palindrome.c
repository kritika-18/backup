#include<stdio.h>
#include<stdbool.h>
#include<string.h>
void palindrome(char *str){
	int n=strlen(str);
	bool flag=false;
	for(int i=0;i<strlen(str)/2;i++){
		if(str[i]==str[n-1-i]) flag=true;
	}
	if(flag==true){printf("YES");}
	else printf("NO");
}

int main(){
	printf("enter a string: ");
	char str[20];
	scanf("%[^\n]%*c",str);
	palindrome(str);
	return 0;
}
