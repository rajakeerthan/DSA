#include<stdio.h>
#include<stdlib.h>

int vertexcount=0;
struct vertex{
	int data;
	struct vertex *next;
};
struct vertex *vert[10];
void null(){
	int i;
	for(i=0;i<10;i++){
		vert[i]=NULL;
	}
}
void add_vertex(){
	int n,v;
	struct vertex *nn;
	//printf("enter no.of vertexes you want to add\n");
	//scanf("%d",&n);
	//for(i=0;i<n;i++){
		nn=(struct vertex *)malloc(sizeof(struct vertex));
		printf("enter vertex\n");
		scanf("%d",&v);
		nn->data=v;
		nn->next=NULL;
		vert[vertexcount]=nn;
		vertexcount++;
	//}
}
void add_edge(){
	struct vertex *temp,*ptr;
	int i,m,k,j;
	for(i=0;i<vertexcount;i++){
	printf("enter no.of vertexes adjacent to %d",vert[i]->data);
	scanf("%d",&m);
		for(j=0;j<m;j++){
			printf("enter adjacent vertex\n");
			scanf("%d",&k);
			ptr=(struct vertex *)malloc(sizeof(struct vertex));
			ptr->data=k;
			ptr->next=NULL;
			temp=vert[i];
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=ptr;
		}
	}
}
void display(){
	int i;
	for(i=0;i<vertexcount;i++){
		struct vertex *temp;
		temp=vert[i];
		//printf("vertex-%d\t",vert[i]->a);
		while(temp!=NULL){
			printf("%d-->",temp->data);
			temp=temp->next;
		}
	}	printf("\n");
}
int main(){
	null();
	add_vertex();
	add_vertex();
	add_vertex();
	add_vertex();
	add_edge();
	display();
return 0;
}
