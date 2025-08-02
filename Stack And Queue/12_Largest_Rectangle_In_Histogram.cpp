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
int Largest_Rectangle_Histogram(vector<int> arr) {
    stack<int> st;
    int maxArea = INT_MIN;
    int element = 0;
    for(int i = 0;i < arr.size();i++) {
        while(!st.empty() && arr[st.top()] > arr[i]) {
            element = arr[st.top()];
            st.pop();
        }
        int nse = i,pse = st.empty() ? -1 : st.top();
        maxArea = max(maxArea,element * (nse - pse - 1));
        st.push(i);
    }
    //leftover element traversal
    while(!st.empty()) {
        element = arr[st.top()];
        st.pop();
        int nse = arr.size(),pse = st.empty() ? -1 : st.top();
        maxArea = max(maxArea,element * (nse - pse - 1));
    }
    return maxArea;
}
int main() {
    vector<int> v = {2,1,5,6,2,3};
    cout << Largest_Rectangle_Histogram(v) << endl;
    return 0;
}