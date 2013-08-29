class Solution {
private:
    void swap(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }
    void reverseVector(vector<int> &num, int s, int e) {
        for (int i = s; i <= (s + e) / 2; i++) {
            swap(num[i], num[s + e - i]); 
        }
    }
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
        reverseVector(num, i + 1, num.size() - 1);
        if (i == -1) {
            return;
        }
        for (int k = i + 1; k <num.size(); k++) {
            if ( num[i] < num[k] ) {
                swap(num[i], num[k]);
                break;
            }
        }
    }
};
