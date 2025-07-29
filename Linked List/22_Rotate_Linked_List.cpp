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
Node* findKNode(Node* head,int k) {
    Node* temp = head;
    while(temp != nullptr && k > 0) {
        temp = temp->next;
        k--;
    }
    return temp;

}

Node* rotate(Node*& head,int k) {
    if(head == nullptr || head->next == nullptr) {
        return head;

    }
    Node* temp = head;
    int len = 1;
    while(temp->next != nullptr) {
        temp = temp->next;
        len++;
    }
    temp->next = head;
    k = k % len;
    if(k % len == 0) return head;
    Node* new_node = findKNode(head,len-k);
    head = new_node->next;
    new_node->next = nullptr;
    return head;
}
int main() {

    return 0;
}