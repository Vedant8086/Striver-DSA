#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<iomanip>
#include<bits/stdc++.h>
//Binary search need an sorted array either asending.
using namespace std;

class Binary_Search {
	public : 
		Binary_Search() {
			cout << "Binary Search started..." << endl;
		}
		int Searching(int arr[],int size,int target) {
			int start = 0;
			int end = size -1;
			int mid = (start + end) / 2;
			while(start <=end) {
				if(arr[mid] == target) {
					return mid;
				}
				if(target > arr[mid]) {
					start = mid + 1;
				}
				else {
					end = mid - 1;
				}
				
				mid = (start+end)/2;
			}
			return -1;
		}
		~Binary_Search() {
			cout << "Binary Search had completed...." << endl;
		}
};
int main() {
	
	Binary_Search b1;
	int size,target;
	cout << "Enter the size of array : ";
	cin >> size;
	int arr[size];
	for(int i = 0;i < size;i++) {
		cin >> arr[i];
	}
	cout << "Enter the target element  : ";
	cin  >> target;
	int index = b1.Searching(arr,size,target);
	cout << "The element is at position : " << (index+1) << endl;
	return 0;
}