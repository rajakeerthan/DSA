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
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("the sorted array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
return 0;
}
