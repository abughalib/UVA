#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main(){

   string input = "a";

   int p =1, q = 1, r = 1;

   for(int i = 0; i < input.length()-1; ++i){
      if(input[i] < input[i+1]){
         q++;
         p = p > q ? p: q;
         r =1;
      }
      else if(input[i] > input[i+1]){ r++;
         p = p > r ? p:r;
      q = 1;}
      else{
      q = 1;
      r = 1;
   }
   }
   cout <<p;

   return 0;
}
