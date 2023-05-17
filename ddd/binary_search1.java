import java.util.*;
class binary_search1{
    public static void main(String args[]){
        int i,n;
        int a[]=new int[20];
        System.out.println("enter no.of elements and elements in the array");
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        for(i=0;i<n;i++){
            a[i]=sc.nextInt();
        }
        binary_search1 b=new binary_search1();
        System.out.println("enter element to search");
        int s=sc.nextInt();
       int k=b.bs(a,n,s);
       /*if(k==-1){
            System.out.println("element not found");
       }
        else{
       System.out.println("element found at "+k);
        }*/
        System.out.println("element found at "+k);
    }
    public int bs(int a[],int n,int t){
        int mid=0;
        int s=0;
        int e=n-1;
        while(s<=e){
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