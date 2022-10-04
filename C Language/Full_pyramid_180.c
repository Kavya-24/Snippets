//28.  W.A.P to print the following pattern, input is number of line.
// * * * * *
//  * * * *
//   * * * 
//    * *
//     *
#include <stdio.h>
int main()
{
    int num, row, clm, space;
    printf("How many lines :  ");
    scanf("%d", &num);
    printf("\n");

    for (row = num; row >= 1; --row)
    {
        for (space = 0; space < num - row; ++space)
            printf("  ");
        for (clm=row;clm <= 2*row-1; ++clm)
            printf("* ");
        for (clm = 0; clm < row - 1; ++clm)
            printf("* ");
        printf("\n");
    }
    
return 0;
}
