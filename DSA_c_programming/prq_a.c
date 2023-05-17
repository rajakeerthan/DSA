#include<stdio.h>
#include<stdlib.h>
#define max 15
int q[max];
int p[max];
int f=-1,r=-1;
void enqueue();
void dequeue();
void display();
int main(){
	int n;
	while(1){
		printf("\nenter 1.enqueu\n2.dequq\n3.display\n4.exit\n");
		scanf("%d",&n);
		switch(n){
			 case 1:enqueue();break;
			case 2:dequeue();break;
			case 3:display();break;
			case 4:exit(0);
		}
	}
return 0;
}
void enqueue(){
	int data,prior,i;
	printf("enter data and corresponding priority]n\n");
	scanf("%d",&data);
	scanf("%d",&prior);
	if(f==-1 && r==-1){
		f=0;	
		r=0;
		q[r]=data;
		p[r]=prior;
	}
	else{
		for(i=r;i>=f;i--){
			if(prior>p[i]){
				q[i+1]=q[i];
				p[i+1]=p[i];
			}	
			else
				break;
		}
		q[i+1]=data;
		p[i+1]=prior;
		r++;
	}
	
}
void dequeue(){
	if(f==-1)
		printf("overflow\n");
	else if(f==r){
		f=-1;
		r=-1;
	}
	else{
		f++;
	}
}
void display(){
	int i;
	for(i=f;i<=r;i++)
		printf("data=%d\t prior=%d\n",q[i],p[i]);	
}
