#include<math.h>
#include<stdio.h>
int main()
{
    int a,n=1,i,c,sum=0;
    printf("enter an integer\n");
    scanf("%d",&a);
    c=a;
    for(i=1;a/10>0;i=i+1)
    {
        a=a/10;
        n=n+1;
    }
    a=c;
    for(i=n;i>0;i=i-1)
    {
        sum=sum+pow((a%10),3);
        a=a/10;
    }
    if(sum==c)
    {
        printf("armstrong number");
    }
    else
    {
        printf("not an armstrong number");
    }
}

