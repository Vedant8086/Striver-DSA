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
            this->next = nullptr;
        }
};

void TraversingLL(Node* head) {
    while(head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}
void ArrayToLL(vector<int>& arr,Node*& head) {
    Node* temp = head;
    int n = arr.size();
    for(int i = 1;i < n;i++) {
        Node* node = new Node(arr[i]);
        temp->next = node;
        temp = node;
    }
}

int addHelper(Node* temp) {
    if(temp == nullptr) return 1;

    int carry = addHelper(temp->next);
    temp->data += carry;
    if(temp->data < 10) return 0;
    temp->data = 0;
    return 1;
}
void AddOneToLL(Node*& head) {
    int carry = addHelper(head);
    if(carry) {
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    Node* head = new Node(arr[0]);
    ArrayToLL(arr,head);
    TraversingLL(head);
    AddOneToLL(head);
    TraversingLL(head);
    return 0;
}