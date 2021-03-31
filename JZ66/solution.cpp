#include <iostream>
using namespace std;
#include <vector>
/* //深度优先
class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        ret = 0;
        vector<vector<int>> visited(rows, vector<int>(cols));
        helper(0, 0, visited, threshold);
        return ret;
    }
private:
    int ret;

    void helper(int i, int j, vector<vector<int>> & visited, int k){
        if(bitAdd(i, j) > k){
            return;
        }else{
            ret++;
            visited[i][j] = 1;
            int rows = visited.size();
            int cols = visited[0].size();
            if(i+1 <rows && visited[i+1][j] == 0){
                helper(i+1, j, visited, k);
            }
            
            if(j+1 <cols && visited[i][j+1] == 0){
                helper(i, j+1, visited, k);
            }
            
            return;
        }

    }

    int bitAdd(int num1, int num2){
        int ret1 = 0;
        int ret2 = 0;
        while(num1){
            ret1 += num1 % 10;
            num1 /= 10;
        }
        while(num2){
            ret1 += num2 % 10;
            num2 /= 10;
        }
        return ret1 + ret2;
    }

};
*/

/*递推 一个点能不能到达取决于它左边或上面的点能不能到达
**visited[i][j] |= visited[i - 1][j];
**visited[i][j] |= visited[i][j - 1];
*/
class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        if(threshold < 0){
            return 0;
        }
        vector<vector<int>> visited(rows, vector<int>(cols));
        visited[0][0] = 1;
        int ret = 1;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols;j++){
                if((i == 0 && j == 0) || bitAdd(i, j) > threshold){
                    continue;
                }
                if(i-1 >= 0){
                    visited[i][j] |= visited[i - 1][j];
                }
                if(j-1 >= 0){
                    visited[i][j] |= visited[i][j - 1];
                }
                ret += visited[i][j];
            }
        }
        return ret;
    }
private:
    int bitAdd(int num1, int num2){
        int ret1 = 0;
        int ret2 = 0;
        while(num1){
            ret1 += num1 % 10;
            num1 /= 10;
        }
        while(num2){
            ret1 += num2 % 10;
            num2 /= 10;
        }
        return ret1 + ret2;
    }

};

int main()
{
    Solution s;
    cout << s.movingCount(3, 2, 17);
    system("pause");
    return 0;
}
