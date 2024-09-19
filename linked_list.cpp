#include "linked_list.h"

// Implementación de la función de inserción
void LinkedList::insert(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Implementación de la función de búsqueda
bool LinkedList::search(int val) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == val) {
            return true;
        }
        current = current->next;
    }
    return false;
}
