import java.util.ArrayList;
import java.util.Scanner;

public class AutoKeyChiper {
    private static final String alphabet = "abcdefghijklmnopqrstuvwxyz";
    private static final String alphabet1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in).useDelimiter("\n");
        int loop1=1;
        while (loop1==1) {
            System.out.println("1 FOR ENCRYPTION:");
            System.out.println("2 FOR DECRYPTION:");
            System.out.println("3 FOR BRUTEFORCE:");
            System.out.println("Other Key FOR EXIT:");
            String key = "";
            String pt = "";
            String pt1 = "";
            String k11 = "";
            String ptd="";
            int f = 0;
            int k = 0;
            int c = sc.nextInt();
            boolean result = false;
            ArrayList<Integer> spaces = new ArrayList<>();

            switch (c) {
                case 1:
                    while (!result) {
                        System.out.println("ENTER Plaintext : ");
                        pt = sc.next();
                        pt1 = pt;
                        pt = pt.replaceAll("\\s+", "");
                        result = pt.matches("[a-z]+");
                        if (result == false)
                            System.out.println("ENTER CORRECT STRING::");
                    }
                    for (int i = 0; i < pt1.length(); i++) {
                        if (pt1.charAt(i) == ' ') spaces.add(i);
                    }
                    while (f == 0) {
                        System.out.println("ENTER KEY : ");
                        k11 = sc.next();
                        result = k11.matches("[0-9]+");
                        if (result == false)
                            System.out.println("ENTER CORRECT KEY::");
                        else
                            f = 1;
                    }
                    k = Integer.parseInt(k11);
                    k = k % 26;
                    key += alphabet.charAt(k);
                    String enc = autoEncryption(pt, key);
                    String enc1 = "";
                    int cc = 0;
                    StringBuffer str = new StringBuffer(enc);
                    for (int i = 0; i < pt1.length(); i++) {
                        for (int j = 0; j < spaces.size(); j++) {
                            if (spaces.get(j) == i) {
                                str.insert(i, ' ');
                            }
                        }

                    }
                    enc1 = str.toString();
                    System.out.println("Plaintext : " + pt1);
                    System.out.println("Encrypted : " + enc1);
                    break;
                case 2:
                    boolean result11 = false;
                    while (!result11) {
                        System.out.println("ENTER Encrypted : ");
                        ptd = sc.next();
                        pt1 = ptd;
                        ptd = ptd.replaceAll("\\s+", "");
                        result11 = ptd.matches("[A-Z]+");
                        if (result11 == false)
                            System.out.println("ENTER CORRECT STRING En::");
                    }
                    for (int i = 0; i < pt1.length(); i++) {
                        if (pt1.charAt(i) == ' ') spaces.add(i);
                    }
                    for(int i=0;i<ptd.length();i++){
                        int p1=alphabet1.indexOf(ptd.charAt(i));
                        pt+=alphabet.charAt(p1);
                    }
                    while (f == 0) {
                        System.out.println("ENTER KEY : ");
                        k11 = sc.next();
                        result11 = k11.matches("[0-9]+");
                        if (result11 == false)
                            System.out.println("ENTER CORRECT KEY::");
                        else
                            f = 1;
                    }
                    k = Integer.parseInt(k11);
                    k = k % 26;
                    key += alphabet.charAt(k);
                    String dec = autoDecryption(pt, key);
                    StringBuffer str1 = new StringBuffer(dec);
                    for (int i = 0; i < pt1.length(); i++) {
                        for (int j = 0; j < spaces.size(); j++) {
                            if (spaces.get(j) == i) {
                                str1.insert(i, ' ');
                            }
                        }

                    }
                    enc1 = str1.toString();
                    System.out.println("Encrypted : " + pt1);
                    System.out.println("Decrypted : " + enc1);
                    break;
                case 3:

                    String ciptext = "";
                    String ciptext1 = "";
                    boolean ctresult = false;
                    boolean outerloop = false;
                    while (!outerloop) {
                        result = false;
                        ctresult = false;
                        while (!result) {
                            System.out.println("ENTER Plaintext : ");
                            pt = sc.next();
                            pt1 = pt;
                            pt = pt.replaceAll("\\s+", "");
                            result = pt.matches("[a-z]+");
                            if (result == false)
                                System.out.println("ENTER CORRECT STRING::");
                        }
                        while (!ctresult) {
                            System.out.println("ENTER Ciphertext : ");
                            ciptext = sc.next();
                            ciptext1 = ciptext;
                            ciptext = ciptext.replaceAll("\\s+", "");
                            ctresult = ciptext.matches("[A-Z]+");
                            if (ctresult == false)
                                System.out.println("ENTER CORRECT STRING::");
                        }
                        int flag = 1;
                        if (ciptext1.length() != pt1.length()) {
                            System.out.println("Length of both are not same");
                            flag = 0;
                        }
                        int flagC = 1;
                        if (flag == 1) {
                            for (int i = 0; i < pt1.length(); i++) {
                                if (pt1.charAt(i) == ' ') {
                                    if (ciptext1.charAt(i) == ' ') {

                                    } else {
                                        flagC = 0;
                                    }
                                }
                            }
                        }
                        if (flagC == 0) {
                            System.out.println("Spaces are not equal or at same place");
                        }
                        if (flagC == 1 && flag == 1) {
                            outerloop = true;
                        }
                    }
                    String Encr = "";
                    String keyBrute = "";
                    int flag1 = 0;
                    for (int i = 0; i < 26; i++) {
                        keyBrute += alphabet.charAt(i);
                        Encr = autoEncryption(pt, keyBrute);
                        //System.out.println("KEY:"+i+"  "+Encr);
                        if (Encr.equals(ciptext)) {
                            System.out.println("FOUND Key:" + i);
                            flag1 = 1;
                            break;
                        }
                        keyBrute = "";
                        Encr = "";
                    }
                    if (flag1 == 0)
                        System.out.println("NO RESULT FOUND");
                    break;
                default:
                    System.out.println("EXIT:");
            }
            System.out.println("For Continue Press 1");
            System.out.println("For Exit Press Any Key");
            loop1=sc.nextInt();
        }

    }

    public static String autoEncryption(String msg, String key)
    {
        int len = msg.length();
        String newkey=key.concat(msg);
        newkey=newkey.substring(0,newkey.length()-key.length());
        String encryptMsg = "";
        for(int i=0;i<len;i++){
            int p1=alphabet.indexOf(msg.charAt(i));
            int n1=alphabet.indexOf(newkey.charAt(i));
            int total = (p1 + n1) % 26;
            encryptMsg += alphabet1.charAt(total);
        }
        return encryptMsg;
    }


    public static String autoDecryption(String msg, String key)
    {
        String currentKey = key;
        String decryptMsg = "";
        for (int x = 0; x < msg.length(); x++) {
            int get1 = alphabet.indexOf(msg.charAt(x));
            int get2 = alphabet.indexOf(currentKey.charAt(x));
            int total = (get1 - get2) % 26;
            total = (total < 0) ? total + 26 : total;
            decryptMsg += alphabet.charAt(total);
            currentKey += alphabet.charAt(total);
        }
        return decryptMsg;
    }
}

