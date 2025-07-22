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
        bool search(vector<int>& nums,int target) {
            int low = 0,high = nums.size() - 1;
            while(low <= high) {
                int mid = (low + high) / 2;
                if(nums[mid] == target) return true;

                if(nums[low] == nums[mid] && nums[high] == nums[mid]) {
                    low++;high--;
                    continue;
                }
                if(nums[low] <= nums[mid]) {
                    if(nums[low]<= target && target <= nums[mid]) {
                        high = mid - 1;
                    }
                    else {
                        low = mid + 1;
                    }
                }
                else {
                    if(nums[mid] <= target && target <= nums[high]) {
                        low = mid + 1;
                    }
                    else {
                        high = mid - 1;
                    }
                }
        }
	    return false;
    }
};
int main() {
    int n;
    cout << "Enter the Number : ";
    cin >> n;
    vector<int> arr;
    for(int  i=0;i < n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    Solution s1;
    int target;
    cout << "Enete the Target : ";
    cin >> target;
    s1.search(arr,target);
    return 0;
}