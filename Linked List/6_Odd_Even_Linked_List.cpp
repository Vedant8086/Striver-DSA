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
//1.Approach is to make two linked list of odd and even and attach.
//2.Approach is to convert into an array rearrange it and make LL.
//3.This Approaches are taking space and time of 2N OR 3N , So It's Better to Swap the Node Connections.

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

void Odd_Even_Linked_List(Node*& head) {
    Node* odd = head;
    Node* even = head->next;
    Node* even_head = head->next;

    while(even != nullptr && even->next != nullptr) {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }

    odd->next = even_head;
    return;

}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    Node* head = new Node(arr[0]);
    ArrayToLL(arr,head);
    TraversingLL(head);
    cout << "Even Odd Singly Linked List : " << endl;
    Odd_Even_Linked_List(head);
    TraversingLL(head);
    // ReversingLLApproach_One(head);
    return 0;
}