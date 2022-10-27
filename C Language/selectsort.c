#include<stdio.h>
void main()
{
	int n,i,t,j,a[20];
	printf("Enter size:");
	scanf("%d",&n);
	printf("\nEnter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		t=a[i];
		int p=i;
		for(j=i;j<n;j++)
		{
			 if(a[j]<t)
			 {
				t=a[j];
				p=j;
			)
		}
	}
	a[p]=a[i];
	a[i]=t;
	}
	printf("\nArray after sorting:");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
}
