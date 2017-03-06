package Language;
import java.util.*;

public class JavaComparator {
    /*
    If you just declare class Dog it will error because you cannot just create new Dog
    You need to put the class on the outside (same package referencing other class (then it becomes package private only members in same package can see it)
    OR you can make the class static
    OR you can make the class nonstatic and use Outerclass.Innerclass innerObject = outerObject.new InnerClass();
     */
     static class Dog implements Comparator<Dog>, Comparable<Dog> {
        public String name;
        public int age;

        Dog() {

        }

        Dog(String n, int a) {
            this.name = n;
            this.age = a;
        }

        public String getName() {
            return name;
        }
        public Dog getDog() {
            return this;
        }
        public int getDogAge() {
            return age;
        }

        //comparable interface
        // if classes have natural order implement Comparable (used to sort classes)
        //based on one class vs other
        @Override
        public int compareTo(Dog d) {
            return (this.name).compareTo(d.name);
        }

        //comparator interface
        //usually used for sorting and treemap treeset... multiple comparisons.
        //based on certain attributes vs other
        @Override
        public int compare(Dog d, Dog d1){
            return d.age - d1.age;
        }

        @Override
        public String toString(){
            return this.name + " Dog is " + age + " years old";
        }
    }

    //Has to be static
    //Or you can create a new Java_Comparator object and do new Java_Comparator().printDogs();
    public static void printDogs(List<Dog> D){
        for(Dog d: D) {
            System.out.println(d);
        }
    }

    public void printDoges(List<Dog> D){
        for(Dog d: D) {
            System.out.println(d);
        }
    }

    public static void main(String[] args) {


        /*Syntax for non-static inner class inside outside class:
        Java_Comparator j = new Java_Comparator();
        Dog b = j.new Dog("hello", 3);

        Syntax for non-static inner class outside outside class:
        Java_Comparator j = new Java_Comparator();
        j.Dog b = j.new Dog("hello", 3);
        */

        /* Testing Dog Class and private/return methods */
        Dog b = new Dog("hello", 3);
        String s = b.getName();
        s = "h";
        System.out.println(b.getName()); //does not change because assignment s changes
        Dog d = b.getDog();
        d.name = "changed";
        System.out.println(b.name); //changes the dog variable because b.name is public and variable changes

        /* testing sorting */
        List<Dog> list = new ArrayList<Dog>();
        for(int i = 0; i < 10; i++){
            char c = (char) (i + 49 + '0'); //string function to convert int to string (starting from 0 is 49)
            list.add(new Dog(Character.toString(c), 1 + (int) (Math.random() * 10))); //convert character to string
        }

        //cannot do printDogs(ArrayList<Dog> D) because arrayList is not a list (static type)
        //all outside methods must be static because nonstatic requires an object...
        System.out.println("Original List:");
        printDogs(list);

        //compare 1 with lambda (sort by age increasing) use this one
        //comparator used mainly for treesets etc.
        System.out.println("\n\nLambda Sort by increasing ages:");
        Collections.sort(list, new Comparator<Dog>(){
            public int compare(Dog d1, Dog d2){
                return d1.age - d2.age; //if private access than screwed must be public or must use getter class
            }
        });
        printDogs(list);

        //compare 2 with comparator
        System.out.println("\n\nComparator sort by decreasing ages");
        Collections.sort(list, new Dog());
        new JavaComparator().printDoges(list); //using nonstatic methods;

        //reverse used the CompareTo Comparable
        System.out.println("\n\nReverse sort by increasing names");
        Comparator<Dog> reverse = Collections.reverseOrder();
        Collections.sort(list, reverse);
        printDogs(list);

        //compare 3 with comparable
        System.out.println("\n\nComparable Sort by increasing names:");
        Collections.sort(list);
        printDogs(list);

        /* IMPORTANT
        Use Array.sort(); for arrays
         */
        Double doubles= 1.2;
        System.out.println(doubles.compareTo(1.123));

    }

}
