#include <bits/stdc++.h>
using namespace std;

class books
{
public:
    string name;
    float price;

    books()
    {
    }

    books(string name, float price)
    {
        this->name = name;
        this->price = price;
    }
};

class BookComparator
{
public:
    bool operator()(books A, books B)
    {
        if (A.name == B.name)
            return true;
        else
            return false;
    }
};

template <class ForwardIterator, class T, class Compare>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key, Compare cmp)
{
    while (start != end)
    {
        if (cmp(*start, key) == true)
        {
            return start;
        }
        start++;
    }
    return end;
}

int main(int argc, char const *argv[])
{
    books b1("C++", 102);
    books b2("Java", 142);
    books b3("Python", 92);
    books b4("Bash", 302);

    list<books> b;

    b.push_back(b1);
    b.push_back(b2);
    b.push_back(b3);
    b.push_back(b4);

    books key("C++", 152);

    BookComparator cmp;

    /*   if (cmp(b1, key))
    {
        cout << "Match Found !";
    }   */

    auto it = search(b.begin(), b.end(), key, cmp);

    // list<books>::iterator it = search(b.begin(),b.end(),key,cmp);

    if (it != b.end())
    {
        cout << "Book was found in the list !";
    }

    return 0;
}
