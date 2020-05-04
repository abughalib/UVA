#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <sstream>

using namespace std;

string get_bits(unsigned int x)
{
  string ret;
  for (unsigned int mask=0x80000000; mask; mask>>=1) {
    ret += (x & mask) ? "1" : "0";
  }
  return ret;
}

vector<int> convert(int x) {
  vector<int> ret;
  while(x) {
    if (x&1)
      ret.push_back(1);
    else
      ret.push_back(0);
    x>>=1;  
  }
  reverse(ret.begin(),ret.end());
  return ret;
}

string convertToString(int x){
    string bitStr = "";
    while(x){
        if(x&1) bitStr+='1';
        else bitStr +='0';
        x >>= 1;
    }
    reverse(bitStr.begin(), bitStr.end());
    return bitStr;
}

unsigned long toInt(std::string const &s) {
    static const std::size_t MaxSize = CHAR_BIT*sizeof(unsigned long);
    if (s.size() > MaxSize) return 0; // handle error or just truncate?

    std::bitset<MaxSize> bits;
    std::istringstream is(s);
    is >> bits;
    return bits.to_ulong();
}

int main(){

    int input = 2;

    string StrInput = convertToString(input);

    cout <<StrInput <<std::endl;

    string outPut = "";

    for(int i = 0; i < StrInput.length(); i++){
        if(StrInput[i] == '1') outPut +='0';
        else outPut+='1';
    }

    std::cout <<toInt(outPut);

    return 0;
}
