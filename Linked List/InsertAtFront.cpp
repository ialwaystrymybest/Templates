#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        this->next = nullptr;
    }
};

Node* InsertAtFront(Node* head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    return newNode;
}

void print(Node* head){
    Node* curr = head;

    while(curr != nullptr){
        cout << curr->data;
        if (curr->next != nullptr){
            cout << " -> ";
        }

        curr = curr -> next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(10);                       //Hardcoding a linked list (not the best way obviously)
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);            

    head = InsertAtFront(head, 5);
    head = InsertAtFront(head, 1);

    print(head);

    return 0;
}
