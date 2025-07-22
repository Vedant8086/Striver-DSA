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
//it is implementation of lowqer bound in it. 
//lower bound if element may present.
//upper bound if element must not be present.
int SearchInsertPosition(vector<int>& arr,int target) {
    int sizes = arr.size();
    int low = 0;
    int high = sizes -1;
    int ans = sizes;
    while(low<=high) {
        int mid = (low+high) / 2;
        if(arr[mid] >= target) {
            ans  = mid;
            high = mid- 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
    int n;
    cout << "Enter the Number : ";
    cin >> n;
    vector<int> arr;
    for(int i = 0;i < n;i++) {
        int temp;
        cin>> temp;
        arr.push_back(temp);
    }
    int target;
    cout << "Enter the Target Position : ";
    cin >> target;
    int position = SearchInsertPosition(arr,target);
    cout << "Target Position : " << position + 1 << endl;
    return 0;
}