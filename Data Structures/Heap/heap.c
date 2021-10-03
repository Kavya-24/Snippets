#include<stdio.h>
#include<time.h>

int main(){
	int k,r,heapsize,n,comp;
	int arr[50];
	clock_t start,stop;
    double timetaken; 
	printf("How many nodes are there:");
	scanf("%d", &n);
	start=clock();
	{
		for(k=0;k<n;k++){
		printf("Enter the value:");
		scanf("%d", &arr[k]);
	}
}
    stop=clock();
	heapsize=n-1;
	heapsort(arr, heapsize);
    
	for(k=0;k<n;k++){
		printf("%d\n", arr[k]);
		comp++;
	}
	printf("\n No of comparisions  = %d",comp);
	timetaken=((double)(stop-start))/CLOCKS_PER_SEC;
    printf("time efficiency is %f",timetaken);
	
	return 0;
}

void heapsort(int arr[], int heapsize)
{
	int j, temp, comp=0;
	build_max_heap(arr, heapsize);
	for(j=heapsize;j>0;j--)
	{
		temp=arr[j];
		arr[j]=arr[0];
		arr[0]=temp;
		heapsize--;
		max_heapify(arr,0,heapsize);
		comp++;
	}
}

void build_max_heap(int arr[], int heapsize)
{
	int i;
	for(i=heapsize/2;i>=0;i--){
		max_heapify(arr,i,heapsize);
	}
}

max_heapify(int arr[],int m,int heapsize){
	int temp, largest;
	int l=(2*m)+1;
	int r=(2*m)+2;
	if((l<=heapsize) && (arr[l]>arr[m]))
	   largest=l;
	else
	   largest=m;
	if((r<=heapsize) && (arr[r]>arr[largest]))
	largest=r;
	if(largest!=m)
	{
		temp=arr[m];
		arr[m]=arr[largest];
		arr[largest]=temp;
		max_heapify(arr, largest, heapsize);
	}
}
