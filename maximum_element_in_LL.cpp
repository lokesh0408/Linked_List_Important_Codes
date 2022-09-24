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

// max element-->
int max1(Node *p)
{
    int max = -32737; // INT_MIN-->
    while (p)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

// min element-->
int min1(Node *p)
{
    int min = INT_MAX;
    while (p)
    {
        if (p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }
    return min;
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
    cout << "max is: " << max1(head) << endl;
    cout << "min is: " << min1(head);
}
