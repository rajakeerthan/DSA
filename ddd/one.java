import java.util.*;
class one{
	public static void main(String args[]){
		one o=new one();
		o.start(5,0);
	}
	public void start(int i,int j){
		if(i==0)
			return ;
		if(j<i){
			System.out.print("* ");
			start(i,j+1);
		}
		else{
			System.out.println();
			start(i-1,0);
		}
	}
}
