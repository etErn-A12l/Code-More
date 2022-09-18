#include <iostream>
#include <list>
using namespace std;

template <typename ForwardIterator, typename S>
ForwardIterator search(ForwardIterator begin, ForwardIterator end, S key)
{
    while (begin != end)
    {
        if (*begin == key)
        {
            return begin;
        }
        begin++;
    }
    return end;
}

int main(int argc, char const *argv[])
{
    list<int> d;

    d.push_back(1);
    d.push_back(7);
    d.push_back(78);
    d.push_back(6);

    auto found = search(d.begin(), d.end(), 78);

    if (found == d.end())
    {
        cout << "The element is not present in the list !";
    }
    else
    {
        cout << "The element " << *found << " is present in the list";
    }

    return 0;
}
