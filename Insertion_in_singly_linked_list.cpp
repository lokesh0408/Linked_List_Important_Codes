#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // next is a pointer which points to next node.

    // constructor-->
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// insertion at head
void insertAtHead(Node *&head, int d)
{
    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

// insertion at tail
void insertAtTail(Node *&tail, int d)
{
    // new node create
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

// insert at middle or at given position-->
void insertAtMiddle(Node *&tail, Node *&head, int position, int d)
{

    // inserting at start
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    // middle
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at last position   --> updating tail
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // creating a new node for d
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// traverse a linked list-------------->
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10); // dynamic object  (in heap memory)
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    // head pointed to node1
    Node *head = node1; // assignment operator
    Node *tail = node1;
    // insertAtHead(head, 12);
    // print(head);

    insertAtTail(tail, 12);
    print(head);

    // insertAtHead(head, 15);
    insertAtTail(tail, 15);
    print(head);

    int position;
    cin >> position;
    insertAtMiddle(tail, head, position, 22);
    print(head);

    cout << "head : " << head->data << "    "
         << "tail : " << tail->data;
    return 0;
}
