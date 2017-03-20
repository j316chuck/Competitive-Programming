package CS61B;

import java.util.*;
import java.util.Iterator;
import static org.junit.Assert.*;
import org.junit.Test;


public class MyHashMap<K, V> implements Map61B<K, V>{

    private ArrayList<Entry<K, V>>[] map;
    private HashSet<K> keyset;
    int size = 0;
    int mod;
    double loadfactor;

    public MyHashMap() {
        this(97);
    }

    public MyHashMap(int initialsize) {
        this(initialsize, 0.75);
    }

    public MyHashMap(int initialsize, double loadfactor) {
        this.mod = initialsize;
        this.loadfactor = loadfactor;
        map = (ArrayList<Entry<K, V>>[]) new ArrayList[initialsize];
        for (int i = 0; i < map.length; i++) {
            map[i] = new ArrayList<Entry<K,V>>();
        }
        keyset = new HashSet<K>();
        size = 0;
    }

    /** Removes all of the mappings from this map. */
    public void clear() {
        map = (ArrayList<Entry<K, V>>[]) new ArrayList[mod];
        for (int i = 0; i < map.length; i++) {
            map[i] = new ArrayList<Entry<K, V>>();
        }
        keyset = new HashSet<K>();
        size = 0;
    }

    public int hash(Object key) {
        return (key == null) ? 0 : (0x7fffffff & key.hashCode()) % mod; //Math.floorMod(key, mod)
    }

    /* Returns true if this map contains a mapping for the specified key. */
    public boolean containsKey(K key) {
        return get(key) == null ? false : true;
    }

    /* Returns the value to which the specified key is mapped, or null if this
     * map contains no mapping for the key.
     */
    public V get(K key) {
        int pos = hash(key);
        for (Entry<K, V> e: map[pos]) {
            if (e.getKey().equals(key)) {
                return e.getValue();
            }
        }
        return null;
    }

    /* Returns the number of key-value mappings in this map. */
    public int size() {
        return size;
    }

    /* Associates the specified value with the specified key in this map. */
    public void put(K key, V value) {
        int pos = hash(key);
        for (Entry<K, V> e: map[pos]) {
            if (e.getKey().equals(key)) {
                e.setValue(value);
                return;
            }
        }
        size++;
        map[pos].add(new Entry(key, value));
        keyset.add(key);
        //only mod changes and arraylist...
        if (((double) size/mod) >= loadfactor) {
            resize();
        }
    }

    public void resize() {
        MyHashMap newmap = new MyHashMap(2 * mod, loadfactor);
        for (int i = 0; i < map.length; i++) {
            for (Entry<K, V> e : map[i]) {
                newmap.put(e.getKey(), e.getValue());
            }
        }
        this.map = newmap.map;
        this.mod = newmap.mod;
        this.keyset = newmap.keyset;
        this.size = newmap.size;
        this.loadfactor = newmap.loadfactor;
    }

    /* Returns a Set view of the keys contained in this map. */
    public Set<K> keySet() {
        return keyset;
    }

    //returns iterator with key values
    public Iterator<K> iterator() {
        return keySet().iterator();
    }


    /* Removes the mapping for the specified key from this map if present.
     * Not required for Lab 8. If you don't implement this, throw an
     * UnsupportedOperationException. */
    public V remove(K key) {
        throw new UnsupportedOperationException();
    }

    /* Removes the entry for the specified key only if it is currently mapped to
     * the specified value. Not required for Lab 8. If you don't implement this,
     * throw an UnsupportedOperationException.*/
    public V remove(K key, V value) {
        throw new UnsupportedOperationException();
    }

    private class Entry<K, V> {
        K key;
        V value;
        public Entry (K key, V value) {
            this.key = key;
            this.value = value;
        }
        public V getValue() {
            return value;
        }
        public K getKey() {
            return key;
        }
        public void setValue(V value) {
            this.value = value;
        }
        public void setKey(K key) {
            this.key = key;
        }

        //hashcode .equals and hashcode go together, must be same if .equals() object,
        // watch out for null, needed for hashmap

        @Override
        public boolean equals(Object o) {
            if (o.equals(null) || o.getClass() != getClass()) {
                return false;
            } else if (o == this) {
                return true;
            }
            Entry that = (Entry) o;
            return that.key.equals(this.key) && that.value.equals(this.value);
        }

        @Override
        public int hashCode() {
            int result = 1;
            result = result * 31 + (key == null ? 0 : key.hashCode());
            result = result * 31 + (value == null ? 0 : value.hashCode());
            return result;
        }
    }


    /** Tests of optional parts of lab 9. */
    public static class TestMyHashMapExtra {
        @Test
        public void sanityGenericsTest() {
            try {
                MyHashMap<String, String> a = new MyHashMap<String, String>();
                MyHashMap<String, Integer> b = new MyHashMap<String, Integer>();
                MyHashMap<Integer, String> c = new MyHashMap<Integer, String>();
                MyHashMap<Boolean, Integer> e = new MyHashMap<Boolean, Integer>();
            } catch (Exception e) {
                fail();
            }
        }
        /* Remove Test
         *
         */
        @Test
        public void testRemove() {
            MyHashMap<String,String> q = new MyHashMap<String,String>();
            q.put("c","a");
            q.put("b","a");
            q.put("a","a");
            q.put("d","a");
            q.put("e","a"); // a b c d e
            assertTrue(null != q.remove("c"));
            assertFalse(q.containsKey("c"));
            assertTrue(q.containsKey("a"));
            assertTrue(q.containsKey("b"));
            assertTrue(q.containsKey("d"));
            assertTrue(q.containsKey("e"));
        }

        /* Remove Test 2
         * test the 3 different cases of remove
         */
        @Test
        public void testRemoveThreeCases() {
            MyHashMap<String,String> q = new MyHashMap<String,String>();
            q.put("c","a");
            q.put("b","a");
            q.put("a","a");
            q.put("d","a");
            q.put("e","a");                         // a b c d e
            assertTrue(null != q.remove("e"));      // a b c d
            assertTrue(q.containsKey("a"));
            assertTrue(q.containsKey("b"));
            assertTrue(q.containsKey("c"));
            assertTrue(q.containsKey("d"));
            assertTrue(null != q.remove("c"));      // a b d
            assertTrue(q.containsKey("a"));
            assertTrue(q.containsKey("b"));
            assertTrue(q.containsKey("d"));
            q.put("f","a");                         // a b d f
            assertTrue(null != q.remove("d"));      // a b f
            assertTrue(q.containsKey("a"));
            assertTrue(q.containsKey("b"));
            assertTrue(q.containsKey("f"));
        }
    }
}
