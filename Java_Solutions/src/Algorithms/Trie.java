package Algorithms;
import java.util.*;

public class Trie {

    static class Node {
        //ch - 'a' to convert
        //else char 128 is needed
        Node[] children = new Node[26];
        boolean leaf;
        //String word;
        //int word_count;
        //int prefix_count;
        //int weight;
        //O(n * 26 * k) k = length of word for prefix count
        //approximately equivalent to hashtable
    }
    static ArrayList<Node> iteratePrefix(Node node, String s) {
        Node v = node;
        for (char c : s.toCharArray()) {
            Node next = v.children[c - 'a'];
            if (next == null) {
                return null;
            }
            v = next;
        }
        ArrayList<Node> result = new ArrayList<Node>();
        LinkedList<Node> q = new LinkedList<Node>();
        q.add(v);
        while (!q.isEmpty()) {
            Node top = q.poll();
            if (top.leaf == true) {
                result.add(top); //replace with word
            }
            for (int i = 0; i < 26; i++) {
                if (top.children[i] != null) {
                    q.addLast(top.children[i]);
                }
            }
        }
        return result;
    }
    public static void insert(Node root, String s) {
        Node v = root;
        for (char ch : s.toCharArray()) {
            Node next = v.children[ch - 'a'];
            if (next == null) {
                next = v.children[ch - 'a'] = new Node();
            }
            v = next;
        }
        v.leaf = true;
    }
    public static void printSorted(Node node, String s) {
        for (int i = 0; i < node.children.length; i++) {
            if (node.children[i] != null) {
                char c = (char) (i + 'a');
                printSorted(node.children[i], s + c);
            }
        }
        if (node.leaf) {
            System.out.println(s);
        }
    }
    //recursive insertion
    /*
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
    */
    // Usage example
    public static void main(String[] args) {
        Node root = new Node();
        insert(root, "hello");
        insert(root, "world");
        insert(root, "hi");
        printSorted(root, "");
    }
}
