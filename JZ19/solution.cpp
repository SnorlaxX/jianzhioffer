#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ret;
        if(matrix.empty()){
            return ret;
        }
        int xl = 0, xr = matrix[0].size() - 1;
        int yu = 0, yd = matrix.size() - 1;
        int x = 0, y = 0;
        while(xl < xr && yu < yd){
            //遍历最外圈
            while(x < xr){
                ret.push_back(matrix[y][x]);
                x++;
            }
            while(y < yd){
                ret.push_back(matrix[y][x]);
                y++;
            }
            while(x > xl){
                ret.push_back(matrix[y][x]);
                x--;
            }
            while(y > yu){
                ret.push_back(matrix[y][x]);
                y--;
            }
            //缩掉最外一圈
            y++;
            x++;
            xl++;
            xr--;
            yu++;
            yd--;
        }
        if(xl == xr){ //剩下一列
            for(int i = yu; i<=yd; i++){
                ret.push_back(matrix[i][xl]);
            }
        }else if(yu == yd){//剩下一行
            for(int i = xl; i<=xr; i++){
                ret.push_back(matrix[yu][i]);
            }
        }
        return ret;
    }
};

void print(vector <int> vec){
    for(auto i : vec){
        cout << i << " ";
    }
    cout << endl;
}


int main()
{
    vector<vector<int> > vec = {{1,2}, {3,4}};
    Solution s;
    vector<int> ret = s.printMatrix(vec);
    print(ret);
    system("pause");
    return 0;
}