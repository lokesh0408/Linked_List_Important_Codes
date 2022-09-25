#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *first = 0, *second = 0, *third = 0;
//  first and second are two linked lists-->
void create(int a[], int n)
{
    Node *t, *last;
    first = new Node;
    first->data = a[0];
    first->next = 0;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = 0;
        last->next = t;
        last = t;
    }
}
void create2(int b[], int m)
{
    Node *t, *last;
    second = new Node;
    second->data = b[0];
    second->next = 0;
    last = second;

    for (int i = 1; i < m; i++)
    {
        t = new Node;
        t->data = b[i];
        t->next = 0;
        last->next = t;
        last = t;
    }
}
// concatenation of two linked lists------->
// void concat(Node *p, Node *q)
// {
//     third = p;
//     while (p->next != 0)
//     {
//         p = p->next;
//     }
//     p->next = q;
// }

// merging two linked lists---->
void merge(Node *p, Node *q)
{
    Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = 0;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = 0;
    }
    while (p and q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = 0;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = 0;
        }
    }
    if (p)
        last->next = p;
    if (q)
        last->next = q;
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

int main()
{
    // first linked list
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    create(a, n);
    // second linked list
    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    create2(b, m);
    // concatenation of two linked lists------->
    // concat(first, second);
    // cout << "concatenated linked list is-----> ";
//     display(third);
    
    // merging two linked lists---->
    merge(first, second);
    display(third);
}
