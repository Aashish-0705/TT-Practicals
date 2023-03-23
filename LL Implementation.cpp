// C++ program for the above approach
#include <iostream>
using namespace std;

// Node class to represent
// a node of the linked list.
class Node {
public:
	int data;
	Node* next;

	// Default constructor
	Node()
	{
		data = 0;
		next = NULL;
	}

	// Parameterised Constructor
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

// Linked list class to
// implement a linked list.
class Linkedlist {
	Node* head;

public:
	// Default constructor
	Linkedlist() { head = NULL; }

	// Function to insert a
	// node at the end of the
	// linked list.
	void insertNode(int);

	// Function to print the
	// linked list.
	void printList();

	// Function to delete the
	// node at given position
	void deleteNode(int);
};

void Linkedlist::deleteNode(int nodeOffset)
{
	Node *temp1 = head, *temp2 = NULL;
	int ListLen = 0;
	if (head == NULL) {
		cout << "List empty." << endl;
		return;
	}
	while (temp1 != NULL) {
		temp1 = temp1->next;
		ListLen++;
	}
	if (ListLen < nodeOffset) {
		cout << "Index out of range"<< endl;
		return;
	}
	temp1 = head;
	if (nodeOffset == 1) {
		head = head->next;
		delete temp1;
		return;
	}
	while (nodeOffset>1) {
		temp2 = temp1;
		temp1 = temp1->next;
		nodeOffset=nodeOffset-1;
	}
	temp2->next = temp1->next;
	delete temp1;
}
void Linkedlist::insertNode(int data)
{
	Node* newNode = new Node(data);
	if (head == NULL) {
		head = newNode;
		return;
	}
	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}
void Linkedlist::printList()
{
	Node* temp = head;
	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}
int main()
{
	Linkedlist list;
cout<<"ENTER NUMBER OF NODES YOU WANT TO ENTER:";
int n,k;
cin>>n;
for(int i=0;i<n;i++)
{
	cout<<"Enter you element:";
	cin>>k;
	list.insertNode(k);
}
	cout << "Elements of the list are: ";
	list.printList();
	cout << endl;
cout<<"Enter the postion of element you want to delete:";
int pos;
cin>>pos;
list.deleteNode(pos);
	cout << "Elements of the list are: ";
	list.printList();
	cout << endl;
	return 0;
}

