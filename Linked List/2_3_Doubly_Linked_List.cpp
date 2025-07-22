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

void ArrayToLL(vector<int> arr,Node*& head) {
    Node* node = head;
    int n = arr.size();
    for(int i = 1;i < n;i++) {
        Node* temp = new Node(arr[i]);
        node->next = temp;
        temp->prev = node;
        node = temp;
    }
    return;
}

int LengthOfLL(Node* head) {
    int cnt = 0;
    while(head != nullptr) {
        cnt++;
        head = head->next;
    }
    return cnt;
} 
void LinkedListTraversal(Node* head) {
    while(head != nullptr) {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

void ReverseTraversal(Node* head) {
    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    while(temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->prev;
    }
    cout << "nullptr" << endl;
    return;
}
void InsertionAtHead(Node*& head,int data) {
    Node* node = new Node(data);
    node->next = head;
    head->prev = node;
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
    node->prev = temp;
    return;
}

void InsertionAtPos(Node*& head,int data,int pos) {
    Node* node = new Node(data);
    if(pos == 1) {
        InsertionAtHead(head,data);
    } else if(pos >= LengthOfLL(head)) {
        InsertionAtTail(head,data);
    } else  {
        Node* temp = head;
        while(pos > 2) {
            temp = temp->next;
            pos--;
        }
        node->next = temp->next->next;
        temp->next = node;
        node->prev = temp;
        return;
    }
}

void InsertionBeforeNode(Node*&head,int data,int val) {
    if(head->data == data) InsertionAtHead(head,data);
    else {
        Node* temp = head;
        Node* prev23 = nullptr;
        while(temp != nullptr) {
            if(temp->data == data) {
                Node* node = new Node(val);
                prev23->next->prev = node;
                node->next = prev23->next;
                prev23->next = node;
                node->prev = prev23;
                return;
            }
            prev23 = temp;
            temp = temp->next;
        }
    }
}
void DeletionAtHead(Node*& head) {
    head = head->next;
    head->prev = nullptr;
}

void DeletionAtTail(Node*& head) {
    Node* temp = head;
    while(temp->next->next != nullptr) {
        temp = temp->next;
    }
    temp->next->prev = nullptr;
    temp->next = nullptr;
    return;
}

void DeletionAtPos(Node*& head,int pos) {
    if(pos == 1) {
        DeletionAtHead(head);
    } else if(pos >= LengthOfLL(head)) {
        DeletionAtTail(head);
    } else {
        Node* temp = head;
        while(pos > 2 && temp != nullptr) {
            temp = temp->next;
            pos--;
        }
        temp->next->next->prev = temp;
        temp->next = temp->next->next;
        return;
    }
}
int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    Node* head = new Node(arr[0]);
    ArrayToLL(arr,head);
    LinkedListTraversal(head);
    ReverseTraversal(head);
    InsertionAtHead(head,110);
    LinkedListTraversal(head);
    InsertionAtTail(head,900);
    ReverseTraversal(head);
    LinkedListTraversal(head);
    InsertionAtPos(head,5000,13);
    LinkedListTraversal(head);
    InsertionBeforeNode(head,8,1897);
    LinkedListTraversal(head);
    ReverseTraversal(head);
    cout << endl;
    cout << "Deletion Operation Will Start from Here : " << endl;
    DeletionAtHead(head);
    LinkedListTraversal(head);
    DeletionAtTail(head);
    LinkedListTraversal(head);
    ReverseTraversal(head);
    DeletionAtPos(head,5);
    LinkedListTraversal(head);
    ReverseTraversal(head);
    
    return 0;
}