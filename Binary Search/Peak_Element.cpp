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
class Solution {
    public :    
        int Peak_Element(vector<int> arr) {
            
        }
};
int main() {
    int n;
    cout << "Enter the Number : ";
    cin >> n;
    vector<int> arr;
    for(int i = 0;i < n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    Solution s1;
    s1.Peak_Element(arr);
    return 0;
}