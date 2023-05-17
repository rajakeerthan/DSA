import java.util.*;
class subseq{
	public static void main(String[] args){
		String s="abc";
		subseq ss=new subseq();
		
		ArrayList<String> k=new ArrayList<>();
		k=ss.Break("",s);
		System.out.println(k);
		
	}
	public ArrayList<String> Break(String res,String temp){
		if(temp.isEmpty()){
		//	System.out.println(res);
        ArrayList<String> k=new ArrayList<>();
       
			k.add(res);
			return k;	
		}
		char ch=temp.charAt(0);
        ArrayList<String> l = Break(res+ch,temp.substring(1));
        ArrayList<String> r = Break(res,temp.substring(1));
        l.addAll(r);
        return l;
	}
}