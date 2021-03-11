#include <iostream>
using namespace std;
#include <string>

class Solution
{
public:
    string replaceSpace(string s) {
/*         int len = s.length();
        for (int i = 0; i < len; i++){
            if(s[i] == ' '){
                s.replace(i, 1, "%20");
                i += 2;
                len += 2;
            }
        }
        return s; */
        string ss;
        int len = s.length();
        for (int i = 0; i < len; i++){
            if(s[i] == ' '){
                ss+="%20";
            }else{
                ss+=s[i];
            }
        }
        return ss;
    }
};

int main()
{
    Solution s;
    string str = "Have a good day!";
    string res = s.replaceSpace(str);
    cout << res << endl;
    system("pause");
    return 0;
}