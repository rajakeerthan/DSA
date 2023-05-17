import java.util.*;
class merge{
	public static void main(String args[]){
		int a[]={5,4,3,2,1};
		merge m=new merge();
		System.out.println(Arrays.toString(a));

		int b[]=m.mergesort(a);
	System.out.println(Arrays.toString(b));
	}
	public int[] mergesort(int a[]){
		if(a.length==1)
			return a;
		int m=a.length/2;
		int l[]=mergesort(Arrays.copyOfRange(a,0,m));
		int r[]=mergesort(Arrays.copyOfRange(a,m,a.length));
		return merge(l,r);
	}
	public int[] merge(int l[],int r[]){
		int mix[]=new int[l.length+r.length];
		int i=0,j=0,k=0;
		while(i<l.length && j<r.length){
			if(l[i]<r[i]){
				mix[k]=l[i];
				i++;
			}
			else{
				mix[k]=r[j];
				j++;
			}
			k++;
		}	
		while(i<l.length){
			mix[k]=l[i];
				i++;
				k++;
		}
		while(j<r.length){
			mix[k]=l[j];
				j++;
				k++;
		}
		return mix;
	}
}