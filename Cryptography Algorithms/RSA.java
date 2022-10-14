import java.util.Scanner;

import javax.print.attribute.standard.PrinterLocation;

class RSA {

    static int enc(int m, int e, int p, int q) {
        // To encrypt
        // m-> message
        // e-> public key
        // p, q -> prime numbers

        int n = p * q;
        int c = (int) (Math.pow(m, e) % n);
        return c;

    }

    static int dec(int c, int d, int n) {
        // To decrypt
        // d-> private key
        // c -> encrypted msg
        
        int m = (int) (Math.pow(c, d) % n );
        return m;

    }

   static int extEu(int a, int b) {
       for (int x = 1; x < b; x++) 
           if(( (a % b) * (x % b) ) % b == 1){
               return x;
           }
           return 1;

   }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = 5;
        int p = 3;
        int q = 11;
        int e = 7;
        int n = (p * q);

        int phi = (p - 1) * (q - 1);

        int x, y;
        x = 1; y = 1;
        System.out.println("==============================RSA===========================");
        System.out.println("Original Message: "+m);
        int ctxt = enc(m, e, p, q);
        System.out.println("Encrypted Text: " + ctxt);


        int d = extEu(e, phi);
        System.out.println("Extended Euclidean Value: "+d);

        int mtxt = dec(ctxt, d, n);

        System.out.println("Decrypted Text: " + mtxt);
        System.out.println("============================================================");
    }
    
}