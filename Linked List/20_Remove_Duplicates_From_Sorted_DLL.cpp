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
        Node* prev;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};
void TraversingDLL(Node* head) {
    while(head != nullptr) {
        cout << head->data << "<->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

Node* RemoveDuplicates(Node* head) {
    Node* temp = head;
    while(temp != nullptr && temp->next != nullptr) {
        Node* new_node = temp->next;
        while(new_node != nullptr && new_node->data == temp->data) {
            new_node = new_node->next;
        }
        temp->next = new_node;
        if(new_node) {
            new_node->prev = temp;
        }
        temp = temp->next;
    }
    return head;
    
}
int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    Node* head = new Node(arr[0]);
    Node* temp = head;
    int n = arr.size();
    TraversingDLL(head);

    return 0;
}