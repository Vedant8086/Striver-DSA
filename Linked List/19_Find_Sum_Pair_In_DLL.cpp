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



Node* findTail(Node* head) {
    while(head->next != NULL) {
        head = head->next;
    }
    return head;
}
vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int,int>> ans;
    if(head == NULL) return ans;
    Node* left = head;
    Node* right = findTail(head);
    while(left->data < right->data) {
        if(left->data + right->data == k) {
            ans.push_back({left->data,right->data});
            left = left->next;
            right = right->prev;
        } else if(left->data + right->data < k) {
            left = left->next;
        } else right = right->prev;
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node* head = new Node(arr[0]);
    return 0;
}
