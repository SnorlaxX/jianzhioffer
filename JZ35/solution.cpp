#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int InversePairs(vector<int> data) {
        int num = data.size();
        vector<int> tmp(num);
        return merge(data, tmp, 0, num-1)%1000000007;
    }
    
private:
    long long merge(vector<int> &data, vector<int> &ret, int left, int right){
        if(left >= right){
            return 0;
        }
        int mid = (left + right) / 2;
        long long cnt = merge(data, ret, left, mid) + merge(data, ret, mid + 1, right);
        int i = left, j = mid + 1, pos = left;
        while(i <= mid && j <= right){//合并
            if(data[i] < data[j]){    //右半部分j以前的数与i构成逆序对
                ret[pos] = data[i];
                i++;
                cnt += (j - (mid + 1));
            }else{
                ret[pos] = data[j];
                j++; 
            }
            pos++;
        }
        for(int k = i; k <= mid; k++){//左半部分有数据剩余
            ret[pos++] = data[k];
            cnt += (j - (mid + 1));    //剩余元素都比右边大
        }
        for(int k = j; k<=right; k++){//右半部分有元素剩余
            ret[pos++] = data[k];
        }
        copy(ret.begin()+left, ret.begin()+right+1, data.begin()+left);
        return cnt;
    }
};

int main()
{
    system("pause");
    return 0;
}