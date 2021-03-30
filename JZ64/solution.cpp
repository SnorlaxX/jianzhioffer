#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <deque>

/* //利用堆（优先队列），左侧的元素可以不用在每次窗口移动时删除
   //在获取最大值的，判断其位置，若在窗口范围外再删除
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> ret;
        if(size > num.size() || size == 0){
            return ret;
        }
        
        priority_queue<pair<int, int>> tmp;
        
        for(int i = 0; i < size; i++){
            tmp.push(make_pair(num[i], i));
        }
        ret.push_back(tmp.top().first);
        for(int i = size; i<num.size(); i++){
            tmp.push(make_pair(num[i], i));
            while(tmp.top().second <= i-size){
                tmp.pop();
            }
            ret.push_back(tmp.top().first);
        }
        
        return ret;
    }
};
*/

//双端数组构建单调递减队列
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> ret;
        if(size > num.size() || size == 0){
            return ret;
        }
        
        deque <int> index; //储存可能的最大值下标

        for(int i = 0; i<size; i++){
            //num[i] <= num[j]且i<j时，
            //i、j同在窗口内，最大值不可能是num[i]，舍弃
            while(!index.empty() && num[i] >= num[index.back()]){   
                index.pop_back();
            }
            index.push_back(i);
            
        }
        ret.push_back(num[index.front()]);
        for(int i = size; i<num.size(); i++){
            if(index.front() <= i-size){    //舍弃不在窗口内的值
                index.pop_front();
            }
            while(!index.empty() && num[i] >= num[index.back()]){
                index.pop_back();
            }
            index.push_back(i);
            ret.push_back(num[index.front()]);
        }
        
        return ret;
    }
};

int main()
{
    system("pause");
    return 0;
}
