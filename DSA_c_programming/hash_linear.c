#include<stdio.h>
#include<stdlib.h>
int size=10;

/*struct pair *head=NULL;*/
int hashtable[10];
int hashfunction(int key){
	return key%size;
}
void null(){
	int i;
	for(i=0;i<size;i++)
		hashtable[i]=-1;
}
int search(int k,int s){
	int m=0;
	if(hashtable[k]==s){
		printf("elemnt found\n");
		m=1;
		return k;}
	else
		search(k++,s);
	if(m==0){
		printf("elemnt not found\n");
	}
}
void delete(){
	int s,k,j;
	printf("enter elemnt to delete\n");
	scanf("%d",&s);
	k=s%size;
	j=search(k,s);

		hashtable[j]=-1;
		printf("elemnt deleted succefully\n");
	
}
void insert(){
	int x,key,value,i,m=0;
	printf("enter new key to be stored\n");
	scanf("%d",&x);
	i=hashfunction(x);
	value=i;
	key=x;
	if(hashtable[value]==-1)
		hashtable[value]=key;
	else{
		int k,j;
		k=value;
		j=0;
		while(hashtable[k]!=-1){
			k=(value+j)%size;j++;
		}
		hashtable[k]=key;
	}
	//if(m==0)
	//	printf("%d is already filled\n",value);
}
void print(){
	int i;
	printf("value\t keys\n");	
	for(i=0;i<size;i++){
		if(hashtable[i]==-1)
			printf("%d\t noelement\n",i);
		else{
			printf("%d\t%d\n",i,hashtable[i]);
		}
	}
}
int main(){
	null();
	int n,s,k;
	while(1){
		printf("choose\n1.insert\n2.print\n3.exit\n4.search\n5.delete\n");
		scanf("%d",&n);
		switch(n){
			case 1:insert();break;
			case 2:print();break;
			case 3:exit(0);break;
			case 4:
			printf("enter elemnt to earch\n");
			scanf("%d",&s);
				k=s%size;
				search(k,s);break;
			case 5:delete();break;
		}
	}
return 0;
}
