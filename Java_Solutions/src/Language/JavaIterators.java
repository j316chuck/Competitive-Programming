package Language;
import java.util.*;

//http://stackoverflow.com/questions/6863182/what-is-the-difference-between-iterator-and-iterable-and-how-to-use-them
public class JavaIterators {
    public static void main(String[] args){
        //also learned Pairs!!! (or that java doesn't have pairs)
        //Pair p1 = new Pair(3, 4);
        ArrayList names = new ArrayList(); //YOU CAN DECLARE WITHOUT TYPE???
        names.add("Chaitanya");
        names.add(1);
        names.add(3.4);

        Iterator it = names.iterator(); //iterators don't have peek
        while(it.hasNext()){
            System.out.println(it.next().toString());
            //you cannot do (String) it.next();
            //you must do .toString();
        }

        //cannot modify list while iterating through it
        /*int counter = 0;
        for (Object d: names) {
            System.out.println(d); //automatically has toString();
            if (counter == 0) {
                names.add("hello"); //cannot modify arraylist inside array
            }
            counter++;
        }*/
        //can modify in nonenhanced for loop
        for (int i = 0; i < names.size(); i++) {
            if (i == 0) {
                names.add("hello");
            }
            System.out.println(names.get(i));
        }

        /* hashmap */
        HashMap<Integer, String> hmap = new HashMap<>();
        hmap.put(11, "AB");
        hmap.put(2, "CD");
        System.out.println("FOR LOOP");
        for (Map.Entry me: hmap.entrySet()) {
            System.out.println(me.getKey() + " "+ me.getValue());
        }

        System.out.println("While Loop:");
        Iterator iterator = hmap.entrySet().iterator();
        while (iterator.hasNext()) {
            Map.Entry me = (Map.Entry) iterator.next();
            System.out.println(me.getKey() + " " + me.getValue());
        }

        /* ListIterators */
        ArrayList al = new ArrayList();
        al.add("A");
        al.add("B");
        al.add("C");
        al.add("D");

        ListIterator iter = al.listIterator(); //List iterator interface
        while(iter.hasNext()){
            Object element = iter.next();
            System.out.println(iter.nextIndex() + ": " + element);
            iter.set(element + "-MAN");
        }
        //also has remove function and previous Index();
        while(iter.hasPrevious()){
            Object element = iter.previous();
            System.out.println(element + " " + iter.previousIndex());
        }
        System.out.println();
    }
}
