#include <iostream>

struct Node{
    int data;
    Node* next;
};

void insert(Node*& head, int value);
void printList(Node*& head);

int main(){
    struct Node* head = nullptr;
    insert(head, 5);
    insert(head, 7);
    insert(head, 10);
    printList(head);
}

void insert(Node*& head, int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if(head == nullptr){
        head = newNode;
        std::cout<<"Primer nodo adquirido!\n";
    }else{
        Node* actual = head;
        while (actual->next != nullptr)
        {
            actual = actual->next;
        }
        std::cout<<"Nodo añadido correctamente!\n";
        actual->next = newNode;
    }
}

void printList(Node*& head) {
    std::cout << "Imprimiendo Lista\n";

    if (head == nullptr) {
        std::cout << "La lista está vacía.\n";
        return;
    }

    Node* actual = head;
    while (actual != nullptr) {
        std::cout << actual->data << "\n";
        actual = actual->next;
    }
}
