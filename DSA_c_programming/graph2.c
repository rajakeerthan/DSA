#include<stdio.h>
#include<stdlib.h>
#define k 10
int a[10][10];
int vertexcount=0;
struct vertex{
	int lable;
	int visited;
};
void null(){
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			a[i][j]=0;
		}
	}
}
void print_matrix(){
	int i,j;
	for(i=0;i<vertexcount;i++){
		printf("%d\t",i+1);
		for(j=0;j<vertexcount;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
struct vertex *listofvertices[k];
void add_vertex(int lable){
	struct vertex *vertex=(struct vertex *)malloc(sizeof(struct vertex));
	vertex->lable=lable;
	vertex->visited=-1;
	listofvertices[vertexcount++]=vertex;
}
/*void print_vertices(){
	int i;
	for(i=0;i<vertexcount;i++){
		printf("%c",listofvertices[i]->lable);
	}
}*/
void add_edge(int i,int j){
	a[i-1][j-1]=1;
	a[j-1][i-1]=1;
}
int main(){
	null();
	int n,i=0,l,o,x,j=0;
	int m;
	printf("enter number of vertices\n");
	scanf("%d",&n);
	printf("enter vertices\n");
	while(i<n){
		scanf("%d",&m);
		add_vertex(m);
		i++;
	}
	//printf("the vertices are=");
	//print_vertices();
	printf("enter number of edges u want to add\n");
	scanf("%d",&x);
	for(j=0;j<x;j++){
		printf("enter edge between which node and which node like 1st and 2nd or 2nd and 4...so on\n");
		scanf("%d %d",&l,&o);
		add_edge(l,o);
	}
	print_matrix();
return 0;
}
