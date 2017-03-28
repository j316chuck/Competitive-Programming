package Language;

import java.util.regex.*;

public class JavaPatternMatch {
    public static void main(String[] args) {

        /*

        has___ regex = .*(operator) .* used for matches()
        is___ regex = (operator) //used for split and matches() and find() and group()...s
         */
        //.* zero and more before .* zero and more characters after
        String patternString = ".*tutorial.*";
        String content = "This is a tutorial Website!";
        boolean isMatch = Pattern.matches(patternString, content);

        //enabling flags  you don't have to fully memorize everything just know it exists
        //use pattern and matcher to combine into pattern matcher;
        content = "This is a tutorial Website!";
        patternString = ".*tuTorial.*";
        Pattern pattern = Pattern.compile(patternString, Pattern.CASE_INSENSITIVE);
        Matcher matcher = pattern.matcher(content);
        isMatch = matcher.matches();

        //splitting strings...
        String text = "THISISCHAITANYA.ITISMYWEBSITE";
        patternString = "is";
        pattern = Pattern.compile(patternString, Pattern.CASE_INSENSITIVE);
        String[] myStrings = pattern.split(text); //pattern is always what you identify and split by
        //note string arrays have to be String[] not myStrings[];...
        for(String temp: myStrings) {
            System.out.println(temp);
        }
        System.out.println(myStrings.length);

        //matcher class
        //find ... start and end together
        //lookingAt() only beginning of class...
        content = "ZZZ AA PP AA QQQ AAA ZZ";
        String string = "AA";
        pattern = Pattern.compile(string);
        matcher = pattern.matcher(content);
        while(matcher.find()){
            System.out.println("Found at: " + matcher.start() + "-" + matcher.end());
        }


        //String Literal
        boolean match = Pattern.matches("abc", "abc");
        //character classes
        match =  Pattern.matches("[pqr]", "abcd"); //f
        match =  Pattern.matches("[pqr]", "qwe"); //t
        match =  Pattern.matches("[pqr]", "pq"); //f
        /*
        [abc] - any either one of them and only once
        [^abc] - none of them
        [a-zA-Z] a thorugh z, or Solutions.Codeforces.A through Z, inclusive
        [a-d[m-p]] union a-d or m-p]
        [a-z&&[def]] any one of them (d, e, f)
        [a-z&&[^bc]] any a-z except b and c
        [a-z&&[^m-p]] a-z and not m-p
        [a|b] a or b
        */
        //\d = digits \s spaces \w = word \W = nonwords \S nonwhite spaces
        /*
        . -> any character
        \d - a digit: [0-9]
        \D - a nonDigit:
        \s -> a white space character: [\t \n \xoB\f\r]
        \S -> Solutions.Codeforces.A non-white space character [^\s]
        \w -> Solutions.Codeforces.A word Character [a-zA-Z_0-9]
        \W -> Solutions.Codeforces.A non-word character: [^\w]
        must be \\s in string character
         */

        /*
        ^ Matches beginning of line $ = end of line
         */
        //quantifiers
        /*
        X? X?? X?+ Matches x once or not at all
        X+ X+? X++ Matches X one or more times
        X* zero or more times
        X{n} Matches X exactly n times
        X{n,} Matches X at least n times
        X{n, m} Matches X at least n times, but at most n times.
         */
        //.* means anything else zero or more times
        //\\d* means any digits zero or more times;
        //\\w* means any word character 0 or more times.
        //(abc) = group AMEN!!! use pattern matching...

        //(add nothing to function) greedy = start from end and never break of
        //? starts from beginning
        //+ never back off eats everything...

        String str = "(\\d\\d)\1"; // two digits representing same digits
        patternString = "create table (.*)";
        Pattern p = Pattern.compile(patternString);
        //.group(0) = entire expression

        String line = " create table as alphahaha ";

        Pattern p1 = Pattern.compile(".*");
        Matcher m1 = p1.matcher("asdasdf");
        boolean mat = m1.matches();
        "asdas".matches("123");
        while(m1.find()) {
            System.out.println(m1.start() + m1.end());
        }
        //lookingAt = beginning of text
        //http://tutorials.jenkov.com/java-regex/matcher.html
        //http://www.vogella.com/tutorials/JavaRegularExpressions/article.html
    }
}
