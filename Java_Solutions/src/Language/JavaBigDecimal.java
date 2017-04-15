package Language;
import java.math.*;
/**
 * Created by chuck on 4/14/2017.
 */
public class JavaBigDecimal {
    public static void main(String[] args) {
        Double toBeTruncated = new Double("3.5789055");
        Double truncatedDouble = BigDecimal.valueOf(toBeTruncated)
                .setScale(3, RoundingMode.HALF_UP)
                .doubleValue();
        System.out.println(truncatedDouble);
        //divide divisor scale roundingmode;
        BigDecimal a = new BigDecimal("1.23");
        a = a.divide(new BigDecimal("1.11"), 10, RoundingMode.HALF_UP);
        System.out.println(a);

    }
}
