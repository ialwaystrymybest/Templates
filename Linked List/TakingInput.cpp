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

void insertAtEnd(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);

    if(head == nullptr){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void traverseList(Node* head){
    cout << "Printing the linked list: ";
    while(head != nullptr){
        cout << head->data;

        if(head->next != nullptr){
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

void freeList(Node* &head){
    while (head != nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        int data;
        cin >> data;
        insertAtEnd(head, tail, data);
    }

    traverseList(head);
    freeList(head);

    tail = nullptr;                 // freeList() deallocated the final node without modifying 'tail'.
                                    // Reset to nullptr to avoid leaving an unsafe dangling pointer.
    return 0;
}