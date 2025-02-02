#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> v, int target) {
    int s = 0;
    int e = v.size() - 1;
    vector<int> ans;

    while (s < e) {
        int currSum = v[s] + v[e];
        if (target == currSum) {
            ans.push_back(s);
            ans.push_back(e);
            return ans;
        } else if (target > currSum) {
            s++;
        } else {
            e--;
        }
    }
    return ans;
}

int main() {
    vector<int> v = {2, 3, 4};
    int target = 6;
    vector<int> ans = twoSum(v,target);

    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}