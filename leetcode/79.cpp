#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
class Solution {
    /*["ABCE","SFCS","ADEE"]
"ABCCED"
["aaaa","aaaa","aaaa","aaaa","aaab"]
"aaaaaaaaaaaaaaaaaaaa"

*/
public:
    bool exist(vector<vector<char>>& board, string word) {
        int depth = 0;
        bool ret = false;
        vector<vector <bool> > flag(board.size(), vector<bool>(board[0].size(), true));
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == word[depth]){
                    flag[i][j] = false;
                    if(dfs(board, word, depth+1, ret, i, j, flag)) return true;
                    flag[i][j] = true;
                    //if(ret == true) return ret;
                }
            }
        }
        return ret;
    }
    bool dfs(vector<vector<char>> board, string word, 
        int depth, bool &ret, int &pos_x, int &pos_y, vector<vector<bool>> &flag){
        int x = -1;
        int y = -1;
        //cout << "flag " << flag[pos_x][pos_y] << endl;
        if(depth == word.size()){
            //ret = true;
            return true;
        }
        for(int i = 0; i < 4; ++i){
            if(i == 0&&0 <= pos_x&&pos_x < board.size() - 1){
                x = pos_x + 1; 
                y = pos_y;
                if(x != -1 && y != -1 && board[x][y] == word[depth] && flag[x][y] == true){
                    flag[x][y] = false;
                    if(dfs(board, word, depth+1, ret, x, y, flag)) return true;
                    flag[x][y] = true;
                }
            }
            if(i == 1&&0 < pos_x&&pos_x < board.size()){
                x = pos_x - 1; 
                y = pos_y;
                if(x != -1 && y != -1 && board[x][y] == word[depth] && flag[x][y] == true){
                    flag[x][y] = false;
                    if(dfs(board, word, depth+1, ret, x, y, flag)) return true;
                    flag[x][y] = true;
                }
            }
            if(i == 2&&0 <= pos_y&&pos_y < board[0].size() - 1){
                x = pos_x;
                y = pos_y + 1;
                if(x != -1 && y != -1 && board[x][y] == word[depth] && flag[x][y] == true){
                    flag[x][y] = false;
                    if(dfs(board, word, depth+1, ret, x, y, flag)) return true;
                    flag[x][y] = true;
                }
            }
            if(i == 3&&0 < pos_y&&pos_y < board[0].size()){
                x = pos_x;
                y = pos_y - 1;
                if(x != -1 && y != -1 && board[x][y] == word[depth] && flag[x][y] == true){
                    flag[x][y] = false;
                    if(dfs(board, word, depth+1, ret, x, y, flag)) return true;
                    flag[x][y] = true;
                }
            }
            if(x == -1 && y == -1 && i == 3) {
                return false;
            }
            /*if(x != -1 && y != -1 && board[x][y] == word[depth] && flag[x][y] == true){
                flag[x][y] = false;
                if(dfs(board, word, depth+1, ret, x, y, flag)) return true;
                flag[x][y] = true;
            }*/
            //if(ret == true) returnf false;
        }
        //ret = false; 
        return false;
    }
};
int main(int argc, char const *argv[])
{
    string str = "a";
    cout << (str[2] == NULL) << endl;
}