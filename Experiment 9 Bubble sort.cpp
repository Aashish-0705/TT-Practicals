#include <iostream>

struct Node {
    int data;
    Node* next;
};

void swapNodes(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSortLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    bool swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swapNodes(ptr1, ptr1->next);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void printList(Node* head) {
    while (head != NULL) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage

    // Create a linked list
    Node* head = new Node();
    head->data = 5;
    head->next = NULL;

    Node* node2 = new Node();
    node2->data = 2;
    node2->next = NULL;
    head->next = node2;

    Node* node3 = new Node();
    node3->data = 9;
    node3->next = NULL;
    node2->next = node3;

    Node* node4 = new Node();
    node4->data = 1;
    node4->next = NULL;
    node3->next = node4;

    Node* node5 = new Node();
    node5->data = 7;
    node5->next = NULL;
    node4->next = node5;

    std::cout << "Original List: ";
    printList(head);

    bubbleSortLinkedList(head);

    std::cout << "Sorted List: ";
    printList(head);

    // Clean up memory
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

