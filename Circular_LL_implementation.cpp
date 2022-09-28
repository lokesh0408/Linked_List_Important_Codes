#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

} * head;

// circular linked list----->
void create(int a[], int n)
{
    Node *t, *last;
    head = new Node;
    head->data = a[0];
    head->next = head; // for circular
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = last->next; // for circular
        last->next = t;
        last = t;
    }
}

void display(Node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}

//  display using recursion--->
void RDisplay(Node *p)
{
    static int flag = 0; // now new flag variable will not be created everytime in the recursive call..
    while (p != head or flag == 0)
    {
        flag = 1;
        cout << p->data << " ";
        display(p->next);
    }
    flag = 0;
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
    // display(head);
    //  display using recursion--->
    RDisplay(head);
}
