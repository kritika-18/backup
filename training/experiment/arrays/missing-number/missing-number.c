#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int res=0;
    int sum_n=n*(n+1)/2;
    res=sum_n-sum;
    if(res==0) printf("Missing number is 0");
    else{
        printf("Missing number: %d",res);
    }
    

    return 0;
}
