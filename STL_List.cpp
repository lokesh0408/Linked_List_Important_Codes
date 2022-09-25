#include <bits/stdc++.h>
using namespace std;

void display(list<int> &lst)
{
    for (auto it : lst)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    // stl list:->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    list<int> list1; // list of 0 length
    list1.push_back(5);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(4);
    list1.push_back(6);
    list1.push_back(7);
    list1.push_back(8);

    display(list1);

    // Creating a list2------------------->

    // int n;
    // cin >> n;
    // list<int> list2(n); // empty list of size - n
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     list2.push_back(x);
    // }

    // OR-------------------->
    list<int> list2(3); // empty list of size - 3
    list<int>::iterator it;
    it = list2.begin(); // now it is in begin of the list
    *it = 45;
    it++;
    *it = 6;
    it++;
    *it = 9;
    it++;
    // display(list2);

    // now deleting list1 last and front element------>
    // list1.pop_back();
    // list1.pop_front();
    // display(list1);

    // now delete from middle-->
    // list1.remove(6);
    // display(list1);

    // sorting the list-->
    // list1.sort();
    // display(list1);

    // merging two lists---->
    // list1.merge(list2);
    // cout << "list1 after merging with list2:  ";
    // list1.sort();
    // display(list1);

    // reversing the list---------->
    list1.reverse();
    display(list1);
}