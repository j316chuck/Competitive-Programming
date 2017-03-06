package Algorithms;

public class BinarySearch {
    public static void main(String[] args){
        System.out.println(search(new int[]{0}, 1)); //doesn't work... use sketchier BinarySearch lol
    }
    static int search(int[] list, int target){

        int start = 0;
        int end = list.length;
        int index = (start + end)/2;
        // can also do start < end start = index; end = index;
        //most efficient is start + 5 < end... 
        while(start <= end){
            if(list[index] == target) return index;
            else if(list[index] < target) start = index + 1;
            else if(list[index] > target) end = index - 1;
            index = (start + end)/2;
        }
        return -1;
    }
}
