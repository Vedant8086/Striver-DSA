#include<iostream>
#include<iomanip>
#include<thread>
#include<typeinfo>
#include<cstring>
#include<bits/stdc++.h>
#include<string>
#include<math.h>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<exception>
#include<stdexcept>
#include<fstream>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> s;
        int i = 1;
        s.push(nums[0]);
        while(i < nums.size()) {
            if(s.empty()) {
                s.push(nums[i]);
                i++;
            }
            else if(s.top() > 0 && nums[i] < 0) {
                int x = abs(nums[i]);
                if(s.top() > x) {
                    i++;
                    continue;
                }else if(s.top() < x) {
                    s.pop();
                    continue;
                } else {
                    s.pop();
                    i++;
                    continue;
                }
            }
            else {
                s.push(nums[i]);
                i++;
            }
        }
        vector<int> ans(s.size());
        for(int i = s.size()-1;i>=0;i--) {
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> v = {5,10,-5};
    for(auto i : s.asteroidCollision(v)) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}