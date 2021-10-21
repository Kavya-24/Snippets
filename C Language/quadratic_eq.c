#include <stdio.h>
#include<math.h>
int main()
{
    int a,b,c,d,x,y,i;
    printf("enter the coefficients of the equation\n");
    scanf("%d,%d,%d",&a,&b,&c);
    d=(b*b)-(4*a*c);
    i=pow(d,1/2);
    if(d>0)
    {
        x=(-b+i)/(2*a);
        y=(-b-i)/(2*a);
        printf("the roots are %d and %d",x,y);
    }
    else if(d==0)
    {
        i=0;
        x=y=(i-b)/(2*a);
        printf("the roots are equal and equal to %d",x);
    }
    else
    {
        printf("the roots are imaginary");
    }
    return 0;
}



