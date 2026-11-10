// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map> //! map stored all value in stored manner
using namespace std;

int main(){
  //* it makes I/O slower.
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr); 
  
  int n;
  cin >> n;
  cin.ignore();

  string str;
  map <string, int> ump;
  for(int i = 0; i < n; i++) {
    getline(cin, str);
    ump[str]++;
  }

  auto first = ump.begin();
  auto last = prev(ump.end());

  //for hight and low freq
  cout << first->first << first->second;
  cout << last->first << last->second;

  printf("\n\nProgram Terminated Successfully!\n");
  return 0;
}
