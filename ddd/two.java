import java.util.*;
class two{
	public static void main(String args[]){
		two o=new two();
		int i;
		int a[]=new int[10];
		for(i=0;i<10;i++){
			a[i]=10-i;
		}
		o.start(9,0,a);
		for( i=0;i<5;i++)
			System.out.print(a[i]+"  ");
	}
	public void start(int i,int j,int a[]){
		if(i==0)
			return ;
		if(j<i){
			if(a[j]>a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
			start(i,j+1,a);
		}
		else{
			
			start(i-1,0,a);
		}
	}
}
