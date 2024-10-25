import javax.swing.text.html.parser.Entity;
import java.util.*;
public class LearnHashMap
{
    public static void main(String[] args) {
        Map<String,Integer> numbers = new HashMap<>();
        numbers.put("one",1);
        numbers.put("five",5);
        numbers.put("two",2);
        numbers.put("three",3);

        //numbers.put("two",22); ------> override the old value
        //numbers.putIfAbsent("two",22);

        System.out.println(numbers);
        for(Map.Entry<String,Integer> e: numbers.entrySet()){
            System.out.println(e);
        }
//        for(Map.Entry<String,Integer> e: numbers.entrySet()){
//            System.out.println(e.getKey());
//            System.out.println(e.getValue());
//        }
        for(String key: numbers.keySet()){
            System.out.println(key);
        }
        System.out.println(numbers.containsKey("one"));

        numbers.replace("one",1,11);
        System.out.println(numbers);
    }
}
