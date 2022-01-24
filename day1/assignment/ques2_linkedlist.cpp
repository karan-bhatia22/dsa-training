#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(){  //default constructor
        next = NULL;
    }
};  

struct List{
    Node * head;

    List(){ //default constructor
        head = NULL;
    }
};


List createLinkedList() // function to create a linkedlist and return the object
{
    int p;
    cin>>p;

    List l;
    if(p == 0) return l;

    int x, i;

    cin>>x;
    Node * head = new Node ();
    head->data = x;

    l.head = head;

    Node * temp;
    temp = head;

    for(i = 1; i < p; i ++)
    {
        cin>>x;
        temp->next = new Node();
        temp->next->data = x;
        temp = temp->next;
    }

    return l;
}

void printLinkedList(List l) //function to print the linkedlist
{
    Node* head;
    head = l.head;

    if(head == NULL) return;

    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL";
    cout<<'\n';
}
int main()
{
    List l;
    l = createLinkedList();
    printLinkedList(l);
}
