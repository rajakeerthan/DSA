import java.util.*;
//up down left and right
class mazeu{
    public static void main(String[] args){
        int g=3;
        mazeu m=new mazeu();
        boolean b[][]={{true,true,true},{true,true,true},{true,true,true}};
       // System.out.println("no.of ways"+m.count(b,0,0,""));
       m.count(b,0,0,"");
    }
    public void count(boolean b[][],int r,int c,String s1){
        if(r==b.length-1 && c==b[0].length-1){
            System.out.println(s1);
            return ;
        }
        if(!b[r][c])
            return ;
        
       b[r][c]=false;
        if(r<b.length-1)
                count(b,r+1,c,s1+"d");
        if(c<b[0].length-1)
                count(b,r,c+1,s1+"r");
        if(r>0)
            count(b,r-1,c,s1+"u");
        if(c>0)
            count(b,r,c-1,s1+"l");
        b[r][c]=true;
    }
}