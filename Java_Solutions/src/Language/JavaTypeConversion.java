package Language;

public class JavaTypeConversion {
    public static void main(String[] args) {
        //toString easy
        int integer = 6;
        String s = Integer.toString(integer);
        int a = 3;
        char character = (char) (a + 48);
        char c = 'c';
        s = Character.toString(c);

        //parseInt String to Int...
        String str = "0";
        integer = Integer.parseInt(str);
        System.out.println(integer);
        str= "00";
        integer = Integer.parseInt(str);
        System.out.println(integer);
        str = "-1";
        integer = Integer.parseInt(str);
        System.out.println(integer);
        String inf = "asdf"; //any error produces -1
        integer = Integer.parseInt(str);
        System.out.println(integer);
        str = "-2";
        integer = Integer.parseInt(str);
        System.out.println(integer);
        str = "-002";
        integer = Integer.parseInt(str);
        System.out.println(integer); //handles all leading zeros... and negatives... edge case is when it is equal to -1 then error....
        //however good news is that my function has all negatives handled like no edge cases.... only 0000 edge case

        //- + 0000 123 0.000 */
        //handled all edge cases with integers... only edge cases with float 0.000 consider...
        //parseDouble
        str = "0";
        double d = Double.parseDouble(str);
        System.out.println(d);
        str = "00.9";
        d = Double.parseDouble(str);
        System.out.println(d);
        str = "-00.9000";
        d = Double.parseDouble(str);
        System.out.println(d);
        str = "-1.987";
        d = Double.parseDouble(str);
        System.out.println(d);
        str = "asdf"; //throws exception
        try {
            d = Double.parseDouble(str);
        } catch (NumberFormatException e) {
            System.out.println("error");
        }
        System.out.println(d); //d remains same/old value;

    }
}
