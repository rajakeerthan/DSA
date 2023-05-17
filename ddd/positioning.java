import java.util.*;
class positioning{
    public static void main(String args[]){
        int k;
        int i,n;
        char a[]=new char[20];
        System.out.println("enter no.of elements and elements in the array");
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        for(i=0;i<n;i++){
            a[i]=sc.next().charAt(0);
        }
        char_ceiling b=new char_ceiling();
        System.out.println("enter element to search");  
        char s=sc.next().charAt(0);
        int z[]=new int[20];
        try{
            List<Integer> r=new ArrayList<Integer>();
            positioning p=new positioning();
            r=p.returning(a,n,s);
            System.out.println(r);
            int l=0;
            for(int i : r){
                z[l]=i;
                l++;
            }
        }
        catch(Exception e){
            
        System.out.println(e);
        }
        for(int i : r){
            
    }
    public List<Integer> returning(char a[],int n,char t){
        List<Integer> r=new ArrayList<Integer>();  
           
        int mid;
        int s=0;
        int e=n-1;
        int one=-1,two=-1;
        while(s<=e){
            mid=(s+e)/2;
                if(a[mid]==t){
                    one=mid;
                    e=mid-1;
                }
                else if(a[mid]<t){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
        }
        s=0;
        e=n-1;
        while(s<=e){
            mid=(s+e)/2;
                if(a[mid]==t){
                    two=mid;
                    s=mid+1;
                }
                else if(a[mid]<t){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
        }
        r.add(one);
        r.add(two);
       return r;
    }
}