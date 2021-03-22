#include <iostream>
using namespace std;
#include <queue>

class Solution {
public:
    void Insert(int num) {
        if(maxHeap.size() == 0){
            maxHeap.push(num);
            return;   
        }
        if(maxHeap.size() == minHeap.size()){
            if(num <= minHeap.top()){   
                maxHeap.push(num);
            }else{
                int tmp = minHeap.top();
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(tmp);
            }

            //这个if-else也可写成下面形式
            //不做判断，直接将数据插入minHeap
            //再将minHeap的最小值插入maxHeap
            //此时不用再对maxHeap是否为空判断
            /*
            minHeap.push(num);
            int tmp = minHeap.top();
            minHeap.pop();
            maxHeap.push(tmp);
            */
        }else{
            if(num >= maxHeap.top()){
                minHeap.push(num);
            }else{
                int tmp = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(tmp);
            }
        }
    }

    double GetMedian() { 
        if(maxHeap.size() > minHeap.size()){
            return maxHeap.top();
        }else{
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
    
private:
    //利用一个最大堆和一个最小堆
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

int main()
{
    system("pause");
    return 0;
}
