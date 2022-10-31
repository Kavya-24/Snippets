#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,a[100],count=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0; i<n; i++)
    {
        if(i+1==n-1 || i+2==n-1)
        {
            count++;
            break;
        }
        else if(a[i+2]==0)
        {
            i++;
            count++;
        }
        else if(a[i+1]==0)
        {
            count++;
        }
    }
    printf("%d",count);
    return 0;
}

