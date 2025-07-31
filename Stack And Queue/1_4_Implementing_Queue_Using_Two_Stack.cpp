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
class QueueUsingStack {
    public : 
        stack<int> s1;
        stack<int> s2;
    QueueUsingStack() {

    }
    void push(int x) {
        while(s1.size()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop() {
        if(s1.empty()) return -1;
        int popped = s1.top();
        s1.pop();
        return popped;
    }
    int top() {
        if(s1.empty()) return -1;
        return s1.top();
    }
    int size() {
        return s1.size();
    }
};
class QueueToStackApproach_2 {
    public : 
        stack<int> s1;
        stack<int> s2;
    QueueToStackApproach_2() {

    }
    void push(int x) {
        s1.push(x);
    }
    int pop() {
        if(!s2.empty()) {
            s2.pop();
        } else {
            while(s1.size()) {
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }
    int top() {
        if(!s2.empty()) {
            return s2.top();
        } else {
            while(s1.size()) {
                s2.push(s1.top());
                s1.pop();
            }
            s2.top();
        }
    }
    int size() {
        return s1.size() + s2.size();
    }
};
int main() {
    QueueUsingStack q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    q1.push(50);
    cout << "Top : " << q1.top() << endl;
    q1.pop();
    cout << "Top : " << q1.top() << endl;
    q1.pop();
    cout << "Top : " << q1.top() << endl;
    cout << "Size of Queue : " << q1.size() << endl;
    return 0;
}