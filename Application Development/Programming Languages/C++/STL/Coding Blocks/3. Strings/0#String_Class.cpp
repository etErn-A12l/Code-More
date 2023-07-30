#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    string s1 = "I Hate You !";
    string s2("Hello World !");
    string s3(s2);

    char arr[] = {'I', 'L', 'U', '\0'};
    string s4(arr);

    cout << s4;
    return 0;
}
