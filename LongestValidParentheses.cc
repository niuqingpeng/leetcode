#include<stack>
#include<string>
using namespace std;
class T {
public:
  int pos;
  char c;
  T(int pos, char c) {
    this->pos = pos;
    this->c = c;
  }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<T> sk; 
        int pre = -1;
        int *v = new int[s.length()];
        for (int i=0; i < s.length(); i++) {
          char c = s[i];
          T t(i, c);
          if (sk.empty()) {
            if (c == ')') {
              v[i] = -2;
            } else {
              sk.push(t);
              v[i] = -1;
            }
          } else {
            T top = sk.top();
            if (top.c == '(') {
              if (c == ')') {
                v[i] = top.pos;
                sk.pop();
              } else {
                v[i] = -1;
                sk.push(t);
              }
            } 
          }
        }

        int maxLen = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
          if (v[i] < 0) {
            continue;
          }
          int iter = i;
          while (iter >= 0 && v[iter] >= 0) {
            iter = v[iter];
            iter--;
          }
          int len = i - iter;
          if (len > maxLen) {
            maxLen = len;
          }
          i = iter;
        }
        delete v;
        return maxLen;
    }
};
