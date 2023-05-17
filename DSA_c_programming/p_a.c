#include<stdio.h>
#include<stdlib.h>
#define max 20
int p[max];
int q[max];
int f=-1;
int r=-1;
void enq();
void display();
void deq();
int main(){
	int n;
	while(1){
		printf("\n1.push\n2.pop\n3.display\n4.exit\nenter  n value\n");
		scanf("%d",&n);
		switch(n){
			case 1:enq();break;
			case 2:deq();break;
			case 3:display();break;
			case 4:exit(0);
		}
	}
return 0;
}
void enq(){
	int data,prior,i;
	printf("enter data and prior\n");
	scanf("%d",&data);
	scanf("%d",&prior);
	if(f==-1){
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
void deq(){
	int n;
	if(f==-1){
		printf("underflow\n");	
	}
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
	for(i=f;i<=r;i++){	
		printf("data=%d\tprior=%d\n",q[i],p[i]);
	}
}


