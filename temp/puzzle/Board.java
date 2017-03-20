package hw3.puzzle;

import java.util.LinkedList;
import java.util.Queue;

public final class Board implements WorldState {
    int[][] graph;
    int n;

    public Board(int[][] tiles) {
        n = tiles.length;
        graph = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = tiles[i][j];
            }
        }
    }

    public int tileAt(int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= n) {
            throw new IndexOutOfBoundsException();
        }
        return graph[i][j];
    }

    public int size() {
        return n;
    }


    @Override
    public Iterable<WorldState> neighbors() {
        Queue<WorldState> neighbors = new LinkedList<WorldState>();
        int r = -1, c = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tileAt(i, j) == 0) {
                    r = i;
                    c = j;
                }
            }
        }

        int[][] temp = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = graph[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (Math.abs(r - i) + Math.abs(c - j) == 1) {
                    temp[r][c] = temp[i][j];
                    temp[i][j] = 0;
                    Board b = new Board(temp);
                    neighbors.add(b);
                    temp[i][j] = temp[r][c];
                    temp[r][c] = 0;
                }
            }
        }
        return neighbors;
    }
    public int hamming() { //may be wrong this is greedy...
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tileAt(i, j) != i * n + j + 1) {
                    ret++;
                }
            }
        }
        ret--;
        return ret;
    }

    public int manhattan() {
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tileAt(i, j) == 0) {
                    continue;
                }
                int c = (tileAt(i, j) - 1) % n;
                int r = (tileAt(i, j) - 1) / n;
                ret += Math.abs(c - j);
                ret += Math.abs(r - i);
            }
        }
        return ret;
    }

    public int estimatedDistanceToGoal() {
        return manhattan();
    }

    public boolean isGoal() {
        return hamming() == 0;
    }

    @Override
    public boolean equals(Object b) {
        if (b == null || b.getClass() != getClass()) {
            return false;
        }
        if (b == this) {
            return true;
        }
        Board board = (Board) b;
        if (board.size() != size()) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board.tileAt(i, j) != tileAt(i, j)) {
                    return false;
                }
            }
        }
        return true;
    }

    @Override
    public int hashCode() {
        int ret = 1;
        int prime = 31;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ret *= 31;
                ret += tileAt(i, j);
                ret %= 100000007;
            }
        }
        return ret;
    }
    /** Returns the string representation of the board. 
      * Uncomment this method. */
    public String toString() {
        StringBuilder s = new StringBuilder();
        int N = size();
        s.append(N + "\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                s.append(String.format("%2d ", tileAt(i, j)));
            }
            s.append("\n");
        }
        s.append("\n");
        return s.toString();
    }
    /*public static void main(String[] args) {
        int[][] graph = new int[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                graph[i][j] = i * 3 + j + 1;
            }
        }
        graph[2][2] = 0;
        Board b = new Board(graph);
        System.out.println(b);
        System.out.println(b.neighbors());
        System.out.println(b.isGoal());
    }*/

}
