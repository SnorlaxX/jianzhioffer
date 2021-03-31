#include <iostream>
using namespace std;
#include <string>
#include <vector>

//深度优先搜索
class Solution {
public:
    bool hasPath(vector<vector<char> >& matrix, string word) {
        int h = matrix.size();
        int w = matrix[0].size();
        vector<vector<int>> visited(h, vector<int>(w)); //判断点是否被访问过
        for(int i = 0; i<h; i++){
            for(int j = 0; j<w; j++){
                if(check(matrix, visited, i, j, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool check(vector<vector<char> >& matrix, vector<vector<int> >& visited, int i, int j, string &word, int k){
        if(matrix[i][j] != word[k]){
            return false;
        }else{
            if(k == word.size() - 1){
                return true;
            }else{
                visited[i][j] = 1;
                bool flag = false;
                if(i+1 <matrix.size() && visited[i+1][j] == 0){
                    flag = flag || check(matrix, visited, i+1, j, word, k+1);
                }
                if(i-1 >=0 && visited[i-1][j] == 0){
                    flag = flag || check(matrix, visited, i-1, j, word, k+1);
                }
                if(j+1 <matrix[0].size() && visited[i][j+1] == 0){
                    flag = flag || check(matrix, visited, i, j+1, word, k+1);
                }
                if(j-1 >=0 && visited[i][j-1] == 0){
                    flag = flag || check(matrix, visited, i, j-1, word, k+1);
                }
                visited[i][j] = 0;
                return flag;
            }
        }
    }
};

int main()
{
    system("pause");
    return 0;
}
