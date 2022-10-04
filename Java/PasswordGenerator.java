import java.util.Random;

public class Main {
    public static void main(String[] args) {

        System.out.println("Password Generated :");

        System.out.println(passwordGenerator(10));

    }

    public static char[] passwordGenerator(int len){
        String values = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*_=+-/.?<>)";
        Random random = new Random();
        char[] password = new char[len];

        for(int i=0; i<10; i++){
             password[i] = values.charAt(random.nextInt(values.length()));
        }
        return password;
    }
}