#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> reOrderArray(vector<int>& array) {
        for(int i = 0; i<array.size();i++){
            for(int j = 0; j<array.size()-1-i; j++){
                if((array[j] % 2 == 0) && (array[j+1] % 2 == 1)){
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }
        return array;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 2, 3, 4};
    v = s.reOrderArray(v);
    for (int i = 0; i < v.size();i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
    system("pause");
    return 0;
}