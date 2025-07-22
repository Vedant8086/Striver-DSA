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

class SingleElementInSortedArray {
    public : 
        int SingleElementInArray(vector<int>& arr) {
            if(arr.size() == 1) return arr[0];
            int n = arr.size();
            if(arr[0] != arr[1]) return arr[0];
            else if(arr[n - 1] != arr[n -2]) return arr[n - 1];

            int low = 1,high = n - 2;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(arr[mid - 1] != arr[mid] && arr[mid + 1] != arr[mid]) {
                    return arr[mid];
                } else if((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            return -1;
        }
};
int main() {
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for(int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    SingleElementInSortedArray s1;
    cout << "Single Element in Sorted Array : " << s1.SingleElementInArray(arr) << endl;
    return 0;
}