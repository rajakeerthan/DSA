#include<stdio.h>
#include<stdlib.h>
#define size 10
struct pair{
	int key;
	int value;
};
struct pair *hashtable[size];
void null(){
	int i;
	for(i=0;i<size;i++){
		hashtable[i]=NULL;
	}
}
int hashcode1(int m){
	return m%size;
}
int hashcode2(int m){
	return (7-(m%7));
}
void y(){
	int data,k,m,j;
	printf("number of elemnts you want to add in \n");
	scanf("%d",&m);
	for(j=0;j<m;j++){
		printf("enter new data\n");
		scanf("%d",&data);
		struct pair *nn;
		nn=(struct pair *)malloc(sizeof(struct pair));
		k=data%size;
		nn->value=k;
		nn->key=data;
		if(hashtable[k]==NULL){
			hashtable[k]=nn;
		}
		else{
			int z=k,l;
			int i=0;
			while(hashtable[k]!=NULL){
				l=hashcode2(k);
				k=(z+(l*i))%size;
				i++;
			}
			hashtable[k]=nn;
		}
	}
}
void search(){
	
	int i,search,m=0,temp;
	printf("enter element to search\n");
	scanf("%d",&search);
	
	for(i=0;i<size;i++){
		struct pair *temp;
		
		if(hashtable[i]==NULL){
			continue;
		}
		else if(hashtable[i]->key==search){
			printf(" element found at %d \n",i);
			m=1;
		}
	}
	if(m==0)
		printf("elemnt not found\n");
		
}
void m(){
	int i;
	for(i=0;i<size;i++){
		if(hashtable[i]==NULL){
			printf("key=_\tvalue=%d\n",i);
		}
		else{
			printf("key-%d\tvalue-%d\n",hashtable[i]->key,i);
		}
	}
}
int main(){
	null();
	int n;
	while(1){
		printf("choose\n,1.insert\n,2.display\n3.exit\n4.search\n");
		scanf("%d",&n);
		switch(n){
			case 1:y();break;
			case 2:m();break;
			case 3:exit(0);break;
			case 4:search();break;
		}
	}
return 0;
}
