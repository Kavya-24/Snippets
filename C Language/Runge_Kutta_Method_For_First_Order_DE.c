/**************************************
*********RUNGE-KUTTA METHOD(1)*********
**************************************/
#include<stdio.h>
#include<math.h>
/*Define the RHS of the first order differential equation here(Ex: dy/dx=f(x,y))  */
double f(double x, double y){
    //return 2-exp(-4*x)-2*y;   
    //return x+y;
    return x;
}
main(){
    int i;
    double x,y,x0,y0,h,k1,k2;
    printf("Enter the initial condition for y: ");
    scanf("%lf",&y0);
    printf("Enter the initial condition for x: ");
    scanf("%lf",&x0);
    printf("Enter the value of x for which y is required: ");
    scanf("%lf",&x);
    printf("Enter the step-width h: ");
    scanf("%lf",&h);
    printf("x\t\ty\t\ty'\t\tk1\t\tk2\n");
    printf("__________________________________________________________________________\n");
    //Begin Runge-Kutta Routine
    while((x-x0)>0.0000000001){
        k1=h*f(x0,y0);
        k2=h*f(x0+h/2.0,y0+k1/2.0);
        y=y0+k2;
        printf("%lf\t%lf\t%lf\t%lf\t%lf\n",x0,y0,f(x0,y0),k1,k2);
        y0=y;
        x0=x0+h;
    }
    printf("%lf\t%lf\n",x0,y0);
    printf("__________________________________________________________________________\n");
    printf("The value of y is %lf\n\n",y);
}
