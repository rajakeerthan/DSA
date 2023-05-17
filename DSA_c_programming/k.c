#include<stdio.h>
#include<stdlib.h>
#define max 10
int main(){
	int n,a[max][max],i,j,visited[max];
	printf("enter n\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		visited[i]=0;
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	bfs(a,visited,0,n);
}
bfs(int b[][max],int v[],int st,int n){
	int q[max],f=-1,r=-1,i;
	q[++r]=st;
	v[st]=1;
	while(r!=f){
		st=q[++f];
		if(st!=n){
			printf("%c",st+65);
			for(i=0;i<n;i++){
				if(b[st][i]==1 && v[i]==0){
					v[i]=1;
					q[++r]=i;
				}
			}
		}
	}

	
}
