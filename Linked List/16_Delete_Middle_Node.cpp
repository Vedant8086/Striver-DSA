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

void DeleteMiddleNode(Node*& head) {
    if(head == nullptr || head->next == nullptr) return;
    Node* slow = head;
    Node* fast = head;
    fast = fast->next->next;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next; // Delete the middle node
    return;
}
int main() {
    vector<int> arr = {1,2,3,4,5};
    Node* head = new Node(arr[0]);
    ArrayToLL(arr, head);
    TraversingLL(head);
    DeleteMiddleNode(head);
    TraversingLL(head);
    return 0;
}