#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

class StringMatchingAlgo{
public:
  /*Naive */
  void naive(string str, string ptr, vector<int> &res){
    int str_len = str.length();
    int ptr_len = ptr.length();

    for (int str_idx = 0; str_idx <= str_len - ptr_len; str_idx++){
      int ptr_idx = 0;
      while (ptr_idx < ptr_len && str[str_idx + ptr_idx] == ptr[ptr_idx]){
        ptr_idx++;
        if(ptr_idx == ptr_len){
          res.push_back(str_idx);
          break;
        }
      }
    }
  }

  /* KMP */
  void KMP(string str, string ptr, vector<int> &res){
    int str_len = str.length();
    int ptr_len = ptr.length();

    //calculate LPS
    vector<int> lps(ptr_len, 0);
    for (int i = 1, x = 0; i < ptr_len; i++){
      if(ptr[x] == ptr[i]){
        x++;
        lps[i] = x;
      }else{
        if(x != 0){
          x = lps[x-1];
        }else{
          x = 0;
        }
      }
    }

    //starting
    int si = 0, pi = 0;
    while(si < str_len){
      if(str[si] == ptr[pi]){
        si++, pi++;
      }

      if(pi == ptr_len){
        res.push_back(si - pi);
        pi = lps[pi-1];
      }else if(si < str_len && str[si] != ptr[pi]){
        if(pi != 0){
          pi = lps[pi - 1];
        }else{
          si++;
        }
      }
    }
  }
  
  void print(vector<int> &vec){
    if(vec.size() == 0){
      printf("Error");
      return;
    }

    // val
    for (auto &val : vec){
      printf("[%d] ",val);
    }
  }
};

int main(){
  string str, ptr;
  vector<int> res;
  printf("Enter String: ");
  cin >> str;
  printf("Enter Pattern: ");
  cin >> ptr;
  
  // algo
  StringMatchingAlgo obj;
  obj.KMP(str, ptr, res);
  obj.print(res);
return 0;}

/*
Index:  0 1 2 3 4 5 6 7 8 9 10 11
String: a a b a a g a a b a  a  b
LPS:    0 1 0 1 2 0 1 2 3 4  5  3
*/
