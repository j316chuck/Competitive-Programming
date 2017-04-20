package Language;
import java.util.*;
import java.io.*;

public class JavaScanner {
    public static void main(String[] args) throws IOException{
        File file = new File("input.in");
        Scanner in = new Scanner(file);
        PrintWriter out = new PrintWriter(System.out);

        /*while(in.hasNext()) {
            String L = in.next(), U = in.next(); //nextLine() //nextInt();
            out.println(L + U);
        }*/
        /*int n = in.nextInt();
        for (int i = 0; i <= n; i++) {
            System.out.print(in.nextInt() + " ");
        }*/
        //nextInt(), hasNext(), nextDouble()... practice using scanner... for next 10 problems
        //learn cool scanner
        out.close();
    }
}
