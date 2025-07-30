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
Node* FindMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* MergeTwoLists(Node* list1,Node* lists2) {
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(list1 != nullptr && lists2 != nullptr) {
        if(list1->data < lists2->data) {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        } else {
            temp->next = lists2;
            temp = lists2;
            lists2 = lists2->next;
        }
    } 
    if(list1) {
        temp->next = list1;
    } else {
        temp->next = lists2;
    }
    return dummyNode->next;
}
Node* SortLinkedList(Node*head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* middle = FindMiddle(head);
    Node* right = middle->next;
    middle->next = nullptr;
    Node* left = head;

    left = SortLinkedList(left);
    right = SortLinkedList(right);

    return MergeTwoLists(left,right);
}
int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    Node* head = new Node(v[0]);
    Node* temp = head;
    int n = v.size();

    return 0;
}