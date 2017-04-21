package Solutions; /**
 * Created by chuck on 4/18/2017.
 */

import java.util.*;
import java.io.*;

public class AutoGrader {

    public static void main(String[] args) {
        String expected = " {name=Starbucks Coffee, lon=-122.280005, id=343610934, lat=37.891484}, {name=Starbucks Coffee, lon=-122.2824219, id=1467717295, lat=37.8288349}, {name=Starbucks Coffee, lon=-122.2095658, id=1580633324, lat=37.8265118}";
        String actual = " {name=Starbucks Coffee, lon=-122.280005, id=343610934, lat=37.891484}, {name=Starbucks Coffee, lon=-122.2824219, id=1467717295, lat=37.8288349}, {name=Starbucks Coffee, lon=-122.2095658, id=1580633324, lat=37.8265118}";
        List<String> expectedList = new ArrayList<String>(Arrays.asList(expected.split(",")));
        List<String> actualList = new ArrayList<String>(Arrays.asList(actual.split(",")));
        HashSet<String> expectedset = new HashSet<>(expectedList);
        HashSet<String> actualset = new HashSet<>(actualList);
        //System.out.println(expectedset);
        for (String s : actualset) {
            if (!expectedset.contains(s)) {
                System.out.println(s);
            }
        }
    }
}
