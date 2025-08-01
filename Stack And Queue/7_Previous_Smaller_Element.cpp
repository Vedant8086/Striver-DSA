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
vector<int> Previous_Smaller_Element(vector<int>& nums) {
    vector<int> ans(nums.size(),0);
    stack<int> st;
    int n = nums.size();
    for(int i = 0;i < n;i++) {
        while(!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(nums[i]);
    }
    return ans;
}
int main() {
    vector<int> v = {5,7,9,6,7,4,5,1,3,7};
    for(auto i : Previous_Smaller_Element(v)) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}