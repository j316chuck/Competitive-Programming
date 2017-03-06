package Language;
import java.util.*;
import java.io.*;

public class JavaScanner {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        while(in.hasNext()) {
            String L = in.next(), U = in.next(); //nextLine() //nextInt();
            out.println(L + U);
        }
        //learn cool scanner
    }
}
