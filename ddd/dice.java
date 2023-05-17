import java.util.*;
class dice{
    public static void main(String args[]){
        dice d=new dice();
        d.check("",4);
        System.out.println("count=="+d.check_count("",4));
    }
    public void check(String res,int t){
        if(t==0){
            System.out.println(res);
            return ;
        }
        for(int i=1;i<=6 && i<=t;i++ ){
            check(res+i,t-i);
        }

    }
    public int check_count(String res,int t){
        int count=0;

        if(t==0){
           // System.out.println(res);
            return 1;
        }
        for(int i=1;i<=6 && i<=t;i++ ){
            count=count+check_count(res+i,t-i);
        }
        return count;

    }
}