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

void ReversingLLApproach_One(Node*& head) {
    Node* temp = head;
    vector<int> arr;
    while(temp != nullptr) {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    reverse(arr.begin(),arr.end());
    Node* head2 = new Node(arr[0]);
    ArrayToLL(arr,head2);
    cout << "Reversed Linked List : " << endl;
    TraversingLL(head2);
}

void ReversingLLApproach_Two(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while(current != nullptr) {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    head = prev;
    return;
}

void ReversingLLApproach_Three(Node*& head) {
    //using stack
    stack<int> s;
    Node* temp = head;
    while(temp != nullptr) {
        s.push(temp->data);
        temp = temp->next;
    }
    Node* temp1 = head; 
    // cout << "Stacking Empty : " <<  (bool)s.empty() << endl;
    while(s.empty()) {
        temp1->data = s.top();
        s.pop();
        
        temp1 = temp1->next;
    }
    // cout << "Stacking Empty : " << s.empty() << endl;
    return;
}


Node* RecursiveReverse(Node* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* new_head = RecursiveReverse(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return new_head;
}
int main() { 
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    Node* head = new Node(arr[0]);
    ArrayToLL(arr,head);

    cout << "Reversing Iterative Using O(N) Space : " << endl;
    ReversingLLApproach_One(head);

    cout << "Reversing Iterative Using O(1) Space : " << endl;
    ReversingLLApproach_Two(head);
    TraversingLL(head);

    cout << "Reversing Iterativly Using Stack : " << endl;
    ReversingLLApproach_Three(head);
    TraversingLL(head);

    cout << "Reversing Using Recursive Approach : " << endl;
    TraversingLL(RecursiveReverse(head));
    return 0;
}