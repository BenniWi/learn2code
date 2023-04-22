#include <stdio.h>
#include <stdlib.h>

// https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
int main()
{
    int noe = 0;

    // Get the number of elements for the array
    printf("Enter number of elements:");
    scanf("%d", &noe);
    printf("Entered number of elements: %d\n", noe);

    // Dynamically allocate memory using malloc()
    int* ptr = (int*)malloc(noe * sizeof(int));

    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        // Memory has been successfully allocated
        printf("Memory successfully allocated.\n");
        // Set the elements of the array
        for (int i = 0; i < noe; ++i)
        {
            ptr[i] = i + 1;
        }

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (int i = 0; i < noe; ++i)
        {
            printf("%d, ", ptr[i]);
        }
        printf("\n");
    }

    // ATTENTION: always FREE the memory, if you don't need it any more
    free(ptr);

    // BAD EXAMPLE -- MEMORY LEAK
    int* ptr2 = NULL;
    for (int i = 0; i < noe; i++)
    {
        // calloc is the same like malloc but initializes the whole memory with zero
        ptr2 = (int*)calloc(100000, sizeof(int));
    }
    free(ptr2);

    return 0;
}
