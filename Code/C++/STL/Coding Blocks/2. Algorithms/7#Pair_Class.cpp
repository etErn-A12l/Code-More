#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // First Method
    pair<int, char> p;
    p.first = 10;
    p.second = 'A';

    cout << p.first << " " << p.second << endl;

    // Second Method
    pair<int, char> p2(p); // Creates a similar pair of P with same value
    cout << p2.first << " " << p2.second << endl;

    // Third Method
    pair<int, string> p3 = make_pair(10, "BMW");
    cout << p3.first << " " << p3.second << endl;

    // User Input Method
    int a, b;
    cin >> a >> b;

    pair<int, int> p4 = make_pair(a, b);
    cout << p4.first << " " << p4.second << endl;

    // Pair of pair
    pair<pair<int, char>, string> car;
    car.second = "Audi";
    car.first.first = 10;
    car.first.second = 'Y';

    cout << car.first.first << endl;
    cout << car.first.second << endl;
    cout << car.second << endl;

    return 0;
}
