package Algorithms;

import java.util.*;
import java.io.*;

public class TriePractice {
    static class Node{
        boolean leaf;
        Node[] children = new Node[26];
        int priority = 0;
    }

    //standard insert too slow..
    /*static void insert(Node node, String s, int priority) {
        Node v = node;
        for (char c : s.toCharArray()) {
            Node next = v.children[c - 'a'];
            if (next == null) {
                v.children[c - 'a'] = next = new Node();
            }
            v = next;
        }
        v.leaf = true;
        v.priority = Math.max(priority, v.priority);
    }*/

    static int insert2(Node node, String s, int priority) {
        if (s == null || s.isEmpty()) {
            return priority;
        }
        if (node.children[s.charAt(0) - 'a'] == null) {
            node.children[s.charAt(0) - 'a'] = new Node();
        }
        int res = insert2(node.children[s.charAt(0) - 'a'], s.substring(1), priority);
        node.priority = Math.max(res, node.priority);
        return node.priority;
    }
    //iterative way too slow...
    /*static int countPrefix(Node node, String s) {
        Node v = node;
        for (char c : s.toCharArray()) {
            Node next = v.children[c - 'a'];
            if (next == null) {
                return -1;
            }
            v = next;
        }
        int result = 0;
        LinkedList<Node> q = new LinkedList<Node>();
        q.add(v);
        while (!q.isEmpty()) {
            Node top = q.poll();
            if (top.leaf == true) {
                result = Math.max(result, top.priority);
            }
            for (int i = 0; i < 26; i++) {
                if (top.children[i] != null) {
                    q.addLast(top.children[i]);
                }
            }
        }
        return result;
    }*/

    static int countPrefix(Node node, String s) {
        Node v = node;
        for (char c : s.toCharArray()) {
            Node next = v.children[c - 'a'];
            if (next == null) {
                return -1;
            }
            v = next;
        }
        return v.priority;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        String s; int p;
        Node root = new Node();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(in.readLine());
            s = st.nextToken();
            p = Integer.parseInt(st.nextToken());
            insert2(root, s, p);
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            out.println(countPrefix(root, st.nextToken()));
        }
        out.close();
        System.exit(0);
    }


    static class Pair implements Comparable<Pair> {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pair p) {
            if (first != p.first)
                return Integer.compare(first, p.first);
            return Integer.compare(second, p.second);
        }

        public int hashCode() {
            return first * 1_000_003 + second;
        }

        public boolean equals(Object o) {
            if (o == null || !(o instanceof Pair))
                return false;
            Pair p = (Pair) o;
            return first == p.first && second == p.second;
        }
    }
}


