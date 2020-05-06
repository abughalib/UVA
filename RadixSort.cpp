#include <vector>
#include <iostream>

int getMax(std::vector<int>& vec) {
    int mx = vec[0];
    for (int i = 1; i < vec.size(); i++)
        if (vec[i] > mx)
            mx = vec[i];
    return mx;
}

void countSort(std::vector<int>& vec, int exp) {
    std::vector<int> output(vec.size());
    std::vector<int> count(10, 0);

    for (int i = 0; i < vec.size(); i++)
        count[(vec[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = vec.size() - 1; i >= 0; i--) {
        output[count[(vec[i] / exp) % 10] - 1] = vec[i];
        count[(vec[i] / exp) % 10]--;
    }

    for (int i = 0; i < vec.size(); i++) {
        vec[i] = output[i];
    }
}

void radixSort(std::vector<int>& vec) {
    int m = getMax(vec);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(vec, exp);
}

int main() {

    std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 0};

    radixSort(vec);
    
    for (int x : vec) {
        std::cout << x << " ";
    }


	return 0;
}
