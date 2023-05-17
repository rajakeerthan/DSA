import java.util.*;
class three{
	public static void main(String args[]){
		three o=new three();
		int i;
		int a[]=new int[10];
		for(i=0;i<10;i++){
			a[i]=10-i;
		}
		o.start(10,0,a,0);
		for( i=0;i<10;i++)
			System.out.print(a[i]+"  ");
	}
	public void start(int i,int j,int a[],int max){
		if(i==0)
			return ;
		if(j<i){
			if(a[j]<a[max])
				start(i,j+1,a,max);
			else
				start(i,j+1,a,j);
		}
		else{
				int t=a[i-1];
				a[i-1]=a[max];
				a[max]=t;
			start(i-1,0,a,0);
		}
	}
}
