//Q57: Find the sum of array elements.

/*
Sample Test Cases:
Input 1:
4
2 4 6 8
Output 1:
20

Input 2:
3
1 1 1
Output 2:
3

*/
#include <stdio.h>

int main()
{
    int arr[100];     // 1D array declaration
    int n, i;
    int sum = 0;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Reading array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    // Calculating sum of array elements
    for(i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    
    // Printing the result
    printf("Sum of all array elements = %d\n", sum);
    
    return 0;
}