package Language;
import java.util.*;
import java.io.*;
import java.util.stream.*;

public class JavaHashSet { //most similar to Solutions.Codeforces.C++ set
    public static void main(String[] args) {
        //http://www4.ncsu.edu/~kaltofen/courses/Languages/JavaExamples/jgl3.1.0/doc/api/com.objectspace.jgl.examples.HashSetExamples.html
        HashSet<String> set = new HashSet();
        set.add("1");
        set.add("2");
        set.add("3");
        //hashset basically useful for only add, and remove
        Set<String> distinctWords = Arrays.asList(args).stream().collect(Collectors.toSet());
        System.out.println(distinctWords.toString());
        Set<String> s1 = new HashSet<String>();
        s1 = distinctWords;
        System.out.println(s1.containsAll(distinctWords));
        s1.addAll(set);
        System.out.println(s1);
        System.out.println(distinctWords);
        s1.retainAll(set);
        s1.removeAll(set);
        //https://docs.oracle.com/javase/tutorial/collections/interfaces/set.html
        //Collection<Type> noDups = new HashSet<Type> (collection);
        //c.stream().collect(Collectors.toSet());

    }
}
