#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    vector<string> words = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to",
    "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

    int peoples;
    cin >> peoples;

    vector<string> names;
    string name;
    
    bool itratednames = false;

    int count = 0;

    for(int i = 0; i < peoples; ++i) {
        cin >> name;
        names.push_back(name);
    }
    
    while(true){
        
        if(count == names.size()) itratednames =true;
        
        if(count%16 == words.size()-1 && itratednames){
            cout <<names[count%peoples] <<": " <<words[count%16] <<endl;
            break;
        }
        
        cout <<names[count%peoples]<<": " <<words[count%16] <<endl;
        
        count++;
    }


    return 0;
}