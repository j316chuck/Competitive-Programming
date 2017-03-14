package Algorithms;

public class Hashing {
    //hashCode() can use hashCode() & 0x7FFFFFFF % MOD;
    //uniform hashing assumption, collision resolution -> external chaining and open addressing
    //N/M = cost of expected amortized search and insert time... Math.floorMod(n, m) ... just do n + m % m;
    //linear probing = use empty array entries to handle collisions
    //search insert and delete time = O(M/N)

    //hashcode of string is
    /*public int hashCode() {
        int h = hash;
        if (h == 0 && value.length > 0) {
            char val[] = value;

            for (int i = 0; i < value.length; i++) {
                h = 31 * h + val[i];
            }
            hash = h;
        }
        return h;
    } */
    //valid hash function means objects that are .equals() will have same hash function...
    //thus, you must use all values in a hash function
    // furthermore -1 is allowed in a hash function
    // integers that collide ... overflow okay...
    // object hashcode returns the memory location

    //hashmaps = immutable key values... should not be able to modify key values
    //sometimes able to get it back but very rarely...
    //perfect hash = hash function that maps distinct elements into distinct buckets with no collision
    //remember to check for null.... in all hashcodes...
    //null = 0, abcdefghijk... etc = 31, pieces = 3 (null, x, O) ... this is the prime that you multiply by

    //typical hash function
    public int hashCode(Object[] value) {
        int result = 1; //not 0 = better performance
        final int prime = 31;
        for (int i = 0; i < value.length; i++) {
            if (value[i] == null) {
                result = result * prime;
                continue;
            }
            result = result * prime + value[i].hashCode();
        }
        return result;
    }

    //same hash
    public static String samehash(String s, int level) {
        if (s.length() < 2)
            return s;
        String sub2 = s.substring(0, 2);
        char c0 = sub2.charAt(0);
        char c1 = sub2.charAt(1);
        c0 = (char) (c0 + level);
        c1 = (char) (c1 - 31 * level); //we can also + modulo c1 - 31 * level
        String newsub2 = new String(new char[] { c0, c1 });
        String re =  newsub2 + s.substring(2);
        return re;
    }


}