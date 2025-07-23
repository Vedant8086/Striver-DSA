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

int main() {

    return 0;
}