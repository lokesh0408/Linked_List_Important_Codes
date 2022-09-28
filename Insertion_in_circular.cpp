#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

} * head;

void create(int a[], int n)
{
    Node *t, *last;
    head = new Node;
    head->data = a[0];
    head->next = head;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

// to find the length of a list..
int Length()
{
    Node *p = head;
    int count = 0;
    do
    {
        count++;
        p = p->next;
    } while (p != head);
    return count;
}

//  insertion in circular LL------------>
void insertion(int pos, int x)
{
    Node *p = head, *t;
    t = new Node;
    // check that if given pos is valid or not..
    if (pos < 0 || pos > Length())
        return;

    if (pos == 0) // either insert before head or after last node -- it is same in circular list.
    {
        if (head == 0) // if one node is there..
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
            {
                p = p->next;
            }
            t->data = x;
            t->next = head;
            p->next = t;
            head = t;
        }
    }
    else
    {
        for (int i = 0; i < pos - 1 and p; i++)
        {
            p = p->next;
        }
        t->data = x;
        t->next = p->next;
        p->next = t;
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

    //  insertion in circular LL------------>
    int pos, x;
    cin >> pos >> x;
    insertion(pos, x);
    display(head);
    // cout << Length();
}