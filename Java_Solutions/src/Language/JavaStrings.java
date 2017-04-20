package Language;

public class JavaStrings {
    public static void main(String[] args) {
        String str = "   1create1 \n";
        str = str.trim();
        System.out.println(str);
        str = "12create13";
        System.out.println(str.matches("(\\d\\d)create\\1"));//no spaces inclusive
        //parentheses cannot be used inside character classes //backreference is needlessescape
        //parentheses cannot be used around \1 also it has to be \\1
        // \\1 represents the 12 12 so 12 13 is wrong
        str = "asd Asd asd as    da asd asd ";
        // \\s means any string you split...
        // how do we do any number of strings... [
        String[] arr = str.split("\\s");
        for(String s: arr) System.out.println(s);
        int a = 1;
        String fs = String.format("The value of the float " + "variable is %d", a);
        String last = "asdf >= asdfasdf";
        System.out.println(last.lastIndexOf(">= "));
        System.out.println(last.indexOf(">= "));
        Double d = Double.parseDouble("1");
        System.out.println(d);
        System.out.println("".compareTo("1"));
        System.out.println(d.toString());
        arr = "123".split(","); //because . is special character
        for(String s: arr)
            System.out.println(s);
        System.out.println("one".compareTo("two"));

        String s = "asdf \n asldfkjdfkls \nasldfjkadfs \nlasdfjdas \n";
        arr = s.split("\\s*\\n\\s*");
        for(String b: arr) System.out.println(b);

        d = 0.0/0.0;
        if(d.toString().equals("NaN")) {
            System.out.println("1");
        }
        s = "'asd'";
        System.out.println(s.substring(1, s.length()-1));
        s = "NaN";
        Double d1 = -1.0;
        Double d2 = 0.0;
        System.out.println(d1.compareTo(d2));
        System.out.println(d1);
        s = "hello"; //java strings are immutable
        //regex vs strings
        //find() = part of string... matches() = whole string..
        //indexOf vs find() and start() and end();
        //both can use split("");
        //matches... find()... group()..split();
        //.replace();
        s = "Hello ^ ! Special Characters .... - ' will be removed";
        String s1 = s.replaceAll("[^A-Za-z]", "").toLowerCase();
        System.out.println(s1);
    }
}
