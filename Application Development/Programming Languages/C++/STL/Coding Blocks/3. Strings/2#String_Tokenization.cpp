#include <iostream>
#include <string>
using namespace std;

int main()
{
    char s[100] = "Aj guhe pani1 pani2 pani3 pani4 pani5 pani6";

    char *ptr = strtok(s, " "); // " " spce works as a de;imeter,, strtok devides the whole string with the delimeter
    cout << ptr << endl;

    ptr = strtok(NULL, " "); // NULL is given to continue to divide from where it left in the previous
    cout << ptr << endl;
    // After extracting all words, it returns NULL
    // So.......

    while (ptr != NULL)
    {
        ptr = strtok(NULL, " ");
        cout << ptr << endl;
    }

    return 0;
}
