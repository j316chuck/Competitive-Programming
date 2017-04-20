package Language;

/**
 * Created by chuck on 4/5/2017.
 */
public class JavaExceptions {

    public static void main(String[] args) {
        int arr[] = new int[5];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = i;
        }
        try {
            for (int i = 0; i < 10; i++) {
                arr[i] += 1;
            }
        } catch (RuntimeException e){
            System.out.println("hello");
            for (int i = 0; i < 10; i++) {
                arr[i] += 1;
            }
        } catch (Exception e) {
            System.out.println("hello");
        } finally {
            System.out.println("hi");
            for (int i = 0; i < 10; i++) {
                arr[i] += 1;
            }
        }
    }
}
