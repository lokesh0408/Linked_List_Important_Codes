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

void display(Node *temp)
{
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// linear search-------------->
// Node *search(Node *p, int key)
// {
//     while (p)
//     {
//         if (key == p->data)
//         {
//             return p;
//         }
//         p = p->next;
//     }
//     return NULL; // if key has not found.
// }

// // recursive solution----->
// Node *RSearch(Node *p, int key)
// {
//     if (p == 0)
//     {
//         return 0;
//     }
//     if (key == p->data)
//     {
//         return p;
//     }
//     return RSearch(p->next, key);
// }

// Improvement in linear search-------------->will reduced the time complexity from O(n) to O(1).
Node *ImproveSearch(Node *p, int key)
{
    Node *q; // taking a pointer q followed by p.
    while (p)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL; // if key has not found.
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

    // for linear search---->
    Node *temp;
    int key;
    cin >> key;
    // temp = search(head, key);
    // temp = RSearch(head, key); // ----> recursive function.
    temp = ImproveSearch(head, key);
    if (temp != 0)
    {
        cout << "key is found: " << temp->data;
    }
    else
        cout << "key not found";
}
