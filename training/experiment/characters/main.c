#include<stdio.h>


int isAlphabet(char ch){
	
	if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
		return 1;
	return 0;
}

int isDigit(char ch){
	if(ch>='0'&& ch<='9')
		return 1;
	return 0;
}

int isSpecial(char ch){
	if((ch>=33 && ch<=47) || (ch>=58 && ch<=64)){
		return 1;
	}
	return 0;
}

void check_char(char ch){
	if(isAlphabet(ch)==1) printf("Alphabet");
	else if(isDigit(ch)==1) printf("number");
	else if(isSpecial(ch)==1) printf("Special key");
}

int main(){
	char ch;
	scanf("%c",&ch);
	check_char(ch);
	return 0;
}

