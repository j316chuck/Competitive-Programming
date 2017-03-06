package Language;
import java.util.*;

public class JavaTreeSet {
    //TreeSets
    public static class Animal implements Comparable<Animal>{
        private int age;
        private int weight;
        public Animal(int age, int weight){
            this.age = age;
            this.weight = weight;
        }

        public int compareTo(Animal a){
            if(this.age - a.age == 0) return this.weight-a.weight;
            return this.age - a.age;
        }
        public String toString(){
            return "Age: " + age + " weight " + weight;
        }
    }
    public static class myComp implements Comparator<String> {
        @Override
        public int compare(String str1, String str2) {
            return str1.charAt(0) - str2.charAt(0);
        }
    }
    public static void main(String[] args) {

        //TreeSet -> BinarySearch too with contains
        //hashset does not have subset, treeset more similar to C++ set
        //http://www4.ncsu.edu/~kaltofen/courses/Languages/JavaExamples/jgl3.1.0/doc/api/com.objectspace.jgl.examples.HashSetExamples.html
        TreeSet<Animal> zoo = new TreeSet<Animal>(); //animal has to be comparable or comparator
        for(int i = 0; i < 10; i++) {
            zoo.add(new Animal(i, i+5));
        }
        for(Animal a : zoo)
            System.out.println(a);

        TreeSet<String> ts = new TreeSet<>(new myComp());
        ts.add("a"); ts.add("b"); ts.add("c"); ts.add("e"); ts.add("d");
        System.out.println(ts);

        System.out.println(zoo.pollFirst());

        String lower_bound = ts.lower("d"); //strictly lower than this value
        String lower_floor = ts.floor("d"); //lower or equal to this value;
        String higher_ceiling = ts.ceiling("d"); //lower or equal to this value;
        String higher_bound = ts.higher("d");//returns null if there is no element;
        System.out.println(ts.lower("d"));
        System.out.println(ts.higher("d"));
        System.out.println(ts.floor("d"));
        System.out.println(ts.ceiling("d"));

        //inclusive, exclusive
        TreeSet<String> subsets = (TreeSet) ts.subSet(lower_bound, true, higher_bound, true);
        //[c, d, e]
        subsets = (TreeSet) ts.subSet(lower_bound, higher_bound);
        //[c, d] true true = inclusive exclusive
        System.out.println(subsets);
        if(ts.contains("d")){
            ts.remove("d");
        }

    }
}
