#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch) {
        int flag = 1; 
        for(auto &s:str){
            if(s.first == ch){
                s.second++;
                flag = 0;
            }
        }
        if(flag == 1){
            str.push_back(make_pair(ch, 1));
        }
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        for(auto s: str){
            if(s.second == 1){
                return s.first;
            }
        }
        return '#';
    }

private:
    vector<pair<char, int>> str;
};

int main()
{
    Solution s;
    s.Insert('g');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('o');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('o');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('g');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('l');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('e');
    cout << s.FirstAppearingOnce() << endl;
    system("pause");
    return 0;
}
