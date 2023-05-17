import java.util.*;
//diagonal move to and with obstacles
class mazeo{
    public static void main(String[] args){
        int g=3;
        mazeo m=new mazeo();
        boolean b[][]={{true,true,true},{true,false,true},{true,true,true}};
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
        if(r<b.length-1 && c<b[0].length-1 )
                 count(b,r+1,c+1,s1+"v");
        if(r<b.length-1)
                count(b,r+1,c,s1+"d");
        if(c<b[0].length-1)
                count(b,r,c+1,s1+"r");
    }
}