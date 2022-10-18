package lab1;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class MultiplicativeCipher {
    private static String decryptNewCipher(int decryption_key,char [] chars,String [] arr){
        ArrayList<String> plainList=new ArrayList<>();
        String plainText="";
        for(String i:arr){
            String convert=i.toLowerCase();
            String ans="";
            for(char ch:convert.toCharArray()){
                int temp=((ch-'a')*map.get(decryption_key))%26;
                ans+=chars[temp];
            }
            plainList.add(ans);
        }
        for(String i:plainList){
            plainText+=i+" ";
        }
        return plainText.trim();
    }
    private static boolean checkCipher(String [] array){
        int count=0;
        for(String i:array){
            if(isContainOtherThanUpperCase(i)){
                count++;
            }
        }
        return count>0;
    }
    private static boolean isContainOtherThanUpperCase(String cipher){
        Pattern pat=Pattern.compile("[^A-Z]");
        Matcher mat= pat.matcher(cipher);
        return mat.find();
    }
    static ArrayList<String> enryptionList=new ArrayList<>();
    static ArrayList<Integer> domain=new ArrayList<>();
    private static int bruteForce(char [] chars,String plain){
        HashMap<Integer,String> bruteforcemap=new HashMap<>();
        for(int i:domain){
            String temp=decryption(i,chars).trim();
            bruteforcemap.put(i,temp);
        }
        int ans=0;
        for (int key: bruteforcemap.keySet()){
            String temp=bruteforcemap.get(key);
            if(plain.equals(temp)){
                ans=key;
            }
        }
        return ans;
    }
    private static String encryption(String [] array,int encryption_key,char [] chars){
        String encryptedCipher="";
        for(String i:array){
            ArrayList<Integer> clist=new ArrayList<>();
            for(char ch:i.toCharArray()){
                int temp=((ch-'a')*encryption_key)%26;
                clist.add(temp);
            }
            String s="";
            for(int j:clist){
                s+=chars[j];
            }
            enryptionList.add(s);
        }
        for(int i=0;i<enryptionList.size();i++){
            encryptedCipher+=enryptionList.get(i)+" ";
        }
        return encryptedCipher.trim();
    }
    private static String decryption(int decryption_key,char[] chars){
        ArrayList<String> plainList=new ArrayList<>();
        String plaintext="";
        for(String i:enryptionList){
            String convert=i.toLowerCase();
            String ans="";
            for(char ch:convert.toCharArray()){
                int temp=((ch-'a')*map.get(decryption_key))%26;
                ans+=chars[temp];
            }
            plainList.add(ans);
        }
        for(String i:plainList){
            plaintext+=i+" ";
        }
        return plaintext.trim();
    }

    private static void showDetails(){
        System.out.println("1.Encryption");
        System.out.println("2.Decryption");
        System.out.println("3.Brute Force Attack");
        System.out.println("4.Exit");
    }
    private static boolean isContainsOtherCharacters(String plain){
        Pattern pattern = Pattern.compile("[^a-z]");
        Matcher matcher = pattern.matcher(plain);
        return matcher.find();
    }
    private static boolean checkForSpecialCharactersOtherThanSpaces(String [] array){
        int count=0;
        for(String i:array){
            if(isContainsOtherCharacters(i)){
                count++;
            }
        }
        return count>0;
    }
    static HashMap<Integer,Integer> map=new HashMap<>();
    private static void modInverse(int a, int m)
    {
        for (int x = 1; x < m; x++)
            if (((a%m) * (x%m)) % m == 1)
                map.put(a,x);
    }
    private static boolean comparePlainWithCipherUsingKey(int key,char [] chars,String plain){
        System.out.println("Decrypted Plain Text:- "+decryption(key,chars));
        return plain.equals(decryption(key,chars));
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("<---Multiplicative Cipher System--->");
        showDetails();
        System.out.println("Enter the plain text:-");
        String plain=sc.nextLine();
        String [] arrayOfplain=plain.split(" ");
        while(checkForSpecialCharactersOtherThanSpaces(arrayOfplain)){
            System.out.println("Re-enter Plain Text");
            plain=sc.nextLine();
            arrayOfplain=plain.split(" ");
        }
        System.out.println("Enter your choice:-");
        int choice=sc.nextInt();
        char [] chars=new char[26];
        for(int i=0;i<26;i++){
            chars[i]= (char) ('a'+i);
        }
        String cipher="";
        for(int i=1;i<=26;i++){
            modInverse(i,26);
        }
        Set<Integer> keyDomain=map.keySet();
        for(int i:keyDomain) domain.add(i);
        while(true){
            if(choice==1){
                System.out.println("<--Encryption Phase-->");
                System.out.println("Enter Encryption Key");
                int encrypt_key=sc.nextInt();
                if(encrypt_key>26){
                    encrypt_key=encrypt_key%26;
                }
                while(!keyDomain.contains(encrypt_key)){
                    System.out.println("Please Enter valid key:-");
                    encrypt_key=sc.nextInt();
                }
                cipher=encryption(arrayOfplain,encrypt_key,chars).toUpperCase();
                System.out.println("Encrypted Cipher Text:- "+cipher);
                showDetails();
                System.out.println("Enter your choice:-");
                choice=sc.nextInt();

            }
            if(choice==2){
                System.out.println("<--Decryption Phase-->");
                System.out.println("Do you want to decrypt the previous encrypted text enter choice 1 or 2");
                int ch=sc.nextInt();
                if(ch==1){
                    System.out.println("Enter Decryption Key");
                    int decrypt_key=sc.nextInt();
                    if(comparePlainWithCipherUsingKey(decrypt_key,chars,plain)){
                        System.out.println("Plain Text Matched Successfully:-");
                    }
                    else {
                        System.out.println("No Match! Try Brute Force!!");
                    }
                }
                if(ch==2){
                    Scanner scn=new Scanner(System.in).useDelimiter("\n");
                    System.out.println("Enter CipherText:-");
                    String ci=scn.next();
                    String [] arr=ci.split(" ");
                    while(checkCipher(arr)){
                        System.out.println("Re-enter Cipher Text");
                        ci=scn.next();
                        arr=ci.split(" ");
                    }
                    System.out.println("Enter Decryption key:-");
                    int dkey=sc.nextInt();
                    String pl=decryptNewCipher(dkey,chars,arr);
                    System.out.println(pl);
                    if(plain.equals(pl)){
                        System.out.println("Congrats decryption done successfully:-"+pl);
                    }
                    else{
                        System.out.println("Try Brute Force");
                    }
                }
                showDetails();
                System.out.println("Enter your choice:-");
                choice=sc.nextInt();
            }
            if(choice==3){
                System.out.println("Brute Force Attack");
                int encrypted=bruteForce(chars,plain);
                System.out.println("Congrats we successfully crack encryption key:- "+encrypted);
                System.out.println("Now Perform decryption to get plain text.");
                System.out.println("Decryption Starting---->");
                System.out.println("Original Plain Text:- "+decryption(encrypted,chars));
                showDetails();
                System.out.println("Enter your choice");
                choice=sc.nextInt();
            }
            if(choice==4){
                System.exit(0);
            }
        }
    }
}
