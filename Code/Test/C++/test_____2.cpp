#include <iostream>
#include <string>

using namespace std;

class Employee
{

public:

    string name;
    int salaray;

    Employee(string n, int s, int sp)
    {
        this->name = n;
        this->salaray = s;
        this->secretPassword = sp;
    }

    void printDetails()
    {
        cout << "The name of our first employee is " << this->name << " and his salaray is " << this->salaray << "Dollers" << endl;
    }
    void getSecretPassword()
    {
        cout << "The secret password of employee is" << this->secretPassword;
    }

private:
    int secretPassword;
};

int main()
{

    Employee T("Tanmoy constructor", 344, 324432);
    // T.name ="Tanmoy";
    // T.salaray =100;
    T.printDetails();
    // cout<<T.secretPassword;
    T.getSecretPassword();

    return 0;
}