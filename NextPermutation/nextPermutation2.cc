#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    void nextPermutation(vector<int> &num) {
      if (num.size() == 1) {
        return;
      }
      int top = num[num.size() - 1];
      int i;
      for (i = num.size() - 2; i >= 0; i--) {
        if (num[i] >= top) {
          top = num[i];
          continue;
        } else {
          break;
        }
      }
      std::reverse(num.begin() + i + 1, num.end());
      if (i == -1) {
        return;
      }
      std::vector<int>::iterator up = std::upper_bound(num.begin() + i + 1, num.end(), num[i]);
      std::swap(num[i], *up);
    }
};
int main() {
  return 0;
}
