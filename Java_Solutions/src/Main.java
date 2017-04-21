import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int testcases = Integer.parseInt(st.nextToken());
        for (int t = 1; t <= testcases; t++) {
            st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());
            ArrayList<Integer> ingredients = new ArrayList<>();
            st = new StringTokenizer(in.readLine());
            for (int i = 0; i < n; i++) {
                ingredients.add(Integer.parseInt(st.nextToken()));
            }
            HashMap<Integer, Integer>[] maps = new HashMap[n];
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(in.readLine());
                HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();
                for (int k = 0; k < p; k++) {
                    int a = Integer.parseInt(st.nextToken()), key = -1, division = a/ingredients.get(i);
                    if (division * ingredients.get(i) * 1.1 >= a) {
                        key = division;
                    } else if (((division + 1) * ingredients.get(i)) * 0.9 <= a){
                        key = division + 1;
                    }
                    if (key == -1) {
                        continue;
                    } else if (mp.get(key) == null) {
                        mp.put(key, 1);
                    } else {
                        mp.put(key, mp.get(key) + 1);
                    }
                }
                maps[i] = mp;
            }

            for (int i = 1; i < maps.length; i++) {
                Iterator<Map.Entry<Integer, Integer>> itr = maps[0].entrySet().iterator();
                while (itr.hasNext()) {
                    Map.Entry<Integer, Integer> it = itr.next();
                    if (!maps[i].containsKey(it.getKey())) {
                        itr.remove();
                    } else {
                        it.setValue(Math.min(it.getValue(), maps[i].get(it.getKey())));
                    }
                }
            }
            int total = 0;
            for (int i : maps[0].values()) {
                total += i;
            }
            out.printf("Case #%d: %d\n", t, total);
        }
        out.close();
        System.exit(0);
    }
}
