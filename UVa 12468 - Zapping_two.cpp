#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <numeric>

using namespace std;

int main() {

    int current = 84, togo = 20;

    while (scanf_s("%d %d", &current, &togo)) {

         if (current == -1 && togo == -1) break;
         //Case 1;
        short path1 = abs(togo - current);
        short path2 = abs(abs(0 - current) + (100 - togo));
        short path3 = abs(100 - current) + togo;

        int path = min(path1, min(path2, path3));

        cout << path << "\n";

    }

    return 0;
}