package Algorithms;


public class Sorting {
    /*
    Theta N^2
    Very easy idea. Iterate through list and order in terms of small to large
     */
    public static void selection(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            int index = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[index]) {
                    index = j;
                }
            }
            int temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
        }
    }
    public static void merge(int[] arr) {

    }

    public static void quick(int[] arr) {

    }
    public static void heap(int[] arr) {

    }
    public static void insertion(int[] arr) {

    }
    public static void random(int[] arr) {
        for (int i = 0; i < 10; i++) {
            arr[i] = (int) (Math.random() * 10);
        }
    }
    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        int arr[] = new int[10];
        random(arr);
        selection(arr);
        printArray(arr);
        /*random(arr);
        merge(arr);
        printArray(arr);
        random(arr);
        quick(arr);
        printArray(arr);
        random(arr);
        heap(arr);
        printArray(arr);
        random(arr);
        insertion(arr);
        printArray(arr);*/
        System.exit(0);
    }
}
