#include <iostream>
#include <map>
#include <string>
using namespace std;


class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, int> cnt;
        if(str.empty()){
            return -1;
        }
        for(auto c : str){
            if(cnt.find(c) == cnt.end()){
                cnt.insert(make_pair(c, 1));
            }else{
                cnt[c]++;
            }
        }
        for(int i = 0; i<str.size(); i++){
            if(cnt[str[i]] == 1){
                return i;
            }
        }
        
        return -1;
    }
};

int main()
{
    system("pause");
    return 0;
}