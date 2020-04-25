#include <iostream>

using namespace std;

template <typename T>
struct Node{
	T value;
	Node* next;
	Node(T x):value(x), next(NULL){}
};

template <typename T>
class Stacks{
private:
	Node<T>* head;
	int length;
public:
	Stacks(){
		this->head = NULL;
		this->length = 0;
	}
	Stacks(T val){
		Node<T>* newNode = new Node<T>(val);
		this->head = newNode;
		this->length++;
	}
	void insert(T val){
		Node<T>* newNode = new Node<T>(val);
		if(this->head == NULL) {this->head = newNode; return; this->length++;}
		Node<T>* temp = head;
		this->head = newNode;
		head->next = temp;
		this->length++;
	}
	void pop(){
		if(this->head == NULL) return;
		Node<T>* temp = head->next;
		this->head = temp;
		this->length--;
	}
	int size(){
		return this->length+1;
	}

	void printStack(){
		Node<T>* temp = head;
		while(temp!=NULL){
			cout <<temp->value <<" ";
			temp = temp->next;
		}
	}

};

int main(){

	Stacks<char> stk;

	stk.insert('A');
	stk.insert('B');
	stk.insert('C');
	stk.insert('D');

	cout <<stk.size() <<endl;
	stk.pop();

	stk.insert('E');

	cout <<stk.size() <<endl;

	stk.printStack();

	return 0;
}
