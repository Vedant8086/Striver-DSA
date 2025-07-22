#include<iostream>
#include<iomanip>
#include<bits/stdc++.h>

using namespace std;

class insertionsort { 
	public : 
		insertionsort() {
			cout << "Insertion sort algorithm." << endl;
		}
		void insertion_sort(vector<int>& arr) {
			int sizes = arr.size();
			for(int i = 1;i < sizes;i++) {
				int key = arr[i];
				int j = i - 1;
				while(j >= 0 && arr[j] > key) {
					arr[j+1] = arr[j];
					j--;
				}
				
				arr[j+1] = key;
			}
		}
};
class Rinsertionsort {
	public : 
		Rinsertionsort() {
			cout << "Reverse Insertion Sort." << endl;
		}
		void rinsertion_sort(vector<int>& arr) {
			int sizes = arr.size();
			for(int i = 1;i < sizes;i++) {
				int key = arr[i];
				int j = i -1;
				while(j >= 0 && arr[j] < key) {
					arr[j+1] = arr[j];
					j--;
				}
				
				arr[j+1] = key;
			}
		}
};
int main() {
	insertionsort sort;
	Rinsertionsort Rsort;
	int n ; 
	cout << "Enter the element : ";
	cin >> n;
	vector<int> arr;
	for(int i = 0;i < n;i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	vector<int> new_arr = arr;
	sort.insertion_sort(arr);
	Rsort.rinsertion_sort(new_arr);
	for(int j = 0;j < n;j++) {
		cout << arr[j] << " ";
	}
	cout << endl;
	cout << "Reversed Sorted Array Using Insertion Sort : " << endl;
	
	for(int j = 0;j < n;j++) {
		cout << new_arr[j] << " ";
	}
	cout << endl;
}