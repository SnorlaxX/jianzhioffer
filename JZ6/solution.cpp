#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if(rotateArray.size() == 0)
            return 0;
        else
        {
            
            return 0;
        }
    }
};

int main()
{
    vector<int> array = {3, 4, 5, 1, 2};
    Solution s;
    int min = s.minNumberInRotateArray(array);
    cout << min << endl;
    system("pause");
    return 0;
}
