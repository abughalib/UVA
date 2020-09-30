#include <iostream>
using namespace std;

struct Node{
	int val;
	Node* next;
	Node(int val): val(val), next(NULL){}
};
struct Edge{
	int src, dest;
};
class Graph{
private:
	Node* getAdjListNode(int dest, Node* head){
		Node* newNode = new Node(dest);
		newNode->next = head;
		return newNode;
	}
	int size;
public:
	Node **head;
	Graph(Edge edges[], int n, int size){
		head = new Node*[size]();
		this->size = size;

		for(int i = 0; i < size; i++){
			head[i] = nullptr;
		}
		for(unsigned i = 0; i < n; i++){
			int src = edges[i].src;
			int dest = edges[i].dest;
			
			Node* newNode = getAdjListNode(dest, head[src]);
			head[src] = newNode;
			// Uncomment below to have bidirectional graph
			// newNode = getAdjListNode(src, head[dest]);
			// head[dest] = newNode;

		}
	}
	~Graph(){
		for(int i = 0; i < size; i++){
			delete[] head[i];
		delete[] head;
		}
	}

};

void printList(Node* ptr){
	while(ptr!= nullptr){
		cout <<"->" <<ptr->val <<" ";
		ptr = ptr->next;
	}
	cout <<endl;
}

int main(){
	Edge edges[] = {
		{0, 1}, {1, 2}, {2, 0}, {2, 1},
		{3, 2}, {4, 5}, {5, 4}
	};
	int size = 6;
	int n = sizeof(edges)/sizeof(edges[0]);
	Graph graph(edges, n, size);

	for(int i = 0; i < size; i++){
		cout <<i <<" --";
		printList(graph.head[i]);
	}
	return 0;

}