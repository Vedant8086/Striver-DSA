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

void Remove_Nth_From_End_LL(Node*& head,int pos) {
    Node* fast = head;
    Node* slow = head;
    for(int i = 0;i < pos;i++) {
        fast = fast->next;
    }
    if(fast == nullptr) head = head->next;
    while(fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    free(delNode);
    return;
}
int main() {
    vector<int> arr = {2,1,0,0,2,1,1,2,0,0,1,1};
    Node* head = new Node(arr[0]);
    ArrayToLL(arr,head);
    TraversingLL(head);
    Remove_Nth_From_End_LL(head,5);
    TraversingLL(head);
    return 0;
}