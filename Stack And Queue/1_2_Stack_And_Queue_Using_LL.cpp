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
class Node {
    public : 
        int data;
        Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class StackUsingLL {
    public : 
        Node* top = nullptr;
    StackUsingLL() {
        top = nullptr;
    }
    int size = 0;
    void push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }
    int pop() {
        if(top == nullptr) {
            return -1;
        }
        int popped = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return popped;
    }
    int Top() {
        if(top ==nullptr) {
            return -1;
        }

        return top->data;
    }
    int sizee() {
        return this->size;
    }
};
class QueueImp {
    public : 
        Node* front = nullptr;
        Node* end = nullptr;
        int sizes = 0;
    QueueImp() {

    }
    void push(int x) {
        Node* temp = new Node(x);
        if(front == nullptr) {
            front = temp;
            end = temp;
        } else {
            end->next = temp;
            end = temp;
        }
        sizes++;
    }
    int pop() {
        if(front == nullptr) {
            return -1;
        }
        int popped = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        sizes--;
        return popped;
    }
    int top() {
        if(front == nullptr) return -1;
        return front->data;
    }
    int size() {
        return this->sizes;
    }

};
int main() {
    StackUsingLL s1;
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
    cout << "Size of Stack : " << s1.sizee() << endl;
    
    QueueImp q1;
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