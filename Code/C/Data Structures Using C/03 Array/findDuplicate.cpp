#include <stdio.h>
#include <unordered_set>

bool hasDuplicates(int array[], int n);

int main()
{
    int array[] = {1, 2, 3, 4, 4};
    int n = sizeof(array) / sizeof(array[0]);

    if (hasDuplicates(array, n) == true)
        printf("Array has duplicate elements");
    else
        printf("Array does not have duplicate elements");
  
    return 0;
}

bool hasDuplicates(int array[], int n)
{

    if (n == 0)
        return false;

    // Create an empty set
    std::unordered_set<int> s;

    // Iterate through the input array
    for (int i = 0; i < n; i++)
    {
        // If element is already in set, return true
        if (s.count(array[i]) > 0)
            return true;

        s.insert(array[i]);
    }

    // We reach here if element is not present in set
    return false;
}

