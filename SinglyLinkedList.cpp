#include <iostream>

using namespace std;

struct Node{
	int data;
	Node* next;

	Node(int x): data(x), next(NULL){}
};

class LinkedList{

public:
	LinkedList(){
		this->head = NULL;
	}
	LinkedList(Node* n){
		this->head = n;
		this->size++;
	}
	void append(Node* n){
		Node* temp = this->head;

		while(temp->next != NULL) temp = this->head->next;
		temp->next = n;
		this->size++;
		cout <<"Node Appended!"<<endl;
	}
	void prepand(Node* n){
		Node* temp = this->head;
		n->next = temp;
		this->head = n;
		this->size++;
		cout <<"Node Prepanded!"<<endl;
	}
	void printList(){
		Node* temp = this->head;
		while(temp!=NULL){
			cout <<temp->data <<endl;
			temp = temp->next;
		}
	}
	void insert(Node* n, int place){
		Node* temp = this->head;
		for(int i = 1; i < place; i++){
			if(temp->next == NULL) {cout <<"Out of Index "<<endl;break;}
			temp = temp->next;
		}
		if(temp != NULL) {
			Node* temp2 = temp->next;
			temp->next = n;
			temp->next->next = temp2;
			this->size++;
		}
	}
	void removeNode(int place){

		if(place > size-1) cout <<"Out Of Index";
		else{
			Node* temp = head;
			for(int i = 1; i < place; i++){
				temp = temp->next;
			}
			temp->next = temp->next->next;
		}
	}
	int getSize() {return size;}

	void update(int place, int value){
		if(place > size-1) cout <<"Out Of Index";
		else{
			Node* temp = this->head;
			for(int i =1; i < place; i++){
				temp = temp->next;
			}
			temp->data = value;
		}
	}

private:
	Node* head;
	int size = 0;

};

int main(){

	Node* first = new Node(1);
	Node* second = new Node(2);
	Node* third = new Node(3);
	Node* four = new Node(4);
	Node* fifth = new Node(5);
	Node* sixth = new Node(6);

	LinkedList ll(first);

	ll.append(second);
	ll.append(third);
	ll.prepand(four);

	ll.insert(fifth, 2);
	ll.insert(sixth, 3);

	ll.removeNode(5);
	ll.update(0, 1);

	printf("Size is: %d\n", ll.getSize());

	ll.printList();

	return 0;
}
