package Solutions.POJ;

import java.util.*;
import java.io.*;

public class poj_2232 {

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new FileReader("input.in"));
        //Scanner in = new Scanner(System.in);
        HashMap<String, Integer> mp = new HashMap<String, Integer>();
        mp.put("C", 0); mp.put("S", 1); mp.put("F", 2);
        while(in.hasNext()) {
            int n = in.nextInt();
            pp[] colors = new pp[3];
            colors[0] = new pp("C", 0);
            colors[1] = new pp("S", 0);
            colors[2] = new pp("F", 0);
            for (int i = 0; i < n; i++) {
                String c = in.next();
                colors[mp.get(c)].counter++;
            }
            Arrays.sort(colors);
            if (colors[2].counter == 0) {
                if (colors[1].counter == 0) {
                    System.out.println(colors[0].counter);
                } else {
                    if (colors[1].c == "F" && colors[0].c == "S") {
                        System.out.println(colors[0].counter);
                    } else if (colors[1].c == "S" && colors[0].c == "F") {
                        System.out.println(colors[1].counter);
                    } else if (colors[1].c == "S" && colors[0].c == "C") {
                        System.out.println(colors[0].counter);
                    } else if (colors[1].c == "C" && colors[0].c == "S") {
                        System.out.println(colors[1].counter);
                    } else if (colors[1].c == "C" && colors[0].c == "F") {
                        System.out.println(colors[0].counter);
                    } else if (colors[1].c == "F" && colors[0].c == "C") {
                        System.out.println(colors[1].counter);
                    }
                }
            } else {
                System.out.println(n);
            }
        }
        in.close();
        System.exit(0);
    }

    static class pp implements Comparable<pp> {
        String c;
        int counter;
        pp(String c, int counter) {
            this.counter = counter;
            this.c = c;
        }
        @Override
        public int compareTo(pp o) {
            return o.counter - counter;
        }
    }
}
