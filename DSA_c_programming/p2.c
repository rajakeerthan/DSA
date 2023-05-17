#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int a[MAX][MAX];
int visited[MAX];
/*void bfs(int adj[][max],int visited[],int start,int n){
	int queue[max],rear=-1,front=-1,i;
	queue[++rear]=start;
	visited[start]=1;
	while(rear!=front){
		start=queue[++front];
		if(start!=n){
			printf("%c\t",start+65);
			for(i=0;i<max;i++){		
				if(adj[start][i]==1 && visited[i]==0){
					queue[++rear]=i;
					visited[i]=1;
				}
			}
		}
	}
}*/
void bfs(int start,int n){
	int i,front=-1,rear=-1;
	int q[MAX];
	q[++rear]=start;
	visited[start]=1;
	while(rear!=front){
		start=q[++front];
		if(start!=n){	
			printf("%c",start+65);
			for(i=0;i<n;i++){
				if(a[start][i]==1 && visited[i]==0){
					q[++rear]=i;
					visited[i]=1;
				}
		
			}
		}
		
	}
}
int main(){
	int n,i,j,k;
	int m;
	printf("enter no.of vetices\n");
	scanf("%d",&n);
	printf("enter adjacency matrix corresponding to the graph\n");
	for(i=0;i<n;i++){
		visited[i]=0;
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("enter starting vertex number\n");
	scanf("%d",&m);
	//printf("%c",m+65-1);
	bfs(m-1,n);
return 0;
}
