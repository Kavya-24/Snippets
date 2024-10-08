#include <stdio.h>

// Recursive function to calculate the sum of digits
int sumOfDigits(int num) {
    if (num == 0)
        return 0;
    return (num % 10) + sumOfDigits(num / 10);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int result = sumOfDigits(num);
    printf("The sum of the digits of %d is: %d\n", num, result);

    return 0;
}
