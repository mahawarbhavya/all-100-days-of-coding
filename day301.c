//Q59: Count even and odd numbers in an array.

/*
Sample Test Cases:
Input 1:
6
1 2 3 4 5 6
Output 1:
Even=3, Odd=3

Input 2:
4
2 4 6 8
Output 2:
Even=4, Odd=0

*/
#include <stdio.h>

int main()
{
    int arr[100];        // 1D array
    int n, i;
    int even = 0, odd = 0;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    // Count even and odd numbers
    for(i = 0; i < n; i++)
    {
        if(arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    
    // Print the result
    printf("Total even numbers = %d\n", even);
    printf("Total odd numbers = %d\n", odd);
    
    return 0;
}