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

void ArrayToLL(vector<int>& arr,Node*& head) {
    Node* temp = head;
    int n = arr.size();
    for(int i = 1;i < n;i++) {
        Node* node = new Node(arr[i]);
        temp->next = node;
        temp = node;
    }
    return;
}

Node* MergeKList(vector<Node*>& lists) {
    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> pq;
    for(int i = 0;i < lists.size();i++) {
        if(lists[i]) {
            pq.push({lists[i]->data,lists[i]});        
        }
    }
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        if(it.second->next) {
            pq.push({it.second->next->data,it.second->next});
        }
        temp->next = it.second;
        temp = temp->next;
    }
    return dummyNode->next;
}
void TraversingLL(Node* head) {
    while(head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    vector<vector<int>> arr = {{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    }};
    int n = arr.size();

    return 0;
}