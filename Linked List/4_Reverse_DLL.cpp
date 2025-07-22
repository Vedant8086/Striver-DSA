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
        Node* prev;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
}; 


void ArrayToLinkedList(vector<int>& arr,Node*& head) {
    Node* temp = head;
    int n = arr.size();
    for(int i = 1;i < n;i++) {
        Node* node = new Node(arr[i]);
        temp->next = node;
        node->prev = temp;
        temp = node;
    }
    
    return;
}

void TraversingLL(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}
void ReverseDoublyLinkedList(Node*& head) {
    Node* node = head;
    Node* prev11 = nullptr;
    while(node != nullptr) {
        prev11 = node->prev;

        node->prev = node->next;
        node->next = prev11;

        node = node->prev;

    }

    TraversingLL(prev11->prev);
}
int main() {
    vector<int> arr = {1,2,3,4,5,6,7};
    Node* head = new Node(arr[0]);
    ArrayToLinkedList(arr,head);
    TraversingLL(head);

    ReverseDoublyLinkedList(head);
    return 0;
}