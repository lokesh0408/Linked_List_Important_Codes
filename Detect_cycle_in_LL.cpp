#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
} *head = 0;

int Length()
{
    Node *p = head;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

// Floyd Cycle Detection Algorithm-------------------------------------->

// check if cycle is there in list or not
bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

// make a cycle in a list
int makeCycle(Node *head, int pos)
{
    Node *temp = head;
    Node *startnode;
    int count = 1;
    if (pos < 0 || pos > Length())
    {
        cout << "invalid position" << endl;
        return -1;
    }
    while (temp->next != NULL)
    {
        if (count == pos)
            startnode = temp->next;
        count++;
        temp = temp->next;
    }
    temp->next = startnode;
}

// remove the existing cycle in a list.
void removeCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    fast = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

void create(int a[], int n)
{
    Node *t, *last;
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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    create(a, n);
    display(head);

    // check if cycle is there in list or not
    if (detectCycle(head))
    {
        cout << "cycle is there" << endl;
    }
    else
        cout << "cycle is not there" << endl;

    // make a cycle in a list
    int pos;
    cin >> pos;
    makeCycle(head, pos);

    cout << "After making a cycle - "
         << " ";
    if (detectCycle(head))
    {
        cout << "cycle is there" << endl;
    }
    else
        cout << "cycle is not there" << endl;

    // remove the existing cycle from a list.
    removeCycle(head);
    cout << "After removing a cycle - "
         << " ";
    if (detectCycle(head))
    {
        cout << "cycle is there" << endl;
    }
    else
        cout << "cycle is not there" << endl;
}
