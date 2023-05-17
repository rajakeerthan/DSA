import java.util.*;
import static java.lang.System.out;

class node {
    node prev;
    int data;
    node next;
}

class scl {
    public static void main(String[] args) {

        int k, x;
        Scanner sc = new Scanner(System.in);
        list l = new list();
        while (true) {
            out.printf("enter 1.insert_at_end\n2.delete_at_end\n3.display\n4.insert+a_beg\n5.del_beg\n9.exit\n");
            k = sc.nextInt();
            switch (k) {
                case 1:
                    out.println("enter element to insert");
                    x = sc.nextInt();
                    l.insert_end(x);
                    break;
                case 2:
                    l.del_end();
                    break;
                case 3:
                    l.display();
                    break;
                case 4:
                    out.println("enter element to insert");
                    x = sc.nextInt();
                    l.insert_beg(x);
                    break;
                case 5:
                    l.del_beg();
                    break;
                default:
                    return;
            }
        }
    }
}

class list {
    node head;

    void insert_end(int x) {
        node nn = new node();
        nn.prev = null;
        nn.next = null;
        nn.data = x;
        if (head == null) {
            head = nn;
        } else if (head.next == null) {
            head.next = nn;
            nn.next = head;
            head.prev = nn;
            nn.prev = head;
        } else {
            node temp = head;
            while (temp.next != head) {
                temp = temp.next;
            }
            nn.next = head;
            head.prev = nn;
            temp.next = nn;
            nn.prev = temp;

        }
    }

    void del_end() {
        if (head == null)
            out.println("empty");
        else if (head.next == null)
            head = null;
        else {
            node temp = head;
            while (temp.next != head) {
                temp = temp.next;
            }
            (temp.prev).next = head;
            head.prev = temp;
            ;
        }
    }

    void insert_beg(int x) {
        node nn = new node();
        nn.data = x;
        nn.next = null;
        nn.prev = null;
        if (head == null) {
            head = nn;
        } else if (head.next == null) {
            head.next = nn;
            nn.next = head;
            head.prev = nn;
            nn.prev = head;
            head = nn;
        } else {
            (head.prev).next = nn;
            nn.prev = head.prev;
            nn.next = head;
            head.prev = nn;
            head = nn;

        }
    }

    void del_beg() {
        if (head == null)
            out.println(" underflow ");
        else if (head.next == null)
            head = null;
        else {
            (head.prev).next = head.next;
            (head.next).prev = head.prev;
            head = head.next;
        }
    }

    void display() {
        node temp = head;
        while (temp.next != head) {
            out.printf("%d ", temp.data);
            temp = temp.next;
        }
        out.println(temp.data);
    }
}