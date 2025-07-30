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
        Node* child;
        Node(int data) {
            this->data = data;
            this->next = nullptr;
            this->child = nullptr;
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

Node* Merge(Node* list1,Node* list2) {
    Node* dummy = new Node(-1);
    Node* res = dummy;
    while(list1 != nullptr && list2 != nullptr) {
        if(list1->data < list2->data) {
            res->child = list1;
            res = list1;
            list1 = list1->next;
        } else {
            res->child = list2;
            res = list2;
            list2 = list2->next;
        }
        res->next = nullptr;
    }
    if(list1) {
        res->child = list1;
    } else {
        res->child = list2;
    }
    return dummy->child;
}
Node* FunctionForMerge(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;
    Node* mergerHead = FunctionForMerge(head->next);
    return Merge(head,mergerHead);
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    Node* head = new Node(arr[0]);
    ArrayToLL(arr, head);
    TraversingLL(head);
    TraversingLL(FunctionForMerge(head));
    return 0;
}