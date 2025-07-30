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
        Node* random;
        Node(int data) {
            this->data = data;
            this->next = nullptr;
            this->random = nullptr;
        }
};
void InsertCopyBetween(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        Node* nextElement = temp->next;
        Node* copy = new Node(temp->data);

        copy->next = nextElement;
        temp->next = copy;
        temp = nextElement;
    }
}

void ConnectRandomPointers(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        Node* copyNode = temp->next;

        if(temp->random) {
            copyNode->random = temp->random->next;
        } else {
            copyNode->random = nullptr;
        }
        temp = temp->next->next;
    }
}

Node* GetDeepCopyList(Node* head) {
    Node* temp = head;
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;


    while(temp != nullptr) {
        res->next = temp->next;
        res = res->next;

        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummyNode->next;
}

Node* CloneLinkedList(Node* head) {
    InsertCopyBetween(head);
    ConnectRandomPointers(head);
    return GetDeepCopyList(head);
}
int main() {
    vector<int> arr = {1,2,3,4,5};
    Node* head = new Node(arr[0]);
    Node* temp = head;
    int n = arr.size();
    
    return 0;
}