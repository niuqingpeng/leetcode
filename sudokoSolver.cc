#include <vector>
#include <cstdlib>
#include <ctype.h>
using namespace std;
#include <string.h>

class Solution {
    private:
        bool u[3][3][10];
        bool rows[9][10];
        bool cols[9][10];
        void init(vector<vector<char> > &board) {
            for (int x = 0; x < 9; x++) {
                for (int y = 0; y < 9; y++) {
                    if (isdigit(board[x][y])) {
                        u[x/3][y/3][board[x][y] - '0'] = true; 
                        rows[x][board[x][y] - '0'] = true; 
                        cols[y][board[x][y] - '0'] = true; 
                    }
                }
            }
            flag = false;
        }
        bool flag;
        void dfs(vector<vector<char> > &board, int pos) {
            if (pos == 81) {
               flag = true; 
               return;
            }
            if (flag) return;
            int x = pos / 9;
            int y = pos % 9;
            if (isdigit(board[x][y])) {
                dfs(board, pos + 1);
            } else {
                for (int i = 1; i <= 9; i++) {
                    if (u[x / 3][y / 3][i] == false && 
                            rows[x][i] == false && 
                            cols[y][i] == false) {
                        u[x / 3][y / 3][i] = true;
                        rows[x][i] = true;
                        cols[y][i] = true; 
                        board[x][y] = '0' + i;
                        dfs(board, pos + 1);
                        if (flag) return;
                        board[x][y] = '.';
                        u[x / 3][y / 3][i] = false;
                        rows[x][i] = false;
                        cols[y][i] = false; 
                    }
                }
            } 
            
        }
    public:
        void solveSudoku(vector<vector<char> > &board) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            memset(u, 0, sizeof(u));
            memset(rows, 0, sizeof(rows));
            memset(cols, 0, sizeof(cols));
            init(board);
            dfs(board, 0);
        }
};
