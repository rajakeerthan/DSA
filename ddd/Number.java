import java.util.*;
import javax.swing.*;
public class Number{
    public static void main(String args[]){
        JFrame jf=new JFrame();
        JLabel l1=new JLabel("guess the number : ");
        JTextField f1=new JTextField();
        l1.setbounds(100,100,100,100);
        f1.setBounds(100,100,100,100);
        jf.add(l1);
        jf.add(f1);
        JButton jb=new JButton("submit");
        jb.setBounds(200,200,100,100);
        jf.add(jb);
    }
}