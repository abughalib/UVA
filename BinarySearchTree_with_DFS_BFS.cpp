#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x), left(NULL), right(NULL){}
};

std::vector<int> Inorderdfs(Node* root);
std::vector<int> PostOrder(Node* root);
std::vector<int> PreOrder(Node* root);

class BST{
private:
    Node* root;
    int size;
public:
    BST(){
        this->root = NULL;
        this->size = 0;
    }
    void insert(int val){
        Node* newNode = new Node(val);
        if(root == NULL) {root = newNode; this->size++; return;}
        Node* temp = this->root;
        while(true){
            if(temp->data > val){
                if(temp->left != NULL) temp = temp->left;
                else {temp->left = newNode; this->size++;}
            }
            else if(temp->data == val) return;
            else{
                if(temp->right != NULL) temp = temp->right;
                else {temp->right = newNode; this->size++;}
            }
        }
    }
    bool search(int val){
        if(this->root == NULL) return false;
        Node* temp = this->root;
        while(temp != NULL){
            if(temp->data > val)
                temp = temp->left;
            else if(temp->data == val) return true;
            else temp = temp->right;
        }
        return false;
    }
    int length(){
        return this->size;
    }
    std::vector<int> BFS(){
        std::vector<int> vec;
        std::queue<Node*> Que;
        Node* currentNode = this->root;
        Que.push(currentNode);
        //vec.push_back(root->data);
        while(Que.size()> 0){
            currentNode = Que.front();
            Que.pop();
            vec.push_back(currentNode->data);
            if(currentNode->left != NULL) 
                Que.push(currentNode->left);
            if(currentNode->right != NULL) 
                Que.push(currentNode->right);
        }
        return vec;
    }
    void InorderDFS(){
        Inorderdfs(this->root);
        return;
    }
    void PreOrderDFS(){
        PreOrder(this->root);
        return;
    }
    void PostOrderDFS(){
        PostOrder(this->root);
        return;
    }

};

std::vector<int> vec;
std::vector<int> Inorderdfs(Node* root){
    
    if(root->left != NULL){
        Inorderdfs(root->left);
    }
    vec.push_back(root->data);
    if(root->right != NULL){
        Inorderdfs(root->right);
    }
    return vec;
}
std::vector<int> PreVec;
std::vector<int> PreOrder(Node* root){
    if(root->left != NULL){
        PreOrder(root->left);
    }
    if(root->right != NULL){
        PreOrder(root->right);
    }
    PreVec.push_back(root->data);
    return PreVec;
}
std::vector<int> PostVec;
std::vector<int> PostOrder(Node* root){
    if(root->left != NULL){
        PostOrder(root->left);
    }
    if(root->right != NULL){
        PostOrder(root->right);
    }
    PostVec.push_back(root->data);
    return PostVec;
}


int main(){

    BST bst;
    /*  0
      1   2
           9
        5    10
    */
    bst.insert(0);
    bst.insert(1);
    bst.insert(2);
    bst.insert(9);
    bst.insert(5);
    bst.insert(10);
    bst.InorderDFS();
    bst.PreOrderDFS();
    bst.PostOrderDFS();
    for(int x : vec){
        std::cout <<x <<" ";
    }
    puts("");
    for(int x : PreVec){
        std::cout <<x <<" ";
    }
    puts("");
    for(int x : PostVec){
        std::cout <<x <<" ";
    }



    return 0;
}
