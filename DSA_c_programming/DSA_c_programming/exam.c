#include<stdio.h>
#include<stdlib.h>
#define size 10
void null();
void insert();
void display();
int hash1(int );
int hash2(int );
int main(){
	null();
	int n;
	while(1){
		printf("choose\n,1.insert\n,2.display\n3.exit\n4.search\n");
		scanf("%d",&n);
		switch(n){
			case 1:insert();break;
			case 2:display();break;
			case 3:exit(0);break;
			//case 4:();break;
		}
	}
return 0;
}
int hash1(int key){
	return key%size;
}
int hash2(int key){
	return (7-key)%7;
}
int hashtable[size];
void null(){
	int i ;
	for(i=0;i<size;i++){
		hashtable[i]=-1;
	}
}
void insert(){
	printf("enter element to insert\n");
	int k;
	scanf("%d",&k);
	int v=hash1(k);
	int l=hash2(k);
	if(hashtable[v]==-1){
		hashtable[v]=k;
	}
	else{
		int i=1,m;
		while(hashtable[m]!=-1){
			m=(v+i*l)%size;
		}
		hashtable[m]=k;
	}
}
/*void delete(){
} 
void search(){
}*/
void display(){
	int i;
	printf("keys--->values\n");
	for(i=0;i<size;i++){
		printf("%d--->%d\n",i,hashtable[i]);
	}
}
