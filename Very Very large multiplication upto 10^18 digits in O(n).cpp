#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	string s1 = "123";
	string s2 = "456";
	cin >> s1 >> s2;

	int n = s1.size() > s2.size() ? s1.size() : s2.size();

	vector<int> multi(s1.length()*2, 0);

	/*
		1 2 3
	  x 4 5 6
	 `````````

	*/
	if (s1.length() < s2.length()) {
		string temp = s2;
		s2 = s1;
		s1 = temp;
	}
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	long long startIndex = 0, currentIndex=0;
	
	int s1_int = 0;
	int s2_int = 0;
	int carryOver = 0;
	int multiplication = 0;

	for (char i : s1) {
		s1_int = i - '0';
		for (char j : s2) {
			s2_int = j - '0';
			multiplication = s1_int * s2_int + carryOver + multi[currentIndex];
			multi[currentIndex] = multiplication%10;
			carryOver = (int)multiplication / 10;
			currentIndex++;
		}
		if (carryOver != 0) {
			multi[currentIndex] += carryOver;
		}
		startIndex++;
		carryOver = 0;
		currentIndex = startIndex;
	}
	while (multi[multi.size() - 1] == 0) multi.pop_back();

	reverse(multi.begin(), multi.end());

	for (int x : multi)
		cout << x;


	return 0;
}
