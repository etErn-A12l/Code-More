#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> rumi;
    cout << "\nMax_Size : " << rumi.max_size();

    rumi.push_back(12);
    rumi.push_back(13);
    rumi.push_back(14);
    rumi.push_back(15);
    rumi.push_back(16);
    rumi.push_back(17);

    cout << "\nCapacity : " << rumi.capacity();
    cout << "\nVector: ";
    for (int i = 0; i < rumi.size(); i++)
    {
        cout << rumi[i] << " ";
    }
    cout << endl;
    return 0;
}
/*

// C++ program to illustrate the 
// capacity function in vector 

*/
