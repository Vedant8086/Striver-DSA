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

Node* ReverseLinkedList(Node* head) {
   Node* temp = head;  
   
   Node* prev = NULL;  
   
   while(temp != NULL){  
       Node* front = temp->next;  
       
       temp->next = prev;  
       prev = temp;  
       
       temp = front; 
   }
   
   return prev;  
}

Node* getKthNode(Node* temp, int k){
    k -= 1; 

    while(temp != NULL && k > 0){ 
        k--; 
        temp = temp -> next; 
    }
    
    return temp; 
}

Node* kReverse(Node* head, int k){
    Node* temp = head; 
    Node* prevLast = NULL; 
    while(temp != NULL){
        Node* kThNode = getKthNode(temp, k); 
        if(kThNode == NULL){ 
            if(prevLast){
                prevLast -> next = temp; 
            }
            break; 
        }
        Node* nextNode = kThNode -> next; 

        kThNode -> next = NULL; 

        ReverseLinkedList(temp); 
       
        if(temp == head){
            head = kThNode;
        }else{
          
            prevLast -> next = kThNode; 
        }

        prevLast = temp; 

        temp = nextNode; 
    }
    
  
    return head; 
}
int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    Node* head = new Node(arr[0]);
    Node* temp = head;
    int n = arr.size();

    return 0;
}