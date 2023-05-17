import java.util.*;
class permut{
    public static void main(String args[]){
        String s="abc";
        permut p=new permut();
        p.sol("",s);
    }
    public void sol(String res,String temp){
        if(temp.isEmpty()){
            System.out.println(res);
            return ;
        }
        char ch=temp.charAt(0);
        for(int i=0;i<=res.length();i++){
            String f=res.substring(0,i);
            String g=res.substring(i,res.length());
            sol(f+ch+g,temp.substring(1));
        }
    }
}