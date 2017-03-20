package hw3.puzzle;

import edu.princeton.cs.algs4.MinPQ;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Set;
import java.util.List;
import java.util.Collections;
import java.util.Iterator;
import java.util.HashMap;

public final class Solver {
    private final int moves;
    private final Iterable<WorldState> solution;

    /*public class MyComparator<Node> implements Comparator<Node> {
        public int compare(Node a, Node b) {
            return (a.move + a.w.estimatedDistanceToGoal())
                    - (b.move + b.w.estimatedDistanceToGoal());
        }
    }*/

    public Solver(WorldState initial) {

        MinPQ<Node> pq = new MinPQ<Node>(new Comparator<Node>() {
            public int compare(Node a, Node b) {
                //return (a.move + a.w.estimatedDistanceToGoal())
                //        - (b.move + b.w.estimatedDistanceToGoal());
                return a.calcDistance() - b.calcDistance();
            }
        });

        pq.insert(new Node(initial, 0, null));
        Set<WorldState> visited = new HashSet<WorldState>();
        while (!pq.isEmpty()) {
            Node top = pq.delMin();
            WorldState w = top.w;
            int move = top.move;
            if (w.isGoal()) {
                moves = move;
                List<WorldState> result = new ArrayList<WorldState>();
                while (top != null) {
                    result.add(top.w);
                    top = top.prev;
                }
                Collections.reverse(result);
                solution = result;
                return;
            }
            Iterable<WorldState> iterable = w.neighbors();
            Iterator<WorldState> itr = iterable.iterator();
            while (itr.hasNext()) {
                WorldState nextw = itr.next();
                if (visited.add(nextw)) {
                    pq.insert(new Node(nextw, move + 1, top));
                }
            }
        }
        moves = -1;
        solution = null;
    }

    public int moves() {
        return moves;
    }

    /*
    Iterable -> iterator
    Iterator -> hasnext(), next(), remove()
    Iterable<WorldState> p= new ArrayList<WorldState> Arraylist extends iterable
    Iterator i = p.iterator();
     */
    public Iterable<WorldState> solution() {
        return solution;
    }

    public static class Node {
        Node prev;
        int move;
        WorldState w;
        static HashMap<WorldState, Integer> mp;

        public Node(WorldState w, int move, Node prev) {
            this.w = w;
            this.move = move;
            this.prev = prev;
            if (mp == null) {
                mp = new HashMap<WorldState, Integer>();
            }
        }

        public int calcDistance() {
            int ret = 0;
            if (mp.get(w) == null) {
                ret = w.estimatedDistanceToGoal();
                mp.put(w, ret);
            } else {
                ret = mp.get(w);
            }
            return move + ret;
        }
    }

    /*public static void main(String[] args) {
        Solver s = new Solver(null);

    }*/
}
