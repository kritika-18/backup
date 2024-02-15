#include<stdio.h>
#include "file1.c"
#include "file2.c"

//auto int a;
static int b;
extern int c;
extern int d;
int func3(int,int);

int func3(int a,int b){
	return a%b;
}

int main(){
	auto int a;
	int b;
	int c;
	int d;
	printf("Enter all the values: ");
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);

	int res1=func1(a,d);
	printf("\nFunction1 executed(sum): %d",res1);
	int res2=func2(a,d);
        printf("\nFunction2 executed(diff): %d",res2);
	int res3=func3(a,b);
        printf("\nFunction3 executed(mod): %d",res3);
	int res4=func4(a,c);
        printf("\nFunction4 executed(mul): %d",res4);
	int res5=func5(a,c);
        printf("\nFunction5 executed(div): %d",res5);





	return 0;
}
