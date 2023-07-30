#include <iostream>
using namespace std;
main()
{
    char a;
ab:
    cout << "Hello World !";
    cout << endl
         << "If you want to see it again then press 'Y' or 'N: ";
    cin >> a;
    if (a == 'y' || a == 'Y')
        // main();
        goto ab;
    else
        return 0;
}