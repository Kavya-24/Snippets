import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'kaprekarNumbers' function below.
     *
     * The function accepts following parameters:
     *  1. INTEGER p
     *  2. INTEGER q
     */

    public static void kaprekarNumbers(int p, int q) {
    // Write your code here
    int count=0;
    for(int i=p;i<=q;i++) {
        if(i == 1) {
            System.out.print(1+" ");
        }
        else if(i < 4) {
            continue;
        }
        else {
            long j = (long)i*i;
            Long ff = j;
            String c = ff.toString();
            String f = c.substring(0,(c.length()/2));
            String s = c.substring((c.length()/2));
            long k = Long.parseLong(f);
            long l = Long.parseLong(s);
            
            if((k+l) == i) {
                System.out.print(i+" ");
                count++;
            }
            
        }
    }
    if(count == 0) {
        System.out.println("INVALID RANGE");
    }

    }

}

public class Modified_Kaprekar_Number {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int p = Integer.parseInt(bufferedReader.readLine().trim());

        int q = Integer.parseInt(bufferedReader.readLine().trim());

        Result.kaprekarNumbers(p, q);

        bufferedReader.close();
    }
}
