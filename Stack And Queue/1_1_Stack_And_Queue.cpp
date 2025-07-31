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
class StackImp {
    public : 
        int n;
        int top = -1;
        int* st = new int[n];
    StackImp(int n) {
        this->n = n;
    }
    void push(int x) {
        if(top >= n) {
            return;
        }
        st[++top] = x;
    }
    int pop() {
        if(top == -1) {
            return -1;
        }
        return st[top--];
    }
    int Top() {
        if(top == -1) return -1;

        return st[top];
    }
    int size() {
        return top + 1;
    }
};

class QueueImp {
    public : 
        int n;
        int front = -1;
        int end = -1;
        int currSize = 0;
        // int maxSize = -1;
        int* q = new int[n];
    QueueImp(int n) {
        this->n = n;
        // maxSize = n;
    }
    void push(int elem) {
        if(currSize == n) {
            cout << "Queue is Full..." << endl;
            exit(1);
        }
        if(end == -1) {
            front = 0;
            end = 0;
        } else {
            end = (end + 1) % n;
        }
        q[end] = elem;
        currSize++;
    }    
    int pop() {
        if(front == -1) {
            cout << "Queue is Empty.." << endl;
        }
        int popped = q[front];
        if(currSize == 1) {
            front = -1;
            end = -1;
        } else {
            front = (front + 1) % n;
        }
        currSize--;
        return popped;
    }
    int top() {
        if(front==-1) {
            cout << "Queue is Empty.." << endl;
        }
        return q[front];
    }
    int size() {
        return currSize;
    }
};
int main() {
    StackImp s1(10);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    cout << "Top : " << s1.Top() << endl;
    s1.pop();
    cout << "Top : " << s1.Top() << endl;
    s1.pop();
    cout << "Top : " << s1.Top() << endl;
    s1.pop();
    cout << "Top : " << s1.Top() << endl;
    cout << "Size of Stack : " << s1.size() << endl;

    QueueImp q1(10);
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