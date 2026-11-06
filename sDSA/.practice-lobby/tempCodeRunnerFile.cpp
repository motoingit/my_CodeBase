  void naive_SM(string haystack, string needle, vector<int>& arr) {
    int n = haystack.size();
    int m = needle.size();

    if (m == 0 || m > n) {
      cout << "Error: 202";
      return;
    }

    for (int i = 0; i <= n - m; i++) {
      int idx = 0;
      while (idx < m && haystack[i + idx] == needle[idx]) {
        idx++;
      }

      if (idx == m) {
        arr.push_back(i);
      }
    }
  }