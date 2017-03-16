package Solutions.USACO;

import java.util.*;
import java.io.*;

public class lasers {
    public static void main(String[] args) throws IOException{

        BufferedReader in = new BufferedReader(new FileReader("lasers.in"));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lasers.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int xl = Integer.parseInt(st.nextToken());
        int yl = Integer.parseInt(st.nextToken());
        int xb = Integer.parseInt(st.nextToken());
        int yb = Integer.parseInt(st.nextToken());

        Map<Integer, ArrayList<Integer>> xtoy = new HashMap<Integer, ArrayList<Integer>>();
        Map<Integer, ArrayList<Integer>> ytox = new HashMap<Integer, ArrayList<Integer>>();
        Map<Line, Integer> dist = new HashMap<Line, Integer>();
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(in.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            if(!xtoy.containsKey(x)){
                xtoy.put(x, new ArrayList<Integer>());
            }
            xtoy.get(x).add(y);
            if(!ytox.containsKey(y)){
                ytox.put(y, new ArrayList<Integer>());
            }
            ytox.get(y).add(x);
        }

        LinkedList<Line> q = new LinkedList<Line>();
        q.offer(new Line(yl, true));
        q.offer(new Line(xl, false));
        dist.put(new Line(xl, false), 0);
        dist.put(new Line(yl, true), 0);

        /*for(Map.Entry<Line, Integer> me : dist.entrySet()){
            System.out.println(me.getKey().val + ": " + me.getKey().horizontal + ": " + me.getValue());
        }*/
        //System.out.println(dist.containsKey(new Line(xl, false)));
        //System.out.println(dist.get(new Line(xl, false)));

        while(!q.isEmpty()){
            Line curr = q.poll();
            if(curr.val == xb && curr.horizontal == false){
                out.println(dist.get(curr));
                break;
            }
            if(curr.val == yb && curr.horizontal == true){
                out.println(dist.get(curr));
                break;
            }
            Map<Integer, ArrayList<Integer>> dir = curr.horizontal ? ytox : xtoy;
            if(dir.containsKey(curr.val)){
                for(int visit: dir.get(curr.val)){
                    Line newline = new Line(visit, !curr.horizontal);
                    if (!dist.containsKey(newline)) {
                        dist.put(newline, dist.get(curr) + 1);
                        q.add(newline);
                    }
                }
            }
        }
        out.close();
        System.exit(0);
    }

    static class Line {
        private int val;
        private boolean horizontal;

        public Line(int v, boolean h) {
            //super();
            val = v;
            horizontal = h;
        }

        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + (horizontal ? 1231: 1237);
            result = prime * result + val;
            return result;
        }

        @Override
        public boolean equals(Object obj) {
            if(obj == this) return true;
            if(obj == null) return false;
            if(obj.getClass() != this.getClass()) return false;
            Line other = (Line) obj; //cannot do obj (Line obj)
            if(other.val != val) return false;
            if(other.horizontal != horizontal) return false;
            return true;
        }
    }

    /*
    BFS PROBLEMS
    1. Identify by equal state and large amount of inputs
    2. Create the graph which you can bfs or transition from state to state (change the variables etc.)
    3. Implement bfs
     */
}
