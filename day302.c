//Q60: Count positive, negative, and zero elements in an array.

/*
Sample Test Cases:
Input 1:
5
-1 0 1 2 -2
Output 1:
Positive=2, Negative=2, Zero=1

*/
#include <stdio.h>

int main()
{
    int arr[100];          // 1D array
    int n, i;
    int positive = 0, negative = 0, zero = 0;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    // Count positive, negative and zero
    for(i = 0; i < n; i++)
    {
        if(arr[i] > 0)
            positive++;
        else if(arr[i] < 0)
            negative++;
        else
            zero++;
    }
    
    // Display the result
    printf("\nPositive numbers = %d\n", positive);
    printf("Negative numbers = %d\n", negative);
    printf("Zeroes           = %d\n", zero);
    
    return 0;
}