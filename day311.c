//Q61: Search for an element in an array using linear search.

/*
Sample Test Cases:
Input 1:
5
1 2 3 4 5
3
Output 1:
Found at index 2

Input 2:
4
10 20 30 40
25
Output 2:
-1

*/
#include <stdio.h>

int main()
{
    int arr[100];        // 1D array
    int n, i, key, found = 0;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    // Input the element to search
    printf("Enter the element to search: ");
    scanf("%d", &key);
    
    // Linear Search
    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            found = 1;
            printf("Element %d found at position %d (index %d)\n", key, i+1, i);
            break;
        }
    }
    
    // If element is not found
    if(found == 0)
    {
        printf("Element %d is not present in the array.\n", key);
    }
    
    return 0;
}