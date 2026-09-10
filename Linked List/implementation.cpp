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

int main(){
    Node* head = new Node(10);                       //Hardcoding a linked list (not the best way obviously)
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);            

                                                      
    Node* current = head;                            // Free the allocated memory
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}

