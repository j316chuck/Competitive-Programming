package Language;

public class JavaInterfaces {
    interface Formula {
        double calculate(int a);

        default double sqrt(int a) {
            return Math.sqrt(a);
        }
    }
    public static void main(String[] args) {
        Formula formula = new Formula() {
            @Override
            public double calculate(int a) {
                return sqrt(a * 100);
            }
        }; //omg that's so cool......
        System.out.println(formula.calculate(3));
    }
}
