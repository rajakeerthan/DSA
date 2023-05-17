import java.util.*;

class mountain_array{
    public static void main(String args[]){
        int i,n;
        int a[]=new int[20];
        System.out.println("enter no.of elements and elements in the mountain array");
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        for(i=0;i<n;i++){
            a[i]=sc.nextInt();
        }
        mountain_array b=new mountain_array();
       int k=b.bs(a,n);
       System.out.println("peak element is "+a[k]);
       
       
    }
    public int bs(int a[],int n){
        int mid;
        int s=0;
        int e=n-1;
        while(s<e){
            mid=(s+e)/2;
                if(a[mid]<a[mid+1])
                    s=mid+1;
                else    
                    e=mid-1;
        }
       return s;
    }
    
}