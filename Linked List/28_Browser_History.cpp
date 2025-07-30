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
        string data;
        Node* next;
        Node* prev;
        Node(string data) {
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};
class BrowserHistory {
public:
    Node* browser; 
    BrowserHistory(string homepage) {
        browser = new Node(homepage);
    }
    void visit(string url) {
       browser->next = new Node(url);
       browser->next->prev = browser;
        browser = browser->next;
    }
    
    string back(int steps) {
       while(browser->prev && steps-- > 0) {
            browser = browser->prev;
       }

       return browser->data;
        
        
    }
    string forward(int steps) {
        
       while(browser->next && steps-- > 0) {
            browser = browser->next;
       }
       return browser->data;
    }
};
int main() {

    return 0;
}