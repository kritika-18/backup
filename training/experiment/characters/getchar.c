#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int main(){
	int ch;
//	ch=getchar();
	//printf("%c",ch);
	//printf("%d",ch);

//	putchar(ch);
	char array[SIZE];	
//	while((ch=getchar())!=-EOF){
		//ch=getchar();
//		putchar(ch);
//		array[i++}=ch;
//	}

	for(int i=0;(ch=getchar())!=EOF;i++){
		array[i]=ch;
		//putchar(array[i]);
	}
	puts(array);

	return 0;
}
