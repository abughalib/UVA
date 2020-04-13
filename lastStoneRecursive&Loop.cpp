#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 0) return 0;
        else if(stones.size() == 1) return stones[0];
        else{
        	sort(stones.begin(), stones.end());
        	stones[stones.size()-2] = abs(stones[stones.size()-1]-stones[stones.size()-2]);
        	stones.pop_back();
        	
        }
        return lastStoneWeight(stones);
    }
};

class Solution1 {
public:
    int lastStoneWeight(vector<int>& stones) {
    	while(stones.size() >= 2){
    		sort(stones.begin(), stones.end());
    		stones[stones.size()-2] = abs(stones[stones.size()-1] - stones[stones.size()-2]);
    		stones.pop_back();
    	}
    	if(stones.size() == 1) return stones[0];
    	return 0;
    }
};

int main(){

	vector<int> vec={2,7,4,1,8,1};

	Solution sol;
	cout <<sol.lastStoneWeight(vec);
}
