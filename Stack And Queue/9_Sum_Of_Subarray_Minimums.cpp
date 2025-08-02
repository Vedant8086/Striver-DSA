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
int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    int total = 0;
    int mod = (int)(1e9 + 7);
    vector<int> nse = findnse(arr);
    vector<int> pse = findpse(arr);
    for(int i = 0;i < n;i++) {
        int left = i - pse[i];
        int right = nse[i] - i;
        total = (total + (right * left * 1LL * arr[i]) % mod) % mod;
    }   
    return total;
}
int main() {
    vector<int> v = {3,1,2,4};
    cout << sumSubarrayMins(v) << endl;
    return 0;
}