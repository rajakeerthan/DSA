#include<stdio.h>
int main()
{
	int i,j,n,temp,a[25];
	printf("enetr no.of elemnts in array\n");
	scanf("%d",&n);
	printf("enetr elements in array\n");	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		j=i;
		while(j>0 && a[j-1]>a[j])
		{
			temp=a[j];
			a[j]=a[j-1];
			a[j-1]=temp;
			j--;
		}
	}
	printf("the sorted array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
return 0;
}
