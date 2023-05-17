import java.util.*;
//up down left and right
class maze_way{
    public static void main(String[] args){
        int g=3;
        maze_way m=new maze_way();
        int b[][]={{0,0,0},{0,0,0},{0,0,0}};
        int p[][]={{0,0,0},{0,0,0},{0,0,0}};
       // System.out.println("no.of ways"+m.count(b,0,0,""));
       m.count(b,0,0,"",p,0);
    }
    public void count(int b[][],int r,int c,String s1,int path[][],int step){
        if(r==b.length-1 && c==b[0].length-1){
           // System.out.println(s1);
           path[r][c]=step;
           System.out.println();
           for(int i[] : path){
                for(int j : i){
                    System.out.print(j);
                }
                System.out.println();
           }
            return ;
        }
        if(b[r][c]==1)
            return ;
        
       b[r][c]=1;
       path[r][c]=step;
        if(r<b.length-1)
                count(b,r+1,c,s1+"d",path,step+1);
        if(c<b[0].length-1)
                count(b,r,c+1,s1+"r",path,step+1);
        if(r>0)
            count(b,r-1,c,s1+"u",path,step+1);
        if(c>0)
            count(b,r,c-1,s1+"l",path,step+1);
        b[r][c]=0;
        path[r][c]=0;
    }
}