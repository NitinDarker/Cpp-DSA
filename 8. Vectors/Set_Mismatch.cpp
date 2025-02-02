#include <iostream>
#include <vector>
using namespace std;

vector<int> findErrorNums(vector<int> &nums) {
    int i = 0;
    int j = i + 1;
    vector<int> ans;
    for (int k = 0; k < nums.size() - 1; k++) {
        if (nums[i] == nums[j]) {
            ans.push_back(nums[i]);
        } else if (nums[i] + 1 != nums[j]) {
            ans.push_back(nums[i] + 1);
        }
        i++;
        j++;
    }
    if (ans.size() == 1) {
        ans.push_back(ans[0] + 1);
    }
    return ans;
}

int main() {
    vector<int> s = {1, 2, 2, 4};
    return 0;
}