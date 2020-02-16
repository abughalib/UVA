#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define forup(i,a,b) for (auto i = a; i <= b; i++)
#define fordn(i, a, b) for(auto i = a; i < b; ++i)
#define print cout <<
#define input std::cin >>
#define readln(n) getline(std::cin, n);
#define forvec(i, v1) for(auto x: v1)
#define temp template<typename T>
using namespace std;

#define pb push_back
#define pf push_front
#define forup(i,a,b) for (auto i = a; i <= b; i++)
#define fordn(i, a, b) for(auto i = a; i < b; ++i)
#define print cout <<
#define input std::cin >>
#define readln(n) getline(std::cin, n);
#define forvec(i, v1) for(auto x: v1)
#define temp template<typename T>

double EPS = 1e-9;
int INF = 1000000005;
long long int modulu = 10e9 + 7;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);

typedef long long int ll;
typedef long long unsigned llu;
typedef std::vector<std::string> vs;
typedef std::vector<char> vc;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::deque <ll> dqi;
typedef std::set<ll> seti;
typedef std::string str;

temp
void printans(T a) {
    for (auto x : a) std::cout << x << " ";
}

int main() {

    //Zaping
    short current = 0, togo = 0;
    while(cin >> current >> togo){

    if(current == -1 && togo == -1) break;
    //Case 1;
    short path1 = 0;
    short path2 = 0;
    short path3 = 0;
    short path4 = 0;

    short path = 0;

    if(togo > current){
        path1 = togo - current;
        path2 = abs(0 - current) + (99-togo) +1;
        path = min(path1, path2);
    }
    else if(current > togo){
        path3 = (100 - current) + togo;
        path4 = current-togo;
        path = min(path3, path4);
    }

    cout <<path <<"\n";

    }

    return 0;
}
