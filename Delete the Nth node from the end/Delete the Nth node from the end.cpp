
#include <iostream>
using namespace std;

class SinglyLinkedList {
	struct node {
		int item;
		node* link;
	};
	node* first, * last;
	int length;

public:
	SinglyLinkedList() {
		first = last = nullptr;
		length = 0;
	}
	bool isEmpty() {
		return first == nullptr;
	}


	void addFirst(int element) {
		node* newNode = new node;
		newNode->item = element;

		if (isEmpty()) {
			first = last = newNode;
			newNode->link = nullptr;
		}
		else {
			newNode->link = first;
			first = newNode;
		}
		length++;
	}

	void addLast(int element) {
		node* newNode = new node;
		newNode->item = element;

		if (isEmpty()) {
			first = last = newNode;
			newNode->link = nullptr;
		}
		else {
			last->link = newNode;
			last = newNode;
			last->link = nullptr;
		}
		length++;
	}

	void deleteNthNode(int nthNode) {
		node* cur = first, * prev = nullptr;
		int pos = length - nthNode; // Calculate the position to delete from the start
		if (first == nullptr) {
			cout << "List is empty";
			return;
		}

		if (nthNode <= 0 || nthNode > length){
		cout << "Position is not valid";
		return;
		}

		if (pos == 0) {  // Removing the first node
			first = first->link;
			if (first == nullptr)
				last = nullptr;  // If the list becomes empty, update last
			delete cur;
		}

		else {
			for (int i = 0; i < pos; i++) { // Traverse to the target node
				prev = cur;
				cur = cur->link;
			}
			prev->link = cur->link; // Remove node

			if (cur == last) {  // If deleting the last node, update last
				last = prev;
			}

			delete cur;
		}
		length--; // Decrement length after successful deletion
	}

	void print() {
		if (first == NULL) {
			cout << "it's empty";
			return;
		}
		else {
			node* cur = first;
			while (cur != nullptr) {
				cout << cur->item << " ";  // Print the item
				cur = cur->link;  // Move to the next node
			}
		}
	}
};


int main() {
		SinglyLinkedList l;
		l.addFirst(1);
		l.addFirst(2);
		l.addFirst(3);
		l.addFirst(4);
		l.addFirst(5);

		l.print();
		cout << endl;

		cout << "Enter the position of the node to delete from the end: ";

		int n;
		cin >> n;
		l.deleteNthNode(n);
		l.print();

	return 0;
}
