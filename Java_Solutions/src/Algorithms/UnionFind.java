package Algorithms;
import java.util.*;

public class UnionFind {
    public static int parent[];
    public static int size[];

    public int find(int x) {
        if (x == parent[x]) { //quick find...
            return x;
        }
        return parent[x] = find(parent[x]); //path compression
    }

    public boolean merge(int x, int y) { //returns true and false (also known as connect)
        int u = find(x); //quick union = + size function
        int v = find(y);
        if (u != v) {
            if (size[u] > size[v]) {
                size[u] += size[v];
                parent[v] = parent[u];
            } else {
                size[v] += size[u];
                parent[u] = parent[v];
            }
            return true;
        }
        return false;
    }

    public static void init(int n){
        parent = new int[n];
        size = new int[n];
        Arrays.fill(size, 1);
        for (int i = 1; i <= parent.length; i++) {
            parent[i] = i;
        }
    }

}
