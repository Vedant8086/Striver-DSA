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
        Node* top;
        int size = 0;
    StackUsingLL() {

    }
    void push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }
    int pop() {
        if(top == NULL) {
            return -1;
        }
        int popped = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return popped;
    }
    int top() {
        if(top ==nullptr) {
            return -1;
        }

        return top->data;
    }
    int size() {
        return size;
    }
};
int main() {

    return 0;
}