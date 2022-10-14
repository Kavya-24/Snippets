import java.util.Scanner;

class DiffieHellman{
    private static long power(long a, long b, long p)
    {
        if (b == 1)
        return a;
        else
        return (((long)Math.pow(a, b)) % p);
    }
    
    public static void main(String[] args)
    {
        long Q, Alpha, x, a, y, b, ka, kb;
        
        System.out.println("------------------------------DiffiHelman------------------------------------");
        Q = 23;
        System.out.println("The value of Q: " + Q);
        
        System.out.println("-------------------------------------------------------------------------------");
        Alpha = 5;
        System.out.println("The value of Alpha: " + Alpha);
        
        System.out.println("---------------------------------------------------------------------------------");
        
        a = 6;
        System.out.println("The private key a for Alice: " + a);
        
        System.out.println("---------------------------------------------------------------------------------");
        
        x = power(Alpha, a, Q);
        
        b = 15;
        System.out.println("The private key b for Bob: " + b);
        System.out.println("---------------------------------------------------------------------------------");
        
        y = power(Alpha, b, Q);
        
        
        ka = power(y, a, Q); // Secret key for Alice
        kb = power(x, b, Q); // Secret key for Bob
        
        System.out.println("Secret key for the Alice is: " + ka);
        System.out.println("Secret key for the Bob is: " + kb);
        System.out.println("---------------------------------------------------------------------------------");
    }
    
}