package Language;

import java.util.*;
import java.io.*;

public class JavaLambdas {
    //http://www.drdobbs.com/jvm/lambda-expressions-in-java-8/240166764?pgno=2
    /*
    A functional interface is the only thing that you can do with a lambda
     */

    public static class Node {
        int first, second;
        Node(int f, int s) {
            first = f;
            second = s;
        }
        public String toString() {
            return "(" + first + "," + second + ")";
        }
    }
    public static void main(String[] args) {
        /*
        Method References:
        object::instanceMethod
        Class::staticMethod
        Class::instanceMethod
        String::CompareToIgnoreCase
        TreeSet::new
         */
        MathOperation addition = (int a, int b)  -> a + b;
        MathOperation subtraction = (a, b) -> a-b;
        MathOperation division = (int a, int b) -> {return a/b; };
        System.out.println(division.operation(10, 5));
        Node c[] = new Node[10];
        for (int i = 0; i < 10; i++) {
            c[i] = new Node(i, (int) (Math.random() * 10));
        }
        //sort is comparator -> compare();
        /*Comparator<Pair> comp = (Pair<Integer, Integer> f, Pair<Integer, Integer> s) -> {
            if(f.first == s.first) return f.second - s.second;
            else return f.first - s.first;
        };*/
        //Arrays.sort(pairs, (Pair a, Pair b) -> {if (a.first == b.first) return a.second - b.second;
        //generics bad because they require extra stuff... that the object may not have                                        else return a.first - b.first;});
        Arrays.sort(c, (Node a, Node b) -> {
            if (a.first == b.first) return a.second - b.second;
            else return a.first - b.first;
        });

        for (int i = 0; i < c.length; i++) {
            System.out.print(c[i]);
        }
    }

    //one abstract function
    interface MathOperation {
        int operation(int a, int b);
    }
}
