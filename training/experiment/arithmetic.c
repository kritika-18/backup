#include<stdio.h>
int add(int,int);
int sub(int,int);
int mul(int,int);


int add(int a,int b){
	return a+b;
}

int sub(int a,int b){
	return a-b;
}

int mul(int a,int b){
	return a*b;
}

int main(){
	int a,int b;
	printf("Enter the numbers to be added: ");
	scanf("%d %d",&a,&b);
	int res1=add(a,b);

	printf("Enter the numbers to be subtracted: ");
	scanf("%d %d",&a,&b);
	int res2=sub(a,b);

	printf("Enter the numbers to be multiplied: ");
	scanf("%d %d",&a,&b);
	int res3=mul(a,b);

	printf("%d\n%d\n%d",res1,res2,res3);
	return 0;
}
