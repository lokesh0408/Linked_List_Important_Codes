#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *first = NULL;

void create(int a[], int n)
{
    Node *t, *last; // t is temporary pointer;
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int sum = 0;
int summ(Node *temp)
{
    // while (temp) // means -> temp != 0;
    // {
    //     sum += temp->data;
    //     temp = temp->next;
    // }

    //  recursion-->
    if (temp == 0)
        return 0;
    return summ(temp->next) + temp->data;
    return sum;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    create(a, n);
    display(first);
    cout << "sum is : " << summ(first) << endl;
}
