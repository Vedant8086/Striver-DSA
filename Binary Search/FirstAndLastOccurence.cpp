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

class FirstAndLastOccurence {
    private : 
        int FirstOccurence(vector<int>& arr,int target) {
            int low = 0,high = arr.size(),first = -1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(arr[mid] == target) {
                    first = mid;
                    high = mid - 1;
                } else if(target > arr[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            return first;
        }
        int LastOccurence(vector<int>& arr,int target) {
            int low = 0,high = arr.size(),last = -1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(arr[mid] == target) {
                    last = mid;
                    low = mid + 1;
                } else if(arr[mid] > target){
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            return last;
        }
    public : 
        vector<int> FirstAndLastPos(vector<int> arr,int target) {
            return {FirstOccurence(arr,target),LastOccurence(arr,target)};
        }
};
int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0;i < n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    int target;
    cin >> target;
    FirstAndLastOccurence class1;
    vector<int> a = class1.FirstAndLastPos(arr,target);
    for(auto i : a) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}