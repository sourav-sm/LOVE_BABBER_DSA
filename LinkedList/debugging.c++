//1st question 
//LEARNING WHILE CREATING NODE WE HAVE TO MAKE IT PUBLIC OTHERWISE WE CAN NOT ACCESS IT 

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
      int data;
      Node* next;
};

void printList(Node* head) {
    Node* temp=head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = nullptr;

    printList(head);
    
    delete head;
    delete second;
    delete third;
    return 0;
}