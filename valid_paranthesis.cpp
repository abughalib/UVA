#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:

    bool isValid(string s) {
		stack<char> stk;
		for(char i : s){
			if(i == '(' || i == '{' || i == '['){
				stk.push(i);
			}else{
				if(stk.size() == 0) return false;
				if(i == ')' && stk.top() == '(')stk.pop();
				else if(i == '}' && stk.top() == '{') stk.pop();
				else if(i == ']' && stk.top() == '[') stk.pop();
				else return false;
			}
		}
		if(stk.size() == 0) return true;
		else return false;
    }
};

int main(){

	string paranthesis = "(])";

	Solution sol;
	cout << boolalpha <<sol.isValid(paranthesis);


	return 0;
}
