#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    bool Find(int target, vector<vector<int>> array) {
        /*暴力 O(mn)
        for (int i = 0; i < array.size(); i++){
            for (int j = 0; j < array[i].size(); j++){
                if(target == array[i][j]){
                    return true;
                }
            }
        }
        return false;
        */
       //O(m+n)
        int row = 0;
        int col = array[0].size() - 1;
        while(row < array.size() && col >= 0){
            if(array[row][col] == target){
                return true;
            }else if(array[row][col] > target){
                col--;
            }else{
                row++;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> array = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}} ;
    bool res = s.Find(7, array);
    cout << res << endl;
    system("pause");
    return 0;
}