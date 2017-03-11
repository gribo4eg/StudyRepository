package Part1;

import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.io.*;

public class Main {

    public static class ReadFile{

        private static void exist(String path) throws FileNotFoundException {
            File file = new File(path);
            if (!file.exists()) throw new FileNotFoundException(file.getName());
        }

        public static LinkedList<String> getWordsFromFile(String path) throws IOException{

            exist(path);

            File file = new File(path);

            String s;
            LinkedList<String> text = new LinkedList();

            FileReader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);

            while ((s = br.readLine()) != null)
                text.add(s);

            br.close();
            fr.close();

            return text;
        }

        public static String getTextFromFile(String path) throws IOException{
            exist(path);

            File file = new File(path);
            String s;
            String text ="";

            FileReader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);

            while((s = br.readLine()) != null)
                text += s;

            br.close();
            fr.close();

            return text;
        }
    }

    public static void main(String[] args) throws IOException{
        final String REG_EXP =
                "<[+-][P-Z0-5]+>";
        final String WORDS_PATH =
                "C:\\Repository\\JavaLabs\\Lab1_2_2\\src\\Part1\\words.txt";
        final String TEXT_PATH =
                "C:\\Repository\\JavaLabs\\Lab1_2_2\\src\\Part1\\text.txt";
        Pattern pattern = Pattern.compile(REG_EXP);
        Matcher matcher;
        LinkedList words = ReadFile.getWordsFromFile(WORDS_PATH);

        System.out.println("Task #1.\nMatches:\n");
        //P Q R S T U V W X Y Z
        for (Object s : words) {
            matcher = pattern.matcher((String)s);
            if(matcher.matches())
                System.out.println("Line: "+(words.indexOf(s)+1)+" Word: "+s);
        }

        String text = ReadFile.getTextFromFile(TEXT_PATH);

        matcher = pattern.matcher(text);
        System.out.println("\nTask #2.\nMatches:\n");
        while(matcher.find())
            System.out.println("Begin: " +matcher.start()+" End: "+matcher.end()+" Word: "+matcher.group());
    }
}
