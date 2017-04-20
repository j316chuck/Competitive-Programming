package Language;
import java.util.stream.*;
import java.util.*;
/*
        Streams can be obtained in a number of ways. Some examples include:
        From a Collection via the stream() and parallelStream() methods;
        From an array via Arrays.stream(Object[]);
        From static factory methods on the stream classes, such as Stream.of(Object[]), IntStream.range(int, int) or Stream.iterate(Object, UnaryOperator);
        The lines of a file can be obtained from BufferedReader.lines();
        Streams of file paths can be obtained from methods in Files;
        Streams of random numbers can be obtained from Random.ints();
        Numerous other stream-bearing methods in the JDK, including BitSet.stream(), Pattern.splitAsStream(java.lang.CharSequence), and JarFile.stream().
        streams are LAZY... they do not change the original list
        terminal operations - forEach, sum = finish
        intermediate operations - filter, map, = create a new stream lazily
*/

public class JavaStreams {
    public static void main(String[] args) {
        List names = new ArrayList();
        names.add("Mahesh");
        names.add("Suresh");
        names.add("Ramesh");
        names.add("Naresh");
        names.add("Kalpesh");
        func f = (Object b) -> System.out.println(b);
        names.forEach(System.out::println);
        names.forEach(f::print);
        List anotherone = new ArrayList();
        names.forEach(anotherone::add);
        anotherone.forEach(System.out::println);
        //because all lists, hashsets extend collections they all have stream();
        // https://docs.oracle.com/javase/8/docs/api/java/util/stream/package-summary.html
        List<String> l = new ArrayList(Arrays.asList("one", "two"));
        Stream<String> sl = l.stream();
        l.add("three");
        //String s = sl.collect(joining(" "));
        //one two three
        //reduce, map, collect, filter
        List<Integer> num = Arrays.asList(1,2, 3, 4, 5);
        List<Integer> collect1 = num.stream().map(n -> n * 2).collect(Collectors.toList()); //collectors.toList, collectors.toSet, collectors.toMap
        System.out.println(num + "\n" + collect1);

    }
    interface func {
        void print(Object s);
    }
}
