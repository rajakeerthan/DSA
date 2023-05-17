import java.util.*;
import static java.lang.System.out;

class dfs {
    public static void main(String[] args) {
        int adj[][] = new int[20][20];
        int visit[] = new int[20];
        int k, l, i;
        dfs g = new dfs();
        out.println("enter no.of nodes");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        out.println("enter no.of edges");
        int e = sc.nextInt();
        out.println("enter sournce bode and destinaton node");
        for (i = 1; i <= e; i++) {
            k = sc.nextInt();
            l = sc.nextInt();
            adj[k][l] = 1;
            adj[l][k] = 1;
        }
        for (i = 1; i < n; i++) {
            visit[i] = 0;
        }
        g.dfs1(1, adj, n, e, visit);
    }

    void dfs1(int i, int a[][], int n, int e, int visit[]) {
        out.println("node" + i);
        visit[i] = 1;

        int j;
        for (j = 1; j <= n; j++) {
            if (a[i][j] == 1 && visit[j] != 1) {
                dfs1(j, a, n, e, visit);
            }
        }

    }
}
