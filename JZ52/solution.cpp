#include <iostream>
using namespace std;
#include <vector>
#include <string>

/*动态规划
**dp[i][j]: str的前i个字符和pattern的前j个字符能否匹配
*/
class Solution {
public:
    bool match(string str, string pattern) {
        int m = str.size() + 1;
        int n = pattern.size() + 1;
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        dp[0][0] = true;
        for (int j = 2; j < n; j+=2){
            dp[0][j] = dp[0][j - 2] && pattern[j - 1] == '*';
        }
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                if(pattern[j-1] == '*'){
                    if(dp[i][j-2]){
                        dp[i][j] = true;
                    }else if(str[i-1] == pattern[j-2] || pattern[j-2] == '.'){
                        dp[i][j] = dp[i - 1][j];
                    }
                }else{ 
                    if(pattern[j-1] == '.' || (str[i - 1] == pattern[j - 1])){
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main()
{
    system("pause");
    return 0;
}
