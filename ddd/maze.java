import java.util.*;
class maze{
    public static void main(String[] args){
        int g=3;
        maze m=new maze();
        System.out.println("no.of ways"+m.count(3,3,""));
    }
    public int count(int r,int c,String s1){
        if(r==1 && c==1){
            System.out.println(s1);
            return 1;
        }
        int l=0,ri=0;
        if(r>1)
             l=count(r-1,c,s1+"r");
        if(c>1)
             ri=count(r,c-1,s1+"d");
        return l+ri;
    }
}