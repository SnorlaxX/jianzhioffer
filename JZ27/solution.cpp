#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        dfs(str, 0);
        return vector<string>(res.begin(), res.end());
    }
private:
    set<string> res;
    void dfs(string str, int cur){
        if(cur == str.size() - 1){
            res.insert(str);
            return;
        }
        set<int> tmp;    //当前位已使用的字符（用于去重）
        for(int i = cur; i<str.size(); i++){
            //重复，进行剪枝
            if(tmp.find(str[i]) != tmp.end()){
                continue;
            }
            
            tmp.insert(str[i]);
            swap(str[i], str[cur]);        //当前位固定为str[i]
            dfs(str, cur+1);                //开始下层递归
            swap(str[i], str[cur]);        //顺序复原
        }
    }
};

int main()
{
    system("pause");
    return 0;
}