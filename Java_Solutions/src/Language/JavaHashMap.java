package Language;
import java.util.*;

public class JavaHashMap {

    //Use hashmap most of time everything is on average O(1)
    //use treemap when you need to sort by soomething specific O(logN) (binary tree redblack tree)
    //like treeset contains descendingMap(), floorEntry, secondEntry, firstKey, ceilingEntry, lowerEntry, higherEntry
    //Map.Entry etc. put get, contains, isEmpty .containsAll()
    //https://docs.oracle.com/javase/tutorial/collections/interfaces/map.html

    public static void printMap(Map<Integer, ArrayList<Integer>> mp){
        //set of entries
        Set set = mp.entrySet();
        Iterator itr = set.iterator();
        while(itr.hasNext()){
            Map.Entry me = (Map.Entry) itr.next();
            System.out.println(me.getKey() + " " + me.getValue());
        }
    }
    public static void main(String[] args) {

        Map<Integer, ArrayList<Integer>> mp = new HashMap<>();
        for(int i = 10; i > 0; i--) {
            int random = (int) (Math.random() * 10);
            if(!mp.containsKey(random)) {
                mp.put(random, new ArrayList<Integer>());
                for(int j = 0; j < 10; j++){
                    mp.get(random).add((int) (Math.random() * 10) + i + j);
                }
            }
        }
        //also can remove using remove(key) .empty() .size()
        printMap(mp);

        TreeMap<Integer, ArrayList<Integer>> sortedMap = new TreeMap(mp);
        for (Map.Entry a: sortedMap.entrySet()) {
            System.out.println(a.getKey() + " " + a.getValue());
        } //done use getKey() and getValue() for keys and value;
    }
}
