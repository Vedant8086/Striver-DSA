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
class MinStack {
public:
    stack<long long> st;
    int mini = INT_MAX;
    
    MinStack() {
        
    }

    void push(int val) {
        if(st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if(mini < val) {
                st.push(val);
            } else {
                long long encoded = 2LL * val - mini;
                st.push(encoded);
                mini = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();
        if(x < mini) {
            mini = (int)(2LL * mini - x);
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long x = st.top();
        if(mini < x) return (int)x;
        return mini;
    }
    
    int getMin() {
        return mini;
    }
};
//Approach IMP giving int overflow so changed into the Long long
int main() {
    MinStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << "Min Element : " << s.getMin() << endl;
    s.push(5);
    cout << "Min Element : " << s.getMin() << endl;
    s.pop();
    cout << "Min Element : " << s.getMin() << endl;
    s.pop();
    cout << "Min Element : " << s.getMin() << endl;
    s.pop();
    cout << "Min Element : " << s.getMin() << endl;
    return 0;
}