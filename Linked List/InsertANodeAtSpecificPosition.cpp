#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* insertNode(Node* head, int pos, int val){
    if(pos < 1) return head;

    if(pos == 1){
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }

    Node *curr = head;
    for (int i = 0; i < pos - 1 && curr != nullptr; i++){
        curr = curr->next;
    }

    if (curr == nullptr){
        return head;
    }

    Node *newNode = new Node(val);

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data;   
        if (curr->next != nullptr) {
            cout << " -> ";
        }
        curr = curr->next;
    }
    cout << endl;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);

    int val = 3, pos = 2;
    head = insertNode(head, pos, val);
    printList(head);

    return 0;
}
