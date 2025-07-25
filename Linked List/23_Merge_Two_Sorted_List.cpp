#include <iostream>
#include <iomanip>
#include <thread>
#include <typeinfo>
#include <cstring>
#include <bits/stdc++.h>
#include <string>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <exception>
#include <stdexcept>
#include <fstream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void TraversingLL(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}
void ArrayToLL(vector<int> &arr, Node *&head)
{
    Node *temp = head;
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        Node *node = new Node(arr[i]);
        temp->next = node;
        temp = node;
    }
}

Node *MergeTwoList(Node *first, Node *second)
{
    Node* t1 = first;
    Node* t2 = second;
    Node* dum = new Node(-1);
    Node* temp = dum;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data < t2->data)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if (t1)
        temp->next = t1;
    else
        temp->next = t2;

    return dum->next;
}
int main()
{

    return 0;
}