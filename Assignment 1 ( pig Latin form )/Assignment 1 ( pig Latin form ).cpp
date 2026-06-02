#include <iostream>
#include <string>
using namespace std;

struct node {
	char value;
	node* link;

	node(char c) {
		value = c;
		link = NULL;
	}
};

// this function is to make a linked list from the string that user entered
node* makingTheLinkedList( const string& text) {
	node* first = NULL;
	node* last = NULL;
	
	for (char c : text) {
		node* ptr = new node(c);
		if (first == nullptr) {
			first = last = ptr;
		}
		else {
			last->link = ptr;
			last = ptr;
		}
	}
	return first;
}
// this function is to determine the vowels including the special cases of y
bool isVowelOrNum(char c , bool Flag) {
	if (Flag && (c == 'y' || c == 'Y'))
		return false;
	if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'o' || c == 'O' || c == 'i' || c == 'I' || c == 'u' || c == 'U' || c == 'y' || c == 'Y' || (c >= '0' && c <= '9'))
		return true;
	else 
		return false;
}
// this function is to covert The linked List to the String again
string covertThelinkedListToAString(node* head) {
	string result;

	node* current = head;
	while (current != nullptr) {
		result += current->value;  
		current = current->link;  
	}

	return result;
}
// this function is to rotate The letters until reaching a vowel
string rotate(string s) {
	char temp = s[0];
	s = s.substr(1) + temp;
	return s;
}
// this function is to converte the string to a pig latin form
void convertToPigLatin(node* LinkedList) {

	string text = covertThelinkedListToAString(LinkedList);

	if (isVowelOrNum(text[0], true)) {
		cout << text + "-way" << endl;
		return;
	}

	string word = text;

	while (!isVowelOrNum(word[0], false)) {
		word = word.substr(1) + word[0];
	}

	cout << word + "-ay" << endl;
}


int main() {
	cout << "Entre a string to convert it to pig Latin form: ";
	string original_string;
	getline(cin,original_string);

	node* mainPtr = makingTheLinkedList(original_string); // the mainPtr will points to the first node in the linked list
	convertToPigLatin(mainPtr);
	
}