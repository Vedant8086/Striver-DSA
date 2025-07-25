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
Node* reverseLinkedList(Node*& head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* newHead = reverseLinkedList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
bool PalindromeOrNot(Node*& head) {
    if(head == nullptr || head->next == nullptr) {
        return true;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverseLinkedList(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second != nullptr) {
        if(first->data != second->data) {
            reverseLinkedList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLinkedList(newHead);
    return true;
}
int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    Node* head = new Node(arr[0]);
    ArrayToLL(arr,head);
    TraversingLL(head);

    return 0;
}