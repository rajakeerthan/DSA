import java.util.*;
import static java.lang.System.out;

class cirq {
    public static void main(String args[]) {
        int k, x;
        Scanner sc = new Scanner(System.in);
        queue q = new queue();
        while (true) {

            out.printf("enter 1.enq\n2.deq\n3.display\n4.exit\n");
            k = sc.nextInt();
            switch (k) {
                case 1:
                    out.println("enter element to insert\n");
                    x = sc.nextInt();
                    q.enq(x);
                    break;
                case 2:
                    q.deq();
                    break;
                case 3:
                    q.display();
                    break;
                default:
                    return;
            }
        }
    }
}

class queue {
    int front = -1, rear = -1;
    int q[] = new int[5];

    void enq(int x) {
        if (this.front == -1 || this.rear == -1) {
            this.front = 0;
            this.rear = 0;
            q[this.rear] = x;
        } else if (this.front == (this.rear + 1) % 5) {
            out.println("overflow");
        } else {
            this.rear = (this.rear + 1) % 5;
            q[this.rear] = x;
        }
    }

    void deq() {
        if (this.rear == -1 && this.front == -1) {
            out.println("underflow");
        } else if (this.front == this.rear) {
            out.println("the deleted element is " + q[this.front]);
            this.front = -1;
            this.rear = -1;
        } else {
            out.println("the deleted element is " + q[this.front]);
            this.front = (this.front + 1) % 5;
        }
    }

    void display() {
        int i = this.front;
        if (this.front == -1) {
            out.println("empty");
            return;
        }
        while (i != this.rear) {
            out.printf("%d  ", q[i]);
            i = (i + 1) % 5;
        }
        out.println(q[this.rear]);
    }
}