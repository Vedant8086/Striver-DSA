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
//Adding two number have 2 Approaches
//1. Using Array to Store the number and add it and return using creating LL
//2. Using Dummy Variable -> Starting ans LL using Dummy Var of data -1 and then assign answer LL to This
// and returning dummy->next as the answer.
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
}

void TraversingLL(Node* head) {
    while(head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

void AddingTwoNumbers(Node* num1,Node* num2,Node*& ans) {
    Node* temp = ans;
    int carry = 0;
    while(num1 != nullptr || num2 != nullptr) {
        int sum = carry;
        if(num1) sum += num1->data;
        if(num2) sum += num2->data;

        Node* new_node = new Node(sum % 10);
        carry = sum / 10;

        temp->next = new_node;
        temp = temp->next;

        if(num1) num1 = num1->next; 
        if(num2) num2 = num2->next; 
    }
    if(carry) {
        Node* new_node = new Node(carry);
        temp->next = new_node;
        temp = temp->next;
    }
    ans = ans->next;
    return;
}
int main() {
    vector<int> arr1 = {3,5};
    vector<int> arr2 = {4,5,9,9};

    Node* head1 = new Node(arr1[0]);
    Node* head2 = new Node(arr2[0]);

    ArrayToLL(arr1,head1);
    ArrayToLL(arr2,head2);

    TraversingLL(head1);
    TraversingLL(head2);
    Node* Dummy = new Node(-1);
    AddingTwoNumbers(head1,head2,Dummy);

    TraversingLL(Dummy);
    return 0;
}