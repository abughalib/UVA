#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Graph{
private:
    int numberOfNodes;
    unordered_map<int,std::vector<int>> mmp;
public:
    Graph(){
        this->numberOfNodes = 0;
    }
    void addVertex(int node){
        //Validate if duplicate node
        vector<int> vec;
            this->mmp.insert(make_pair(node, vec));
    }
    void addEdge(int nodeA, int nodeB){
        //undirected graph
        //Validate if nodeA or nodeB exist.
        this->mmp[nodeA].push_back(nodeB);
        this->mmp[nodeB].push_back(nodeA);
    }
    void showConnections(){
        for(auto i : this->mmp){
            printf("%d->[", i.first);
            for(auto j: i.second) cout <<j <<" ";
            cout <<"] "<<endl;
        }
    }
};

int main(){

    Graph gph;

    gph.addVertex(1);
    gph.addVertex(2);
    gph.addVertex(3);

    gph.addEdge(1, 2);
    gph.addEdge(2, 3);
    gph.addEdge(3, 1);

    gph.showConnections();


    return 0;
}
