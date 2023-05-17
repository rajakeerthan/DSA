import java.util.*;

class infinite_bs{
    public static void main(String args[]){
        int i,n;
        int a[]=new int[20];
        System.out.println("enter no.of elements and elements in the array");
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        for(i=0;i<n;i++){
            a[i]=sc.nextInt();
        }
        infinite_bs b=new infinite_bs();
        System.out.println("enter element to search");  
        int s=sc.nextInt();
        if(s>a[n-1]){
            System.out.println("cannot found");
            return ;
        }
       int k=b.bs(a,s,n);
       System.out.println("element is at"+k);
       
    }
    public int bs(int a[],int t,int n){
        int mid;
        int s=0;
        int e=1;
        while(s<=e){
            if(a[e]<t){
                int y=(e-s);
                s=e;
                e=s+y*2;
                if(e>n-1)
                    e=n-1;
                continue;
            }
            mid=(s+e)/2;
                if(a[mid]==t){
                    return mid;
                }
                else if(a[mid]<t){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
        }
       return s;
    }
    
}