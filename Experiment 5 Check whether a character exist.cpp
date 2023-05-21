#include <iostream>

struct Node {
    char data;
    Node* next;
};

bool characterExists(Node* head, char target) {
    Node* current = head;

    while (current != NULL) {
        if (current->data == target) {
            return true;
        }
        current = current->next;
    }

    return false;
}

int main() {
    // Create the linked list: A -> B -> C -> D
    Node* nodeA = new Node{'A', NULL};
    Node* nodeB = new Node{'B', NULL};
    Node* nodeC = new Node{'C', NULL};
    Node* nodeD = new Node{'D', NULL};
    nodeA->next = nodeB;
    nodeB->next = nodeC;
    nodeC->next = nodeD;

    // Test the characterExists function
    std::cout << std::boolalpha;
    std::cout << characterExists(nodeA, 'S') << std::endl;  // true
    std::cout << characterExists(nodeA, 'Z') << std::endl;  // falss

    return 0;
}

