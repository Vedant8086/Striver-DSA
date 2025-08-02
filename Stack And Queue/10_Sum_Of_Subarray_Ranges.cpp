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
private : 
    vector<int> findnse(vector<int> arr) {
    vector<int> ans(arr.size(),0);
    stack<int> st;
    int n = arr.size();
    for(int i = n - 1;i>=0;i--) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? n  : st.top();
        st.push(i); 
    }
    return ans;
    }
    vector<int> findpse(vector<int> arr) {
        vector<int> ans(arr.size(),0);
        stack<int> st;
        int n = arr.size();
        for(int i = 0;i < n;i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;
        // int mod = (int)(1e9 + 7);
        vector<int> nse = findnse(arr);
        vector<int> pse = findpse(arr);
        for(int i = 0;i < n;i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            total = (total + (right * left * 1LL * arr[i]));
        }   
        return total;
    }
    vector<int> findnge(vector<int> arr) {
        vector<int> ans(arr.size(),0);
        stack<int> st;
        int n = arr.size();
        for(int i = n - 1;i>=0;i--) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n  : st.top();
            st.push(i); 
        }
        return ans;
    }
    vector<int> findpge(vector<int> arr) {
        vector<int> ans(arr.size(),0);
        stack<int> st;
        int n = arr.size();
        for(int i = 0;i < n;i++) {
            while(!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;
        int mod = (int)(1e9 + 7);
        vector<int> nse = findnge(arr);
        vector<int> pse = findpge(arr);
        for(int i = 0;i < n;i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            total = (total + (right * left * 1LL * arr[i]));
        }   
        return total;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};
int main() {
    Solution s;
    vector<int> v = {1,2,3};
    cout << s.subArrayRanges(v) << endl;
    return 0;
}