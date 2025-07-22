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

class MinimumRotatedSortedArray {
    public  : 
        int MiniRotatedSortedArray(vector<int>& arr) {
            int low = 0,high = arr.size(),ans = INT_MAX;

            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(arr[low] <= arr[mid]) {
                    ans = min(ans,arr[low]);
                    low = mid + 1;
                } else {
                    ans = min(ans,arr[mid]);
                    high = mid - 1;
                }
            }

            return ans;
        }
};

class MaximumRotatedSortedArray {
    public : 
        int MaxRotatedSortedArray(vector<int>& arr) {
            int low = 0,high = arr.size(),ans = INT_MIN;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(arr[low] <= arr[mid]) {
                    ans = max(arr[mid],ans);
                    low = mid + 1;
                } else {
                    high = mid - 1;
                    ans = max(ans,arr[high]);
                }
            }
            return ans;
        }
};
int main() {
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for(int i =0;i < n;i++) {
        cin >> arr[i];
    }
    MinimumRotatedSortedArray m1;
    cout << "Minimum in This Rotated Array :  " << m1.MiniRotatedSortedArray(arr) << endl;

    MaximumRotatedSortedArray m2;
    cout << "Maximum in Rotated Sorted Array : " << m2.MaxRotatedSortedArray(arr) << endl;
    return 0;
}