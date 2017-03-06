package Algorithms;

import java.util.*;
import java.io.*;
//can do O(V^2) algorithm with adjacency matrix;
//Note O(E + V) runtime with just adjacency list
//has to be directed acyclic graph
public class TopologicalSort {

    static boolean AdjacencyMatrix(int w[][], ArrayList<Integer> order){
        int n = w.length;
        int parent[] = new int[n];
        LinkedList<Integer> q = new LinkedList<Integer>();
        order.clear();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(w[j][i] == 1){ //w[j][i] if(anything comes before i);
                    parent[i]++;
                } //nice can't just read must implement;
            }
            if(parent[i] == 0)
                q.push(i);
        }
        //basically the USACO problem of topological sorting...

        while(!q.isEmpty()){
            int top = q.poll();
            order.add(top);
            for(int i = 0; i < n; i++) {
                if(w[top][i] == 1) { //key mistake!!!!
                    parent[i]-=1;
                    if(parent[i] == 0) {
                        q.offer(i);
                    }
                }
            }
        }
        return order.size() == n;
    }

    static void InitAdjacentList(int n, List<Integer>[] adj) {
        adj = (List<Integer>[])new List[n]; //nice meme... List<Integer>[] adj = (List<Integer>[]) new List[n]
        for(int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
        }
    }

    public static void main(String[] args) {
        ArrayList<Integer> order = new ArrayList<Integer>();
        int w[][] = new int[][]{
                {0, 1, 1},
                {0, 0, 1},
                {0, 0, 0}
        };
        AdjacencyMatrix(w, order);
        System.out.println(order);

        HashMap<Integer, ArrayList<Integer>> mp = new HashMap<Integer, ArrayList<Integer>> ();
        //HashMap for adjacency matrix in java.
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++) {
                if(!mp.containsKey(i))
                    mp.put(i, new ArrayList<Integer>());
                mp.get(i).add(i < j ? 1 : 0);
            } //mp is from i to j...
        }

        //Better way = adjacencyList
        List<Integer> G[] = (List<Integer>[]) new List[3]; //nice meme... List<Integer>[] adj = (List<Integer>[]) new List[n]
        for(int i = 0; i < 3; i++) {
            G[i] = new ArrayList<Integer>();
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i < j){
                    G[i].add(j);
                }
            }
        }

        LinkedList<Integer> q = new LinkedList<Integer>();
        int parent[] = new int[G.length];
        for(int i = 0; i < G.length; i++){
            for(int j = 0; j < G[i].size(); j++){
                int visit = G[i].get(j);
                parent[visit]++;
            }
        }
        for(int i = 0; i < G.length; i++){
            if(parent[i] == 0){
                q.add(i);
            }
        }
        order.clear();

        //Algorithm using maps!!!
        while(!q.isEmpty()){
            int top = q.poll();
            order.add(top);
            for(int i = 0; i < G[top].size(); i++){
                int visit = G[top].get(i);
                parent[visit]--;
                if(parent[visit] == 0){
                    q.offer(visit);
                }
            }
        }
        System.out.println(order);

        //dfs topological sort
        int n = 3;
        List<Integer>[] g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        g[2].add(0);
        g[2].add(1);
        g[0].add(1);

        List<Integer> res = topologicalSort(g);
        System.out.println(res);
    }

    //https://sites.google.com/site/indy256/algo/topological_sorting
    //topological sort with dfs
    static void dfs(List<Integer>[] graph, boolean[] used, List<Integer> res, int u) {
        used[u] = true;
        for (int v : graph[u])
            if (!used[v])
                dfs(graph, used, res, v);
        res.add(u);
    }

    public static List<Integer> topologicalSort(List<Integer>[] graph) {
        int n = graph.length;
        boolean[] used = new boolean[n];
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; i++)
            if (!used[i])
                dfs(graph, used, res, i);
        Collections.reverse(res);
        return res;
    }

}
