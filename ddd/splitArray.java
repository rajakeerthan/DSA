import java.util.*;
class splitArray{
    public static void main(String args[]){
        int a[]=new int[20];
        int i;
       // a=[7,2,5,8,10];
       Scanner sc=new Scanner(System.in);
        for(i=0;i<5;i++){
            a[i]=sc.nextInt();
        }
        splitArray s=new splitArray();
        System.out.println(s.split(a,2));
    }
    int split(int[] nums, int k) {
       int start=0;//min answer that we can get
       int end=0;//max number that we may get
       //int i;
       for(int i=0;i<nums.length;i++){
            start=Math.max(start,nums[i]);
            end=end+nums[i];
       }
       int mid;
       while(start<end){
            mid=start+(end-start)/2;
            int sum=0;
            int pieces=1;
            for(int num : nums){
                if(sum+num>mid){
                    sum=num;
                    pieces++;
                }
                else{
                        sum=sum+num;
                }
            }
            if(pieces>k){
                start=mid+1;
            }
            else{
                end=mid;
            }

       }
       return end;//start=end=mid
    }
}