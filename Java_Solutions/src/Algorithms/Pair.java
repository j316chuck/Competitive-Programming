package Algorithms;

/**
 * Created by chuck on 4/20/2017.
 */
public class Pair implements Comparable<Pair> {
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
