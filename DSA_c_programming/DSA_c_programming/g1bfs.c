#include<stdio.h>
#include<stdlib.h>
#define max 10
int v[max]={0};
int a[max][max];
void bfs(int ad[][max],int v[],int start,int n){
	int front=-1,rear=-1,q[max],i;
	q[++rear]=start;
	v[start]=1;
	while(rear>front){
		start=q[++front];
		if(start!=n){
			printf("%c\t",start+65);
			for(i=0;i<n;i++){
			
				if(ad[start][i]==1 && v[i]==0){
					q[++rear]=i;
					v[i]=1;
				}	
			}
		}
	}
}
/*void bfs(int adj[][max],int visited[],int start,int n){
	int queue[max],rear=-1,front=-1,i;
	queue[++rear]=start;
	visited[start]=1;
	while(rear>front){
		start=queue[++front];
		if(start!=n){
			printf("%c\t",start+65);
			for(i=0;i<n;i++){		
				if(adj[start][i]==1 && visited[i]==0){
					queue[++rear]=i;
					visited[i]=1;
				}
			}
		}
	}
}*/
int main(){
	int n,i,j;
	printf("enter no.of vertices\n");
	scanf("%d",&n);
	printf("enter adjacency matrix of corresponding graph\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("enter element of %d row %d coloumn \n",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	bfs(a,v,0,n);
return 0;
}
