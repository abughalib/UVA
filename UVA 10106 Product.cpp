#include <iostream>
#include <string>
#include <vector>
using namespace std;

void convert_str_vec(string &num_raw, vector<int>& num){
  for(int i = 0; i < num_raw.size(); i+=1){
    num[i] = num_raw[i]-'0';
  }
}

vector<int> scalar_mutliplication(vector<int>&num, int n, int len){
  vector<int> result(num.size()+len, 0);
  int carry_over = 0;
  for(int i = 0; i < num.size(); i+=1){
    int multi = num[num.size()-1-i]*n;
    result[result.size()-1-i] = (multi+carry_over)%10;
    carry_over = (carry_over+multi)/10;
  }
  if(carry_over != 0){
    result[result.size()-num.size()-1] = carry_over;
  }

  return result;
}

vector<vector<int>> multiplication(vector<int>&num1, vector<int>&num2){
  vector<vector<int>> multiples(num2.size(), vector<int>(num1.size()+num2.size(), 0));
  for(int i = 0; i < num2.size(); i+=1){
    multiples[i] = scalar_mutliplication(num1, num2[num2.size()-1-i], num2.size()-i);
    for(int j = 0; j < i; j+=1){
      multiples[i].push_back(0);
    }
  }

  return multiples;
}

vector<int> multi_addition(vector<vector<int>>& multiplications){
  vector<int> result(multiplications[0].size(), 0);
  int carry_over = 0;
  for(int i = 0; i < multiplications[0].size(); i+=1){
    int add = 0;
    for(int j = 0; j < multiplications.size(); j+=1){
      add += multiplications[j][multiplications[j].size()-1-i];
    }
    result[result.size()-1-i] = (add+carry_over)%10;
    carry_over = (add+carry_over)/10;
  }
  // if (carry_over != 0){
  //   result[result.size()-multiplications[0].size()] = carry_over;
  // }
  return result;
}

void print_result(string num1_raw, string num2_raw){

  vector<int> num1(num1_raw.size(), 0),
    num2(num2_raw.size(), 0);
  convert_str_vec(num1_raw, num1);
  convert_str_vec(num2_raw, num2);

  vector<vector<int>> result;

  if(num1.size() > num2.size()){
    result = multiplication(num1, num2);
  }else{
    result = multiplication(num2, num1);
  }

  // for(auto x: result){
  //   for(int y: x)printf("%d", y);
  //   printf("\n");
  // }
  // printf("result: \n");
  vector<int> ans = multi_addition(result);

  for(int i = 0; i < ans.size(); i+=1){
    if (i == 0 && ans[0] == 0){

    }else{
      printf("%d", ans[i]);
    }
  }

}

int main(){

  string num1_raw = "12", num2_raw = "12";
  string num3_raw = "2", num4_raw = "222222222222222222222222";

  while(cin >> num1_raw >> num2_raw){
    if(num1_raw == "0" || num2_raw=="0"){
      printf("0");
    }else{
      print_result(num1_raw, num2_raw);
    }
    printf("\n");
  }

  return 0;
}
