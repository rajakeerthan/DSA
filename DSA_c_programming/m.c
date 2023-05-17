#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *a[10];
void display_list(int );
void display_matrix(int );
int b[10][10];
int main(){
	int i,j,n;
	printf("enter no.of elements in the graph\n");
	scanf("%d",&n);
	printf("enter adjacency matrix \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(b[i][j]==1){
				struct node *temp=a[i],*nn;
				nn=(struct node *)malloc(sizeof(struct node));
				nn->data=j+65;
				if(a[i]==NULL)
					a[i]=nn;
				else{
					nn->next=a[i];
					a[i]=nn;
				}
			}		
		}
	}
	display_matrix(n);
	display_list(n);
return 0;
}
void display_matrix(int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
}
void display_list(int n){
	int i;
	for(i=0;i<n;i++){
		struct node *temp=a[i];
		printf("%d-->",i+1);
		while(temp!=NULL){
			printf("%c",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
