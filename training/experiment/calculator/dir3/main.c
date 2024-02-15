#include "add.c"
#include "sub.c"
#include "mul.c"
#include "div.c"
#include "mod.c"

#include "../dir2/hdr.h"


int main(){
	
	int opt;
	printf("enter the options: 1 for addition\n2 for subtraction\n3 for multiplication\n4 for division\n5 modulus\n Enter 0 to exit\n"); 
	scanf("%d",&opt);

	if(opt ==0) exit(0);

	int a,b;
	printf("Enter nos: ");
	scanf("%d",&a);
       scanf("%d",&b);

	switch(opt){
		
		 case 1:
                        printf("%d",add(a,b));
                        break;
                case 2:
                        printf("%d",sub(a,b));
                        break;
		case 3:
                        printf("%d",mul(a,b));
                        break;
                case 4:
                        printf("%d",dv(a,b));
                        break;
		case 5:
                        printf("%d",mod(a,b));
                        break;
               

		default:
		printf("Invalid option");
		}
		return 0;
		}

