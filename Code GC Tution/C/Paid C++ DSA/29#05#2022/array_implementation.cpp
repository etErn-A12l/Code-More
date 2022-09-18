#include <iostream>
using namespace std;

const int MAX = 5;

class array
{
private:
    int arr[MAX];

public:
    void insert(int pos, int num);
    void del(int pos);
    void reverse();
    void display();
    void search(int num);
    void sort();
};

void array::insert(int pos, int num)
{
    int i;
    // shifting data twoards right
    for (i = MAX - 1; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[i] = num;
}

void array::del(int pos)
{
    // arr[pos] = 0;
    int i;
    for (int i = pos; i < MAX; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[MAX - 1] = 0;
}

void array::reverse()
{
    for (int i = 0; i < MAX / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[MAX - 1 - i];
        arr[MAX - 1 - i] = temp;
    }
}

void array::display()
{
    for (int i = 0; i < MAX; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void array::search(int num)
{
    int check = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (arr[i] == num)
        {
            check = 1;
            cout << "The data " << arr[i] << " is present at index " << i + 1;
            break;
        }
    }
    if (check == 0)
    {
        cout << "The given data is not present !";
    }
    cout << endl;
}

void array::sort()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = i + 1; j < MAX; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    array a1;
    a1.insert(1, 12);
    a1.insert(2, 121);
    a1.insert(3, 22);
    a1.insert(4, 62);
    a1.insert(5, 78);

    // a1.display();

    // a1.del(3);

    // a1.display();

    // a1.del(2);

    a1.display();

    // a1.reverse();

    // a1.display();

    // a1.search(121);
    // a1.search(50);

    a1.sort();

    a1.display();
    return 0;
}
