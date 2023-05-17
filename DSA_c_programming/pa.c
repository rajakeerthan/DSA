#include<stdio.h>
#include<stdlib.h>
int p[20];
int q[20];
int f=-1;
int r=-1;
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
	int data,pr,i;
	printf("enter data and prior\n");
	scanf("%d",&data);
	scanf("%d",&pr);
	if(f==-1){
		f=0;
		r=0;
		q[r]=data;
		p[r]=pr;
	}
	else{
		for(i=r;i>=f;i--){
			if(pr>p[i]){
				q[i+1]=q[i];
				p[i+1]=p[i];
			}
			else  
				break;
		}
		q[i+1]=data;
		p[i+1]=pr;
		r++;
		
	}
}
void deq(){
	if(f==-1)
		printf("underflow\n");
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
