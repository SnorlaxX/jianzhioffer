#include <iostream>
#include <string>

using namespace std;

/* 
class Solution {
public:
    string ReverseSentence(string str) {
        string tmp;
        vector<string> vec;
        for(int i = 0; i< str.size(); i++){
            if(str[i] == ' '){
                vec.push_back(tmp);
                tmp.clear();
            }else{
                tmp += str[i];
            }
        }
        vec.push_back(tmp);
        tmp.clear();
        reverse(vec.begin(), vec.end());
        for(int i = 0; i<vec.size(); i++){
            tmp += vec[i];
            if(i!=vec.size()-1){
                tmp += ' ';
            }
        }
        return tmp;
    }
}; 
*/

class Solution {
public:
    string ReverseSentence(string str) {
        if(str.empty()){
            return str;
        }
        int left, right = str.size()-1;
        string res;
        while(right >= 0){
            while(right >= 0 && str[right] == ' '){
                right--;
            }
            if(right < 0){
                break;
            }
            left = right - 1;
            while(left >= 0 && str[left] != ' '){
                left--;
            }
            res += str.substr(left+1, right - left);
            res += ' ';
            right = left;
        }
        if(!res.empty()){
            res.pop_back();    //去除最后一个空格
            return res;
        }else{
            return str;         //str为全空格，按测试要求返回原字符串
        }
    }
};

int main()
{
    system("pause");
    return 0;
}