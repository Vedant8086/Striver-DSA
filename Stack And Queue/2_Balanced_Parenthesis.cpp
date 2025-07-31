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

bool isBalancedParanthesis(string s) {
    stack<char> st;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else {
            if(st.empty()) return false;
            char c = st.top();
            st.pop();
            if(c == '(' && s[i] == ')' || c == '{' && s[i] == '}' || c == '[' && s[i] == ']') {
                continue;
            } else {
                return false;   
            }
        }
    }
    return st.empty();
}
int main() {
    string str;
    cin >> str;
    string strs =  (isBalancedParanthesis(str) ? "Yes" : "No");
    cout << "String is Balanced or Not ? : " << strs << endl;
    return 0;
}