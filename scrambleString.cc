#include <vector> 
#include <cstdio> 
#include <string> 
#include <cstdlib> 
#include <string.h> 
#include <iostream> 
using namespace std;
class Solution {
  public:
    vector<vector<vector<int> > > mem;
    bool isScramblePositions(int b1, int e1, int b2, int e2,
        const string& s1, const string& s2) {
      if (e1 - b1 != e2 - b2) {
        return false;
      }
      int len = e1 - b1 + 1;
      if (mem[b1][b2][len - 1] == 1) {
        return true;
      } else if (mem[b1][b2][len - 1] == -1) {
        return false;
      }
      if (b1 == e1) {
        if (s1[b1] == s2[b2]) {
          mem[b1][b2][len - 1] = 1; 
          return true;
        } else {
          mem[b1][b2][len - 1] = -1; 
          return false;
        }
      }

      for (int i = 0; i < len - 1; i++) {
        if (isScramblePositions(b1, b1 + i, 
              b2, b2 + i, s1, s2) && 
            isScramblePositions(b1 + i + 1, b1 + len - 1, 
              b2 + i + 1, b2 + len - 1, s1, s2)) {
          mem[b1][b2][len - 1] = 1; 
          return true;
        }
        if (isScramblePositions(b1, b1 + i, 
              b2 + len - 1 - i, b2 + len - 1, s1, s2) && 
            isScramblePositions(b1 + i + 1, b1 + len - 1, 
              b2, b2 + len - 2 - i, s1, s2)) {
          mem[b1][b2][len - 1] = 1; 
          return true;
        }
      }
      mem[b1][b2][len - 1] = -1; 
      return false;
    } 
    bool isScramble(string s1, string s2) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      if (s1.length() != s2.length()) {
        return false;
      }
      int len = s1.length();
      vector<vector<vector<int> > > tmem(len, 
          vector<vector<int> >(len, 
            vector<int>(len, 0)));
      mem = tmem;
      mem[3][3][4]=0;
      return isScramblePositions(0, s1.length() - 1, 
          0, s2.length() - 1, 
          s1, s2);
    }
};
int main() {
  Solution solution;
  string s1 = "abcdd"; 
  string s2 = "dbdac";
  //string s1 = "great"; 
  //string s2 = "rgtae";
  bool u = solution.isScramble(s1, s2);
  if (u) printf("true\n");
  else printf("false\n");
  return 0;
}
