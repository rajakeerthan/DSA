import java.util.*;
class ceiling{
    public static void main(String args[]){
        int i,n;
        int a[]=new int[20];
        System.out.println("enter no.of elements and elements in the array");
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        for(i=0;i<n;i++){
            a[i]=sc.nextInt();
        }
        ceiling b=new ceiling();
        System.out.println("enter element to search");  

        float s=sc.nextFloat();
        if(s>a[n-1]){
            System.out.println("ceiling not found");
            return ;
        }
       int k=b.bs(a,n,s);
       
            System.out.println("celing is"+a[k]);
       
    }
    public int bs(int a[],int n,float t){
        int mid;
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