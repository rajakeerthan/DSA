import java.util.*;
import static java.lang.System.out;

class node {
    node left;
    int data;
    node right;
}

class bin_tree {
    public static void main(String[] args) {
        int k, x, y;
        node root = new node();
        tree t = new tree();
        Scanner sc = new Scanner(System.in);
        while (true) {
            out.printf("choose\n1.insert\n2.display\n3.search\n4.delete\n5.exit\n");
            k = sc.nextInt();
            switch (k) {
                case 1:
                    out.println("enter number to insert");
                    x = sc.nextInt();
                    t.insert(root, x);
                    break;
                case 2:
                    out.println("the tre data");
                    t.display(root);
                    break;
                case 3:
                    out.println("enter element to search");
                    x = sc.nextInt();
                    t.search(root, x);

                    break;
                case 4:
                    out.println("enter element to delete");
                    x = sc.nextInt();
                    t.delete(root, x);
                    break;
                default:
                    return;
            }
        }

    }
}

class tree {

    void insert(node root, int x) {
        node nn = new node();
        nn.data = x;
        nn.left = null;
        nn.right = null;
        if (root == null) {
            root = nn;
        } else if (root.left == null && root.data >= x) {
            root.left = nn;
        } else if (root.right == null && root.data <= x) {
            root.right = nn;
        } else if (root.data <= x) {
            insert(root.right, x);
        } else {
            insert(root.left, x);
        }

    }

    void search(node root, int x) {
        if (root == null)
            return;
        else if (root.data == x)
            out.println("element found");
        else if (x <= root.data)
            search(root.left, x);
        else
            search(root.right, x);
    }

    node delete(node root, int x) {
        if (root == null)
        {
            out.println("cant be deleted");
            return null;
        }
        else if (root.data == x) {
            out.println("element found");
            if (root.left == null && root == null)
                root = null;
            else if (root.left == null) {
                node temp = root.right;
                free(root);
                return temp;
            } else if (root.right == null) {
                node temp = root.left;
                free(root);
                return temp;
            } else {
                node temp = min(root.right);
                root.data = temp.data;
                root.right = delete(root.right, x);
            }
            out.println("deleted succefully");
            return root;
        } else if (root.data < x) {
            root.right = delete(root.right, x);
        } else {
            root.left = delete(root.left, x);
        }
        // node k = null;
        // return k;
    }

    void free(node n) {
        n = null;
    }

    node min(node r) {
        while (r.left != null)
            r = r.left;
        return r;
    }

    void display(node root) {
        if (root == null) {
            return;
        }
        out.println(root.data + " ");
        display(root.left);
        display(root.right);
    }
}