import java.util.*;
class positions{
    public static void main(String args[]){

        int k;
        try{
        List<Integer> a=new ArrayList<Integer>();
        positions p=new positions();
        
        a=p.returning();
        System.out.println(a);
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
    public List<Integer> returning(){
      
        List<Integer> a=new ArrayList<Integer>();
            a.remove(0);
            a.add(0,1);
            a.remove(0);
            a.add(0,1);
            a.add(1,2);
            return a;
     
        
    }

}