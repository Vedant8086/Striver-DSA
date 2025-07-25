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

Node* Sort_Zero_Ones_Twos(Node*& head) {
    // if(head || head->next) {
    //     return head;
    // }
    Node* temp = head;
    Node* zerotemp = new Node(-1);
    Node* onetemp = new Node(-1);
    Node* twotemp = new Node(-1);

    Node* zero = zerotemp;
    Node* one = onetemp;
    Node* two = twotemp;

    while(temp != nullptr) {
        Node* new_node = new Node(temp->data);
        if(temp->data == 0) {
            zerotemp->next = new_node;
            zerotemp = zerotemp->next;
        } else if(temp->data == 1) {
            onetemp->next = new_node;
            onetemp = onetemp->next;
        } else {
            twotemp->next = new_node;
            twotemp = twotemp->next;
        }

        temp = temp->next;
    }
    zerotemp->next = (one->next) ? one->next : two->next;
    onetemp->next = (two->next) ? two->next : nullptr;
    return zero->next;
    // return;
}
int main() {
    vector<int> arr = {2,1,0,0,2,1,1,2,0,0,1,1};
    Node* head = new Node(arr[0]);
    ArrayToLL(arr,head);
    
    TraversingLL(Sort_Zero_Ones_Twos(head));
    return 0;
}