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
vector<int> Next_Greater_Element(vector<int> v) {
    vector<int> ans(v.size(),0);
    stack<int> st;
    for(int i = v.size()- 1;i>=0;i--){
        while(!st.empty() && st.top() <= v[i]) {
            st.pop();
        }
        if(st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        st.push(v[i]);
    }
    return ans;
}

int main() {
    vector<int> v = {2,1,4,9,2,6,8,4};
    vector<int> ans = Next_Greater_Element(v);
    for(int i = 0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}