#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // destrucure
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is Free" << endl;
    }
};

void insertAtHead(Node *&head, int data)
{

    // new node create
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int data)
{
    // new node create
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void printLL(Node *&head)
{

    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {


    //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

void DleteList(Node *&head, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;

        temp ->next = NULL;
        delete temp;
    }
    else
    {

        Node *current = head;
        Node *prev = NULL;

        int cnt = 1;

        while (cnt < position)
        {
            prev = current;
            current = current->next;
            cnt++;

      
        }
              prev->next = current->next;
          current->next= NULL;
            delete current;
    }
}

int main()
{

    Node *node1 = new Node(10);
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    printLL(head);

    insertAtTail(tail, 12);
    printLL(head);


    insertAtPosition(tail, head, 2, 22);
    printLL(head);
    
    insertAtPosition(tail, head, 4, 2);
    printLL(head);
   
  


    DleteList(head,4);
    printLL(head);
}