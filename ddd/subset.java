import java.util.*;
class subset{
	public static void main(String[] args){
		String s="abc";
		subset ss=new subset();
		
		ArrayList<String> k=new ArrayList<>();
		ss.Break("",s,k);
		System.out.println(k);
		
	}
	public void Break(String res,String temp,ArrayList<String> k){
		if(temp.isEmpty()){
		//	System.out.println(res);
			k.add(res);
			return;	
		}
		char ch=temp.charAt(0);
		Break(res+ch,temp.substring(1),k);
		Break(res,temp.substring(1),k);
	}
}