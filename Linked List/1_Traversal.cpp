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
void ArrayToLL(vector<int> arr,Node*& head) {
    Node* node = head;
    int n = arr.size();
    for(int i = 1;i < n;i++) {
        Node* temp = new Node(arr[i]);
        node->next = temp;
        node = temp;
    }
    // head = node;

}
void LinkedListTravesal(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
    // cout<<endl;
}

int LengthOfLL(Node* head) {
    Node* temp = head;
    int cnt = 0;
    while(temp!= nullptr) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
void InsertionAtHead(Node*& head,int data) {
    Node* node = new Node(data);
    node->next = head;
    head = node;
    return;
}
void InsertionAtTail(Node*& head,int data) {
    Node* node = new Node(data);
    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = node;
    return;
}
void InsertionAtPos(Node*& head,int data,int pos) {
    int len = LengthOfLL(head);
    if(pos < 1) {
        cout << "Position is Out of Length" << endl;
        return;
    }
    if(pos == 1) InsertionAtHead(head,data);
    else if(pos >= len+1) InsertionAtTail(head,data);
    else {
        Node* node = new Node(data);
        Node* temp = head;
        while(pos > 2) {
            temp = temp->next;
            pos--;
        }
        node->next = temp->next;
        temp->next = node;
    }
}
void DeletionAtHead(Node*& head) {
    head = head->next;
    return;
}

void DeletionAtTail(Node*& head) {
    Node* temp = head;

    while(temp->next->next!= nullptr) {
        temp = temp->next;
    }
    temp->next = nullptr;
    return;
}

void deletionAtPos(Node*& head,int pos) {
    if(pos == 1) DeletionAtHead(head);
    else if(pos >= LengthOfLL(head)) DeletionAtTail(head);
    else {
        Node* temp = head;
        while(pos > 2) {
            temp = temp->next;
            pos--;
        }
        temp->next = temp->next->next;
        return;
    }
}

void RemoveElement(Node*& head,int Ele) {
    if(head == nullptr) return;
    if(head->data == Ele) {
        DeletionAtHead(head);
    } else {
        Node* temp = head;
        Node* prev = nullptr;
        while(temp != nullptr) {
            if(temp->data == Ele) {
                prev->next = temp->next;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }
}
int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8};
    Node* head = new Node(arr[0]);
    ArrayToLL(arr,head);
    InsertionAtHead(head,90);
    InsertionAtTail(head,100);
    InsertionAtPos(head,200,5);
    LinkedListTravesal(head);
    cout<<LengthOfLL(head) << endl;
    cout << "Now Deletion Code Will Be Written : " << endl;
    DeletionAtHead(head);
    LinkedListTravesal(head);
    DeletionAtTail(head);
    LinkedListTravesal(head);
    deletionAtPos(head,5);
    LinkedListTravesal(head);
    RemoveElement(head,200);
    LinkedListTravesal(head);
    return 0;
}