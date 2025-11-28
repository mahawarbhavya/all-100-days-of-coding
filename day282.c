//Q56: Read and print elements of a one-dimensional array.

/*
Sample Test Cases:
Input 1:
3
10 20 30
Output 1:
10 20 30

Input 2:
5
1 2 3 4 5
Output 2:
1 2 3 4 5

*/
#include <stdio.h>

int main()
{
    int n, i, j;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    int num[1005];     // 1D array to store numbers from 2 to n
    int prime[1005];   // 1D array to mark prime (1) or not prime (0)
    
    // Step 1: Fill num[] with numbers from 2 to n
    for(i = 2; i <= n; i++)
    {
        num[i] = i;
        prime[i] = 1;     // Assume all are prime initially
    }
    
    // Step 2: Sieve method using array
    for(i = 2; i * i <= n; i++)
    {
        if(prime[i] == 1)  // If i is prime
        {
            for(j = i * i; j <= n; j = j + i)
            {
                prime[j] = 0;  // Mark multiples of i as not prime
            }
        }
    }
    
    // Step 3: Print all numbers where prime[index] == 1
    printf("Prime numbers from 1 to %d are:\n", n);
    
    for(i = 2; i <= n; i++)
    {
        if(prime[i] == 1)
        {
            printf("%d ", num[i]);
        }
    }
    
    printf("\n");
    
    return 0;
}