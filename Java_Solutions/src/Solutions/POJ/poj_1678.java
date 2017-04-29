package Solutions.POJ;

import java.io.IOException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;


public class poj_1678 {
    static int arr[];
    static HashMap<Integer, Integer> mem;

    public static void main(String[] args) throws IOException {
        //Scanner in = new Scanner(new FileReader("input.in"));
        Scanner in = new Scanner(System.in);
        int testcases = in.nextInt();
        while (testcases-- > 0) {
            int n = in.nextInt();
            int a = in.nextInt();
            int b = in.nextInt();
            mem = new HashMap<Integer, Integer>();
            arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = in.nextInt();
            }
            Arrays.sort(arr);
            int result = Integer.MIN_VALUE;
            for (int i = 0; i < n; i++) {
                if (a <= arr[i] && arr[i] <= b) {
                    result = Math.max(result, dfs(i, a, b));
                }
            }
            if (result == Integer.MIN_VALUE) {
                System.out.println("0");
            } else {
                System.out.println(result);
            }
        }
        in.close();
        System.exit(0);
    }

    static int dfs(int index, int a, int b) {
        if (mem.get(index) != null) {
            return mem.get(index);
        }
        int result = Integer.MIN_VALUE;
        for (int i = index + 1; i < arr.length; i++) {
            if (a + arr[index] <= arr[i] && arr[i] <= b + arr[index]) {
                result = Math.max(dfs(i, a, b), result);
            }
        }
        if (result == Integer.MIN_VALUE) {
            result = arr[index];
        } else {
            result = arr[index] - result;
        }
        mem.put(index, result);
        return result;
    }
}
