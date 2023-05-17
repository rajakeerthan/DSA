import java.util.*;
class phn{
    public static void main(String args[]){
        String s="12";
        phn p=new phn();
        p.sol("",s);
    }
    public void sol(String res,String temp){
        if(temp.isEmpty()){
            System.out.println(res);
            return ;
        }
        char ch=temp.charAt(0);
        int d=ch-'0';
        System.out.println("char=="+d);
        for(int i=(d-1)*3;i<d*3;i++){
         //   String f=res.substring(0,i);
           // String g=res.substring(i,res.length());
           char ch1=(char)('a'+i);
            sol(res+ch1,temp.substring(1));
        }
    }
} 