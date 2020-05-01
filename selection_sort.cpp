#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool alessthenb(int a, int b){
	if(a < b) return true;
	else return false;
}

int main(){

	vector<int> vec = {2, 65, 34, 2, 1, 7, 8};
	bool swap = false;
	for(int i = 0; i < vec.size(); i++){
		int minimum_val = vec[i];
		int minIndex = 0;
		for(int j = i+1; j < vec.size(); j++){

			if(alessthenb(vec[j], minimum_val)){
				minimum_val = vec[j];
				minIndex = j;
				swap = true;
			}
		}
		if(swap){
		vec[minIndex] = vec[i];
		vec[i] = minimum_val;
		swap = false;
		}
	}

	for(int x: vec){
		cout <<x <<" ";
	}

	return 0;
}
