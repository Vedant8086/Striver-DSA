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
public:
    int search(vector<int>& arr, int target) {
        int low =0,high = arr.size() - 1;
        while(low <=high) {
            int mid = (low+ high) / 2;
            if(arr[mid] == target) return mid;

            if(arr[low] <= arr[mid]) {
                if(arr[low] <= target && target <= arr[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                if(arr[mid] <= target && target <= arr[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};
int main() {
    int n;
    cout << "Enter the Number Of size : ";
    cin >> n;
    vector<int> arr;
    for(int i =0;i < n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    } 
    Solution s1;
    int target;
    cout << "Enter the Target : ";
    cin >> target;
    int result = s1.search(arr,target);
    cout << "Result : " << result << endl;

    return 0;
}