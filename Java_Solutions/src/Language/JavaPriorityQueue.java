package Language;
import java.util.*;

class Pair<X, Y> {
    X first;
    Y second;

    public Pair(X f, Y s){
        first = f;
        second = s;
    }
    void setFirst(X f) {
        first = f;
    }
    void setSecond(Y s) {
        second = s;
    }
    @Override
    public String toString(){
        return first.toString() + " " + second.toString();
    }
}

class JavaPriorityQueue {
    public static void main(String[] args) {
        /*
        Collection interface
        all collections have size(), isEmpty(), contains(), add(), remove(), and iterator()
         */
        //list has get set add and remove indexOf, rotate, swap, fill, binarySearch, subList
        //Collections.rotate(list, 3); 3 is size of rotation;
        //map
        //set has set notations .containsAll = t/f is subset .addAll = union, .retainAll = intersection, .removeall = assymetric setdifference

        //priority queue -> size, toArray(), remove, poll, peek, offer, contains, clear(), add
        //queue offer and add Same
        //priorityqueue intialization (capacity, comparator) or just (comparator)
        Pair<Integer, String> pi = new Pair<Integer, String>(3, "h");
        /*PriorityQueue< Pair<Integer, String> > pq = new PriorityQueue<>(5, new Comparator<Pair<Integer, String>> (){
            public int compare(Pair <Integer, String> i, Pair <Integer, String> j) {
                return i.first -j.first;
            }
        });*/
        PriorityQueue< Pair<Integer, String> > pq = new PriorityQueue<>(5, new Comparator<Pair <Integer, String> >(){
            public int compare(Pair <Integer, String> i, Pair<Integer, String> j){
                return i.first - j.first;
            }
        });

        pq.offer(new Pair <Integer, String> (100, "join"));
        pq.offer(new Pair <Integer, String> (100, "join"));
        pq.offer(new Pair <Integer, String> (100, "join"));
        pq.offer(new Pair <Integer, String> (100, "join"));

        int result = pq.peek().first;
        String res = pq.poll().second;
        //has contains also has remove...
        Object[] array = pq.toArray();
        for(int i = 0; i < array.length; i++){
            System.out.print(array[i] + " ");
        }

        //queue and stack same way use LinkedList
        //clear
        //contains
        //add(int index, Obj)
        //remove (Obj)
        LinkedList<Integer> queue = new LinkedList<Integer>();
        for (int i = 0; i < 10; i++) {
            queue.offer(i);
            queue.addFirst(i);
            //try to use queue.poll and queue.offer();
        }
        while(!queue.isEmpty()){
            System.out.println(queue.poll());
        }
        //arraydequee new ArrayDeque<Integer>(); //also LinkedList<Integer>(); basically queue
    }
    /*public class Compare extends Comparator {
        @Override
        public int compare(Pair p1, Pair p2) {
            if(p1.first.equal
        }
        //you can write a comparator class
    }*/
}
