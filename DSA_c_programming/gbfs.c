#include<stdio.h>
#include<stdlib.h>
void dequeue();
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1,b[10];
void bfs(int v){
	for(i=0;i<n;i++){
		
		if(a[v-1][i] && !visited[i]){
			visited[i]=1;
			q[++r]=i+1;
		}
	}	
			if(f<=r){
				printf("%d",q[f]);
				bfs(q[f++]);	
			}
}
void main(){
	int v;
	printf("enter no.of vertices\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		q[i]=0;
		visited[i]=0;
	}
	printf("enter vertices\n");
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	printf("enter graph data in matrix form i.e 1 if edge o elsewhere\n");
	for(i=0;i<n;i++){	
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	//printf("enter starting vetrex:\n");
	//scanf("%d",&v);
	bfs(b[0]);
	printf("nodes\n");
	//if(visited[i])
		//printf("%d",i);
}

