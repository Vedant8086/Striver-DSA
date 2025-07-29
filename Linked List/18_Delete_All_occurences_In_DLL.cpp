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


Node* DeleteAllOccurence(Node*& head,int x) {
    Node* temp = head;
    while(temp != nullptr) {
        if(temp->data == x) {
            if(temp == head) {
                head = temp->next;
            }
            Node* new_node = temp->next;
            Node* prev_node = temp->prev;
            if(new_node) {
                new_node->prev = prev_node;
            }
            if(prev_node) {
                prev_node->next = new_node;
            }
            free(temp);
            temp = new_node;
        }
    }

    return head;
}
int main() {
    vector<int> arr = {1,2,3,4,5};
    Node* head = new Node(arr[0]);
    ArrayToLL(arr, head);
    TraversingLL(head);
    
    return 0;
}