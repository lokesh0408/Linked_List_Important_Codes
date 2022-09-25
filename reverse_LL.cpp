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
    Node *last, *t;
    head = new Node;
    head->data = a[0];
    head->next = 0;
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

void display(Node *q)
{
    while (q)
    {
        cout << q->data << " ";
        q = q->next;
    }
    cout << endl;
}

// Reversing a linked list============
void Reverse1(Node *p)
{
    Node *q = 0, *r = 0;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

// recursive solution===========
void Reverse2(Node *q, Node *p)
{
    if (p)
    {
        Reverse2(p, p->next);
        p->next = q; // while returning-(reverse the links).
    }
    else
        head = q;
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
    // Reversing a linked list============
    // Reverse1(head);
    // recursive solution===========
    Reverse2(NULL, head);
    display(head);
}