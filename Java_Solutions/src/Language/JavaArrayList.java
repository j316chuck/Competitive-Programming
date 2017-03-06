package Language;
import java.util.*;

public class JavaArrayList {

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
    public static void main(String[] args){

        /* 1D ArrayList functions */
        ArrayList<Integer> A = new ArrayList<Integer>();
        for(int i = 0; i < 10; i++){
            A.add(i);
        }
        A.remove(3);
        A.remove(5);
        System.out.println(A);

        int find = A.indexOf(2);
        A.set(find, 3);

        for(int i = 0; i < A.size(); i++){
            System.out.print(A.get(i) + " ");
        }
        System.out.println();
        A.clear();


        /*Initalization Blocks */
        for (char c :new ArrayList<Character>() {{add('a'); add('b'); add('c');}}) {
            System.out.println("char: " + c);
        }
        List<Character> list = Arrays.asList('a', 'b', 'c');
        //or can do Arrays.asList(insert list);

        /* Collection Functions */
        List<Animal> zoo = new ArrayList<> ();
        for(int i = 0; i < 10; i++) {
            zoo.add(new Animal(i, i + 10));
        }
        Collections.sort(zoo);
        for(Animal a: zoo) System.out.println(a);
        int index = Collections.binarySearch(zoo, new Animal(1, 11));
        System.out.println(zoo.get(index));

        // 13 is not present. 13 would have been inserted
        // at position 4. So the function returns (-4-1)
        // which is -5. (returns -position - 1)
        //also it returns lower_bound so any element greater than the element not found;
        //so to resize you do -(index + 1)

        int secondindex = Collections.binarySearch(zoo, new Animal(1, 3));
        zoo.add(-(secondindex+1), new Animal(1, 3));
        System.out.println(secondindex);
        for(Animal a: zoo) System.out.println(a);
        //make sure in the comparable you have established that both values are compared...
        //secondindex = -(secondindex + 1);
        //element above
        /*System.out.println(zoo.get(-secondindex));
        //element below
        System.out.println(zoo.get(-secondindex-1));


        //has .contains (O(n)) and .indexOf(O(n))
        /* 2D arrayLists */
        //almost always never use arraylists
        List<List<Integer>> obj = new ArrayList<List<Integer>>();
        for (int i = 0; i < 10; i++) {
            obj.add(new ArrayList<Integer>());
            for(int j = 0; j < 10; j++){
                obj.get(i).add(i * 10 + j);
            }
        }

        for(int i = 0; i < obj.size(); i++) {
            for(int j = 0; j < obj.get(i).size(); j++) {
                obj.get(i).set(j, obj.get(i).get(j) + 11);
            }
        }

        for(int i = 0; i < obj.size(); i++) {
            for(int j = 0; j < obj.get(i).size(); j++){
                System.out.print(obj.get(i).get(j) + (j == (obj.get(i).size()-1) ? "\n" : " "));
            }
        }
    }
}
