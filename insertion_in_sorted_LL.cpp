#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
} *head = 0;

void create(int a[], int n)
{
    Node *t, *last;
    head = new Node;
    head->data = a[0];
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = 0;
        last->next = t;
        last = t;
    }
}

void display(Node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// insertion in sorted list------------------------------------------------------------------------------------------->>>>>>>>>>>>>>
void insertionSorting(Node *p, int x)
{
    Node *t, *q = NULL; // t will be the inserting node..
    t = new Node;
    t->data = x;
    t->next = 0;

    //  special case--> if LL is empty then p will be null and t will be the first or head node.
    if (head == 0)
    {
        head = t;
    }
    else
    {
        while (p and p->data < x) // p means p != NULL;
        {
            q = p;
            p = p->next;
        }

        // special case--> if there is only one node in LL .. and t is less than that node ,then, t will be placed left of that node
        if (p == head)
        {
            t->next = head;
            head = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
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
    display(head);

    // insertion in sorted list
    int x;
    cin >> x;
    insertionSorting(head, x);
    display(head);
}