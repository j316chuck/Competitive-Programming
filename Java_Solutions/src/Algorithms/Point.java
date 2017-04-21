package Algorithms;

/**
 * Created by chuck on 4/20/2017.
 */
public class Point implements Comparable<Point> {
    int r, c;
    char ch;
    Point(int r, int c, char ch) {
        this.r = r;
        this.c = c;
        this.ch = ch;
    }

    public int compareTo(Point x) {
        if (this.r == x.r) {
            return this.c - x.c;
        }
        return this.r - x.r;
    }
}