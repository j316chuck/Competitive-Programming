package Algorithms;

import java.util.Arrays;
import java.util.Comparator;

//not tested may not work check for kruskal algorithm...

public class Edge implements Comparator<Edge> {
    public int u, v, w;

    public Edge(int u, int v, int w) {
        this.u = u;
        this.v = v;
        this.w = w;
    }

    @Override
    public int compare(Edge e1, Edge e2) {
        return e1.w - e2.w;
    }

    @Override
    public boolean equals(Object e) {
        if (this == e) return true;
        if (e == null) return false;
        if (e.getClass() != getClass()) return false;
        Edge that = (Edge) e;
        if (that.u != this.u || that.v != this.v || that.w != this.w) return false;
        return true;
    }

    /*@Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = result * prime + u;
        result = result * prime + v;
        result = result * prime + w;
        return result;
    }*/


    @Override
    public int hashCode() {
        return Arrays.hashCode(new Object[]{u, v, w});
    }

}
