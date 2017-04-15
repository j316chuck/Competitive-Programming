package Language;

import java.util.*;

public class JavaTreeMap {
    /*
    Input: 1 2 2 3 3 1 4 5 6 7;
    Output: 1 1 2 2 3 3 4 5 6 7;
            1 6 2 3 4 5 7 8 9 10
     */
    public static class Node implements Comparable<Node> {
        int val;
        int pos;
        public Node(int v, int p) {
            val = v;
            pos = p;
        }
        @Override
        public int compareTo(Node a) {
            if (a.val == val) {
                return pos - a.pos;
            }
            return val - a.val;
        }
        @Override
        public String toString() {
            return "(" + val + ", " + pos + ")";
        }
    }
    public static void main(String[] args) {
        TreeSet<Node> t = new TreeSet<Node>();
        //Comparator c = t.comparator();
        for (int i = 0; i < args.length; i++) {
            t.add(new Node(Integer.parseInt(args[i]), i+1));
        }
        /*
        Alternate O(NlogN way)
        CF61E
         */
    }
}
