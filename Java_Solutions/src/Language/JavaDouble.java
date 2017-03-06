package Language;

public class JavaDouble {
    public static void main(String[] args) {

        System.out.printf("%.3f\n", 0.000);
        System.out.printf("%.3f\n", (double) 0);
        System.out.printf("'%5d'", 10);   //'  10'
        System.out.printf("'%-5d'", 10); //'10   '
        System.out.printf("'%05d'", 10); //'00010'
        System.out.printf("'%+5d'", 10); //with plus sign '   +10'
        System.out.printf("'%0+5d\n'", 10); //'+10   '

        //99% of the time I will use this!!! 99% of time I will use printf and format
        double d = 1.2;
        String s = String.format("%.3f", d);
        System.out.println(s);
        d = -1.213;
        s = String.format("%.3f", d);
        System.out.println(s);
        d = 000.0;
        s = String.format("%.3f", d);
        System.out.println(s);
        d = -000.1234;
        s = String.format("%.3f", d);
        System.out.println(s);

        s = "asd";
        System.out.println(s.toString());
        d = 1.0/2;
        System.out.println(d);
        d = Math.floor(d);
        System.out.println(d);
        Double d1 = d;
        System.out.println(d1.toString());

        d1 = 0.0/0;
        String s1 = d1.toString();
        System.out.println(s1);
        d1 = Double.parseDouble(s1);
        System.out.println(d1);
    }
}
