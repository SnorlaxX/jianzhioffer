#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        //排序
        /* vector<int> ret;
        if(k > input.size()){
            return ret;
        }
        sort(input.begin(), input.end());
        for(int i = 0; i<k;i++){
            ret.push_back(input[i]);
        }
        return ret; */

        //最大堆
        /* vector<int> maxHeap;
        for(auto i: input){
            if(maxHeap.size() == 0){
                maxHeap.push_back(i);
            }else if(maxHeap.size() < k){
                maxHeap.push_back(i);
                int index = maxHeap.size() - 1;
                while(index){
                    int parentIndex = (index - 1) / 2;
                    if(maxHeap[index] > maxHeap[parentIndex]){
                        swap(maxHeap[index], maxHeap[parentIndex]);
                        index = parentIndex;
                    }else{
                        break;
                    }
                }
            }else if(i < maxHeap[0]){
                maxHeap[0] = i;
                int index = 0;
                while(index < k){
                    int lchildrenIndex = index * 2 + 1;
                    int rchildrenIndex = index * 2 + 2;
                    if(maxHeap[lchildrenIndex] > maxHeap[rchildrenIndex]){
                        if(maxHeap[index] < maxHeap[lchildrenIndex]){
                            swap(maxHeap[index], maxHeap[lchildrenIndex]);
                            index = lchildrenIndex;
                        }else{
                            break;
                        }
                    }else{
                        if(maxHeap[index] < maxHeap[rchildrenIndex]){
                            swap(maxHeap[index], maxHeap[rchildrenIndex]);
                            index = rchildrenIndex;
                        }else{
                            break;
                        }
                    }
                }
            }
        }
        sort(maxHeap.begin(), maxHeap.end());
        return maxHeap; */

        //优先队列（也是以堆实现）
        vector<int> ret(k, 0);
        if (k == 0) {
            return ret;
        }
        priority_queue<int> maxHeap;
        for (int i = 0; i < k; ++i) {
            maxHeap.push(input[i]);
        }
        for (int i = k; i < (int)input.size(); ++i) {
            if (maxHeap.top() > input[i]) {
                maxHeap.pop();
                maxHeap.push(input[i]);
            }
        }
        for (int i = k-1; i >= 0; i--) {
            ret[i] = maxHeap.top();
            maxHeap.pop();
        }
        return ret;
    }

};

int main()
{
    Solution s;
    vector<int> arr = {4,5,1,6,2,7,3,8};
    vector<int> ret = s.GetLeastNumbers_Solution(arr, 4);
    for(auto i : ret){
        cout << i << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
