import java.util.*;

class rotated_array{
    public static void main(String args[]){
        int i,n;
        int a[]=new int[50];
        System.out.println("enter no.of elements and elements in the rotated array");
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        for(i=0;i<n;i++){
            a[i]=sc.nextInt();
        }
        rotated_array b=new rotated_array();
       int k=b.pivot(a,n);
       if(k!=-1)
            System.out.println("peak element is "+a[k]);
            System.out.println("enter element to search");
            int s=sc.nextInt();
       int l=b.bs(a,n,s,0,k);
       if(l==-1){
        l=b.bs(a,n,s,k+1,n-1);
       
   }
   if(l==-1){
    System.out.println("element not found");
    }
    else{
        System.out.println("element found at"+l);
    }
}
int bs(int a[],int n,int t,int s,int e){
    while(s<=e){
   int  mid=(s+e)/2;
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
return -1;
}
       
    
    public int pivot(int a[],int n){
        int mid;
        int s=0;
        int e=n-1;
        while(s<=e){
            mid=(s+e)/2;
                if(a[mid]>a[mid+1])
                        return mid;
                else if(a[mid]>=a[s])
                    s=mid+1;
                else    
                    e=mid-1;
        }
       return -1;
    }
    
}