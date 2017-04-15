package Language;
import java.util.*;

public class JavaStringBuilder {
    public static void main(String[] args) {
        StringBuilder s = new StringBuilder("hello");
        s.append(1);
        s.append(true);
        System.out.println(s.charAt(6));
        s.insert(6, 12);
        System.out.println(s);
        System.out.println(s.substring(3, 8));
        //reverse, length insert, append, replace,  charAt
    }
}
