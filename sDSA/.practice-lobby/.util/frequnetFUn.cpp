#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
      s = normalizeSpaces(s);
      int n = s.size();
      int ptr = n - 1;

       string res;
       stack <char> stk;
       
       while (ptr != -1){
          char curr = s[ptr];
          if(curr != ' '){
            stk.push(curr);
          }else{
            while (!stk.empty()){
              res.push_back(stk.top());
              stk.pop();
            }
            res.push_back(' ');
          }

          ptr--;
       }

       while (!stk.empty()){
        res.push_back(stk.top());
        stk.pop();
      }

       return res;
    }

    string normalizeSpaces(string s) {
      string ans;
      int i = 0;
      int n = s.size();

      // Skip leading spaces
      while (i < n && s[i] == ' ')
          i++;

      while (i < n) {
          if (s[i] != ' ') {
              ans.push_back(s[i]);
          } else {
              // Add only one space
              ans.push_back(' ');

              // Skip all consecutive spaces
              while (i < n && s[i] == ' ')
                  i++;
              continue;
          }

          i++;
      }

      // Remove trailing space if present
      if (!ans.empty() && ans.back() == ' ')
          ans.pop_back();

      return ans;
  }

  void inputMatrix(auto &adjMat){
    for (auto &list : adjMat){
      for (auto &node : list){
        cin >> node;
      }
    }
  }
};
