package Language;
import java.util.*;
import java.io.*;
/*

 BufferedReader in = new BufferedReader(new FileReader("input.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(in.readLine());

        Always like this...

        For USACO
        change it to FileWriter(File.out)
        For POJ etc.
        change it to FileReader(System.in);

        then at the end change it all to System.in and System.out and move it to solutions...

 */

/*
ALL PATHS ARE RELATIVE
./ is current working directory ... which lies in the java_solutions folder
./src/Java_Solutions/castle.in is how you run it in package
 */

/*
After refactoring
you have to go to run, edit configurations and then change the name too
 */

public class JavaIO { //IOException if an input/output error occurs
    public static void main(String[] args) throws IOException{ ///either throws IOException
        //or use try catch
        /*try {
            //opening file
            File file = new File("input.in");
            boolean succeed = file.createNewFile();
            if (succeed) System.out.println("YAY");


            //appending to file
            File file = new File("input.in");
            if(!file.exists()){
                file.createNewFile();
            }
            FileWriter fw = new FileWriter(file, true);
            BufferedWriter bw = new BufferedWriter(fw);
            bw.write("content");
            bw.close();
        } catch (IOException e) {
            System.out.println("Exception Occurred:");
            e.printStackTrace();
        }*/

        //For system.in and system.out
        /*BufferedReader in = new BufferedReader(new InputStreamReader(System.in)); //replace with System.in
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out))); //Replace with System.out
        StringTokenizer st = new StringTokenizer(in.readLine()); //use in.readLine() and in.nextToken(); */

        //new StringTokenizer(in.readLine());
        //always in.readLine()
        //and then st.nextToken();
        //for input.in and output.out


        //File has to be on the way outside of class created by the PROJECT

        /*BufferedReader in = new BufferedReader(new FileReader("input.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ouput.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        (this works normally maybe package fault)
        //out.println(Integer.parseInt(st.nextToken()));
        //remember st.nextToken()
        //remember Integer.parseInt();
        //remember bufferedRedaer new FileReader
        //remember PrintWriter -> bufferedWriter -> FileWriter
        //String Tokenizer = new StringTokenizer(in.readLine());

        in.close();
        out.close();
        System.exit(0); */

        BufferedReader in = new BufferedReader(new FileReader("Solutions/input.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());

        int n = Integer.parseInt(st.nextToken());
        HashMap<Integer, String> hmap = new HashMap<>();

        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(in.readLine());
            int x = Integer.parseInt(st.nextToken());
            String y = st.nextToken();
            hmap.put(x, y);
        }
        for (Map.Entry<Integer, String> obj: hmap.entrySet()){
            System.out.println(obj.getKey() + " " + obj.getValue());
        }

        out.close();
        in.close();
        //After 1 month learn this https://github.com/lewin/GoogleCodeJam/blob/master/src/arewelostyet.java
    }
}
