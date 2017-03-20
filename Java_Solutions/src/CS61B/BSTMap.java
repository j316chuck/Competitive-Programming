package CS61B;
import java.util.*;

public class BSTMap<K extends Comparable<K>, V> implements Map61B<K, V>{

    private class Node {
        private K key;
        private V val;
        private Node left, right;

        public Node(K key, V val) {
            this.key = key;
            this.val = val;
        }

        public Node() {
            this.key = null;
            this.val = null;
        }
    }

    private Node currentnode;

    public BSTMap() {
        currentnode = null;
    }

    @Override
    public void clear() {
        currentnode = null;
    }

    /* Returns true if this map contains a mapping for the specified key. */
    @Override
    public boolean containsKey(K key) {
        return get(key) != null;
    }

    /* Returns the value to which the specified key is mapped, or null if this
     * map contains no mapping for the key.
     */
    @Override
    public V get(K key) {
        return get(key, currentnode);
    }

    public V get(K key, Node n) {
        if (n == null) {
            return null;
        }
        int cmp = key.compareTo(n.key);
        if (cmp < 0) {
            return get(key, n.left);
        } else if (cmp > 0) {
            return get(key, n.right);
        } else {
            return n.val;
        }
    }

    /* Returns the number of key-value mappings in this map. */
    @Override
    public int size() {
        return size(currentnode);
    }

    public int size(Node n) {
        if (n == null) {
            return 0;
        }
        return 1 + size(n.left) + size(n.right);
    }

    /* Associates the specified value with the specified key in this map. */
    @Override
    public void put(K key, V value) {
        currentnode = put(key, value, currentnode);
    }


    public Node put(K key, V value, Node n) {
        if (n == null) {
            n = new Node(key, value);
            return n;
        }
        int cmp = key.compareTo(n.key);
        if (cmp < 0) {
            n.left = put(key, value, n.left);
        } else if (cmp > 0) {
            n.right = put(key, value, n.right);
        } else {
            n.val = value;
        }
        return n;
        //n.size = 1 + size(n.left) + size(n.right);
    }


    public void printInOrder() {
        printInOrder(currentnode);
    }

    public void printInOrder(Node n) {
        if (n == null) {
            return;
        }
        printInOrder(n.left);
        System.out.println(n.val);
        printInOrder(n.right);
    }

    @Override
    /* Returns a Set view of the keys contained in this map. */
    public Set<K> keySet(){
        throw new UnsupportedOperationException();
    }

    /* Removes the mapping for the specified key from this map if present.
     * Not required for Lab 8. If you don't implement this, throw an
     * UnsupportedOperationException. */
    @Override
    public V remove(K key) {
        throw new UnsupportedOperationException();
    };

    @Override
    public Iterator<K> iterator() {
        throw new UnsupportedOperationException();
    }

    /* Removes the entry for the specified key only if it is currently mapped to
     * the specified value. Not required for Lab 8. If you don't implement this,
     * throw an UnsupportedOperationException.*/
    @Override
    public V remove(K key, V value) {
        throw new UnsupportedOperationException();
    };
}

