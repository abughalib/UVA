#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> GlobalVec;

void PrintFront(vector<int> vec){

	for(int i = 0; i <vec.size()-1; ++i){
		GlobalVec.push_back(vec[i]);
		//cout << vec[i];
	}
}

void PrintBack(vector<int> vec, int start){
	for(int i = start; i >= 0; --i){
		GlobalVec.push_back(vec[i]);
		//cout <<vec[i];
	}
}

void PrintVertical(vector<vector<int>> vec){

	for(int i = 0; i < vec.size(); i++){
		GlobalVec.push_back(vec[i][vec[i].size()-1]);
		//cout <<vec[i][vec[i].size()-1];

	}
}
void OtherPattern(vector<vector<int>> vec, int rowCount){
	if(rowCount%2 != 0){
		PrintFront(vec[vec.size()-rowCount-1]);
	}
	else{
		PrintBack(vec[vec.size()-rowCount-1], vec[vec.size()-rowCount-1].size()-2);
	}
}

void PrintOrder(vector<vector<int>> vec){

	int rowCount = 0;

	if(vec.size() > 0)
	for(int i = 0; i <= vec.size(); i++){

		switch(i){
			case 0:
				PrintFront(vec[0]);
				break;
			case 1:
				PrintVertical(vec);
				break;
			case 2:
				PrintBack(vec[vec.size()-1], vec[vec.size()-1].size()-2);
				rowCount++;
				break;
			default:
				OtherPattern(vec, rowCount);
				rowCount++;
				break;

		}

	}
}

int main(){

	vector<vector<int>> vec = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

	PrintOrder(vec);

	for(int i: GlobalVec){
		cout <<i;
	}

	return 0;
}
