#include <iostream>
#include <vector>

using namespace std;

struct Node{
	int value;
	Node* next;
	Node(int val):value(val), next(NULL) {}
};

class Queue{
private:
	Node* top;
	Node* buttom;
	int size;

public:
	Queue(){
		this->top = NULL;
		this->buttom = NULL;
		this->size = 0;
	}

	void peek(){
		if(this->size == 0) {cout <<"NULL\n"; return;}
		cout <<buttom->value;
	}

	void enqueue(int value){
		Node* newNode = new Node(value);
		if(this->size == 0) {
			this->buttom = newNode;
			this->top = this->buttom;
		}else{
			this->top->next = newNode;
			this->top = newNode;
		}
		this->size++;
	}
	void dequeue(){
		if(this->size == 0) return;
		else{ //Deallocate memeory here.
			this->buttom = this->buttom->next;
		}
		this->size--;
	}

	int Size(){
		return this->size;
	}

	void PrintQueue(){
		Node* temp = this->buttom;
		while(temp != NULL){
			cout <<temp->value <<" ";
			temp = temp->next;
		}
		cout <<"\n";
	}
};

int main(){

	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.dequeue();

	cout << q.Size()<<endl;

	q.PrintQueue();


	return 0;
}
