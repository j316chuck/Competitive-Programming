package Solutions.Berkeley;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class InputProblem {

    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        //Scanner in = new Scanner(System.in); probably need to uncomment this
        //Scanner in = new Scanner(new FileReader("input.in"));

        int caseNumber = 1;
        int minimumDifference = Integer.MAX_VALUE;
        ArrayList<Integer> differences = new ArrayList<Integer>();
        String s;
        while ((s = in.readLine()) != null) {
            if (s.isEmpty()) { //we hit an entirely empty line so we have to calculate the results and reset the values
                long total = 0;
                for (int i = 0; i < differences.size(); i++) {
                    total += differences.get(i) - minimumDifference;
                }
                System.out.println("Image " + caseNumber + ": " + total);

                //resetting the values
                caseNumber += 1;
                minimumDifference = Integer.MAX_VALUE;
                differences = new ArrayList<Integer>();
            } else {
                int whiteSpace = 0;
                s.trim();
                for (int i = 0; i < s.length(); i++) {
                    if (s.charAt(i) == ' ') {
                        whiteSpace++;
                    }
                }
                minimumDifference = Math.min(minimumDifference, whiteSpace);
                differences.add(whiteSpace);
            }
        }

        //evaluating the last case
        long total = 0;
        for (int i = 0; i < differences.size(); i++) {
            total += differences.get(i) - minimumDifference;
        }
        System.out.println("Image " + caseNumber + ": " + total);
        caseNumber += 1;
        minimumDifference = Integer.MAX_VALUE;
        differences = new ArrayList<Integer>();

        in.close();
        System.exit(0);
    }

}

