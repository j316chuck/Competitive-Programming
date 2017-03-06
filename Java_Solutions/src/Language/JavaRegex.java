package Language;
import java.util.regex.*;

public class JavaRegex {
    public static void main(String[] args){
        String REST = "\\s*(.*)\\s*";
        Pattern CREATE_CMD = Pattern.compile("create\\s*table" + REST);
        Matcher m = (CREATE_CMD.matcher("create table adklsjasd asdasd adsasd"));
        if(m.matches()){
            System.out.println(m.group(1));
        }else{
            System.out.println(m.matches());
        }

        String URL = "hEllo";
        Pattern pattern = Pattern.compile("^[a-zA-Z]\\w+");
        Matcher matcher = pattern.matcher(URL);
        if(matcher.matches()){
            System.out.println(matcher.group(0));
        }
    }
}
