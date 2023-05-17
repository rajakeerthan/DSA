import java.util.*;
class subseq2{
	public static void main(String[] args){
	
		subseq2 ss=new subseq2();
		int a[]={1,2,3};

		List<List<Integer>> k=new  ArrayList<>();
		k=ss.Break(a);
	//	System.out.println(k);
		for(List<Integer> l :k){
			System.out.println(l);
		}
		
	}
	public List<List<Integer>> Break(int a[]){
		
		//	System.out.println(res);
        List<List<Integer>>  k=new ArrayList<>();
       k.add(new ArrayList<>());
		for(int num : a){
				int n=k.size();
				for(int i=0;i<n;i++){
					List<Integer> m=new ArrayList<>(k.get(i));
					m.add(num);
					k.add(m);
				}
		}
        return k;
	}
}