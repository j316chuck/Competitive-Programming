package Algorithms;

import java.util.ArrayList;
import java.util.List;

public class AdjacencyList {

    public static List<Integer>[] G; //G has to be a static variable....

    /*static void InitAdjacentList(int n, List<Integer>[] adj) {
        G = (List<Integer>[]) new List[n]; //nice meme... List<Integer>[] adj = (List<Integer>[]) new List[n]
        for(int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
        }
    }*/ //function doesn't work because you set it to new list... need a new class...

    public static void main(String[] args){  //you need public static void main

        //InitAdjacentList(3, G); //G has to be a static variable
        G = (List<Integer>[]) new List[3]; //nice meme... List<Integer>[] adj = (List<Integer>[]) new List[n]
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
        for(int i = 0; i < 3; i++){
            System.out.println(G[i]);
        }
    }
}
