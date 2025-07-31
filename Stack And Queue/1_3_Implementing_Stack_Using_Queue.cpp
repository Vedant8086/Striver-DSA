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
class StackUsingQueue {
    public : 
        queue<int> q1;
        queue<int> q2;
    StackUsingQueue() {

    }
    void push(int x) {
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    int pop() {
        if(q1.empty()) return -1;
        int popped = q1.front();
        q1.pop();
        return popped;
    }
    int top() {
        if(q1.empty()) return -1;
        return q1.front();
    }
    int size() {
        return q1.size();
    }
};
int main() {
    StackUsingQueue s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    cout << "Top : " << s1.top() << endl;
    s1.pop();
    cout << "Top : " << s1.top() << endl;
    s1.pop();
    cout << "Top : " << s1.top() << endl;
    s1.pop();
    cout << "Top : " << s1.top() << endl;
    cout << "Size of Stack : " << s1.size() << endl;
    return 0;
}