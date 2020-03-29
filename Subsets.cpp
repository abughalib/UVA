#include <bits/stdc++.h>

#define pb push_back
#define pf push_front
#define forup(i,a,b) for (auto i = a; i <= b; i++)
#define fordn(i, a, b) for(auto i = a; i < b; ++i)
#define print cout <<
#define input std::cin >>
#define readln(n) getline(std::cin, n);
#define forvec(i, v1) for(auto x: v1)
#define nl <<"\n";

double EPS = 1e-9;
int INF = 1000000005;
long long int modulu = 10e9 + 7;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);

using namespace std;

typedef long long int ll;
typedef long long unsigned llu;
typedef std::vector<std::string> vs;
typedef std::vector<char> vc;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::deque <ll> dqi;
typedef std::set<ll> seti;
typedef std::string str;

template<typename T>
void printans(T a) {
	for (auto x : a) std::cout <<x <<" ";
}
template<typename T>
vector<vector<T>> PowerSet(std::vector<T> originalSet){
    vector<vector<T>> subsets;

    long long numberofcombinations = pow(2, sizeof(originalSet));

    for(long long  combinationIndex = 0; combinationIndex < numberofcombinations; combinationIndex++){
        std::vector<T> subset;
        for(long long  seElementIndex = 0; seElementIndex < sizeof(originalSet); seElementIndex++){
            
            if(combinationIndex & 1 << seElementIndex){
                subset.push_back(originalSet[seElementIndex]);
            }
        }

        subsets.push_back(subset);
    }

    return subsets;
}

int main(){

    vector<int> set = {1, 2, 3};
    for(auto x: PowerSet(set)){
        for(auto y: x) cout <<"{ " <<y <<" }";   
    }   


    return 0;
}
