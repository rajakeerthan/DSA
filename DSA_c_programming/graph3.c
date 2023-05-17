#include<stdio.h>
#include<stdlib.h>
#define size 10
struct vertex{
	int vert;
	struct vertex *next;
};
struct vertex *array[size];
void print(){
	int i;
	for(i=0;i<size;i++){
		struct vertex *temp;
		temp=array[i];
		printf("key-%d\t",i);
		while(temp!=NULL){
			printf("%d\t",temp->vert);
			temp=temp->next;
		}
		printf("NULL\n");
	}
	exit(0);
}
void graph(){
	struct vertex *temp;
	int n,vertice,e,x,adj,i,j;
	print("enter no.of vertices in the graph\n");
	scanf("%d",&n);
	printf("enter %d vertices \n",n);
	for(i=0;i<n;i++){
		scanf("%d",&vertice);
		array[i]->vert=vertice;
		array[i]->next=NULL;
	}
	for(i=0;i<n;i++){
		printf("enter no.of edges to %d",array[i]->vert);
		scanf("%d",&e);
		for(j=0;j<e;j++){
			printf("enter %d th  vertices that connected to %d\n",j+1,array[i]->vert);
			scanf("%d",&adj);
			struct vertex *nv;
			nv=(struct vertex *)malloc(sizeof(struct vertex));
			nv->vert=adj;
			nv->next=NULL;	
			if(array[i]->next==NULL)
					array[i]->next=nv;
			else
				
				temp=array[i];
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=nv;
		}
	}
}
/*void null(){
	int i;
	for(i=0;i<size;i++){
		array[i]=NULL;
	}
}*/
int main(){
	//null();
	graph();
	print();
return 0;
}

