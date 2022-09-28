#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *prev;
    int data;
    Node *next;

} *head = 0;

void create(int a[], int n)
{
    Node *t, *last;
    head = new Node;
    head->data = a[0];
    head->prev = head->next = 0;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = last->next;
        t->prev = last;
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

// reversing the doubly linked list-->
void reverse(Node *p)
{
    Node *temp;
    while (p)
    {
        //  swapping the links-->
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p and p->next == 0)
        {
            head = p;
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

    reverse(head);
    display(head);
}
