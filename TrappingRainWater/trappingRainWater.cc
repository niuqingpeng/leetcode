class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *left = (int*) malloc(n * sizeof(int));
        int *right = (int*) malloc(n * sizeof(int));
        
        int t = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] > t) {
                t = A[i];
            }
            left[i] = t;
        }
        
        t = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (A[i] > t) {
                t = A[i];
            }
            right[i] = t;
        }
        
        int volumn = 0;
        for (int i = 0; i < n; i++) {
            volumn += (left[i] < right[i] ? left[i] : right[i]) - A[i]; 
        }
        
        free(left);
        free(right);
        
        return volumn;
    }
};
