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
int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    Node* head = new Node(v[0]);
    Node* temp = head;
    int n = v.size();

    return 0;
}