#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        //查找二分，但技术是遍历，实际时间复杂度还是O(n)
        /*int low = 0;
        int high = data.size() - 1;
        int cnt = 0;
        int index = -1;

        while(low<=high){
            int mid = (low + high) / 2;
            if(data[mid] == k){
                index = mid;
                break;
            }else if(data[mid] > k){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        cout << index << endl;
        if(index != -1){
            for (int i = index; i < data.size();i++){
                if(data[i] == k){
                    cnt++;
                }else{
                    break;

                }
            }
            for (int i = index-1; i >= 0;i--){
                if(data[i] == k){
                    cnt++;
                }else{
                    break;
                }
            }
        } */
        //二分查找数字在数组中出现的位置边界
        int low = 0;
        int high = data.size() - 1;
        int cnt = 0;
        int lowBound, highBound;

        while(low<=high){
            int mid = (low + high) / 2;
            if(data[mid] <= k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        highBound = low;
        
        low = 0;
        high = data.size() - 1;
        

        while(low<=high){
            int mid = (low + high) / 2;
            if(data[mid] < k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        lowBound = low;
        cout << highBound << " " << lowBound << endl;

        cnt = highBound - lowBound;
        return cnt;
    }
};

int main()
{
    Solution s;
    vector<int> array = {1, 2, 3, 3, 3, 3, 4, 5};
    int res = s.GetNumberOfK(array, 3);
    cout << res << endl;
    system("pause");
    return 0;
}