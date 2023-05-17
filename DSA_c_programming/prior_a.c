#include<stdio.h>
#define max 10;
int q[20];
int p[20];
int f=-1;
int r=-1;
int main(){
	int n;
	while(1){
		printf("choose\n1.enq\n2.deq\n3.exit\n4.display\n");
		scanf("%d",&n);
		switch(n){
			case 1:enq();break;
			case 2:deq();break;	
			case 4:display(front);break;
			case 3:exit(0);
		}
	}
return 0;
}
void enq(){
	int data,prior,i;
		printf("enter data and priority\n");
		scanf("%d",&data);
		scanf("%d",&prior);
	if(f==-1){
		f=0;
		r=0;
		q[r]=data;
		p[r]=prior;
	}
	else{
		for(i=r;i<=f;i--){
			if(p[i]<=prior){
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
	if(f==-1){
		printf("empty\n");
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

