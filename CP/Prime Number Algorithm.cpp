//This algorithm checks whether a given number n is prime by attempting to divide it by all integers from 2 up to the square root of n.

#include <iostream>
#include <cmath>

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    
    // Check for factors from 3 to sqrt(n)
    int sqrtN = static_cast<int>(std::sqrt(n));
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0)
            return false;
    }
    
    return true;
}

int main() {
    int number;
    std::cout << "Enter a number to check if it's prime: ";
    std::cin >> number;
    
    if (isPrime(number))
        std::cout << number << " is a prime number.\n";
    else
        std::cout << number << " is not a prime number.\n";
    
    return 0;
}
