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

int cnt = 0;
int length(Node *p)
{

    while (p)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}

// insertion in doubly LL-->
int insertion(Node *p, int pos, int x)
{
    Node *t = new Node;
    if (pos < 0 || pos > length(p))
    {
        return -1;
    }
    // insert at first position , i.e, before head-->
    if (pos == 0)
    {
        t->data = x;
        t->prev = NULL;
        t->next = head;
        head->prev = t;
        head = t;
    }
    else
    {
        // insert at any other position-->
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if (p->next != 0) // if next node is there ,only then we can do it otherwise 3 links will be modified..
            p->next->prev = t;
        p->next = t;
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
    cout << "length is : ";
    cout << length(head) << endl;

    // insertion in doubly LL-->
    int pos, x;
    cin >> pos >> x;
    insertion(head, pos, x);

    display(head);
}
