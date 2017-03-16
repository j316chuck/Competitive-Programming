package Algorithms;

import java.io.*;
import java.util.*;

public class Graph2 {
    private static class Edge {
        int to;
        int next;
        Edge(int to, int next) {
            this.to = to;
            this.next = next;
        }
    }
    private static int index = 0;
    private static int rst = 0;

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int nodeNum = Integer.parseInt(st.nextToken());
        int edgeNum = Integer.parseInt(st.nextToken());
        Edge[] edges = new Edge[nodeNum * (nodeNum - 1)];
        int[] nodes = new int[nodeNum + 1];
        boolean[][] vis = new boolean[nodeNum + 1][nodeNum + 1];
        Arrays.fill(nodes, -1);
        for (int i = 0; i < edges.length; ++i) {
            edges[i] = new Edge(0, 0);
        }
        index = 0;
        for (int i = 1; i <= edgeNum; ++i) {
            st = new StringTokenizer(in.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            addEdge(nodes, edges, u, v);
        }
        for (int i = 1; i <= nodeNum; ++i) {
            bfs(nodes, edges, vis, i);
        }
        System.out.println((nodeNum * (nodeNum - 1) / 2) - rst);
    }

    private static void addEdge(int[] nodes, Edge[] edges, int u, int v) {
        edges[index].to = v;
        edges[index].next = nodes[u];
        nodes[u] = index++;
    }

    private static void bfs(int[] nodes, Edge[] edges, boolean[][] vis, int index) {
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.offer(index);
        while (!queue.isEmpty()) {
            int u = queue.poll();
            for (int k = nodes[u]; k != -1; k = edges[k].next) {
                int v = edges[k].to;
                if (!vis[index][v]) {
                    vis[index][v] = true;
                    ++rst;
                    queue.offer(v);
                    if (u != index) {
                        addEdge(nodes, edges, index, v);
                    }
                }
            }
        }
    }

}
