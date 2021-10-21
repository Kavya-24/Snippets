#include<stdio.h>
typedef struct
{
  float real;
  float imag;
}complex;

complex add(complex n1, complex n2)
{
  complex result;
  result.real=n1.real+n2.real;
  result.imag=n1.imag+n2.imag;

 return result;
}

int main()
{
 complex n1,n2,result;

  printf("For 1st complex number \n");
    printf("Enter the real and imaginary parts: ");
    scanf("%f %f", &n1.real, &n1.imag);
  printf("\nFor 2nd complex number \n");
    printf("Enter the real and imaginary parts: ");
    scanf("%f %f", &n2.real, &n2.imag);

    result=add(n1,n2);
    printf("sum=%0.1f+(%0.1f)i",result.real,result.imag);

    return 0;
} 