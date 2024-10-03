// A Simple Implementation Of The Tower Of Hanoi Problem In C

#include <stdio.h>

void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    // Move n-1 disks from source to auxiliary, using destination as temporary
    towerOfHanoi(n - 1, source, auxiliary, destination);

    // Move the nth disk from source to destination
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);

    // Move the n-1 disks from auxiliary to destination, using source as temporary
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main()
{
    int n;
    printf("Enter the no. of Disks: ");
    scanf("%d", &n);

    // A, B, and C are rods
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}
