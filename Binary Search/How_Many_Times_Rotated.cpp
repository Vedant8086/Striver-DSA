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
class HowManyTimesRotated {
    public : 
        pair<int,int> HowManyTimes(vector<int>& arr) {
            int low = 0,high = arr.size() - 1,index = -1,ans = INT_MAX;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(arr[low] <= arr[mid]) {
                    if(arr[low] <= ans) {
                        index = low;
                        ans = arr[low];
                    }
                    low = mid + 1;
                } else {
                    high = mid - 1;
                    if(arr[mid] < ans) {
                        ans = arr[mid];
                        index = mid;
                    }
                }
            }

            return {ans, index};
        }
};
int main() {
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for(int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    HowManyTimesRotated h1;
    cout << h1.HowManyTimes(arr).first << " is minimum and " << h1.HowManyTimes(arr).second << " is the count of array rotation." << endl;
    return 0;
}