#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.empty()){
            return str;
        }
        n = n % str.size();
        
        return str.substr(n) + str.substr(0, n);
    }
};

int main()
{
    system("pause");
    return 0;
}