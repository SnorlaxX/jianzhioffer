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
            int left = 0;
            int right = rotateArray.size() - 1;
            while(left < right)
            {
                int mid = (int)((left + right) / 2);
                if(rotateArray[right] > rotateArray[left]){
                    return rotateArray[left];
                }else if(rotateArray[right] > rotateArray[mid])
                {
                    right = mid;
                }else if(rotateArray[left] > rotateArray[mid]){
                    left = mid + 1;
                }else{
                    left++;
                }
            }
            return rotateArray[left];
        }
    }
};

int main()
{
    vector<int> array = {6, 6, 1};
    Solution s;
    int min = s.minNumberInRotateArray(array);
    cout << min << endl;
    system("pause");
    return 0;
}
