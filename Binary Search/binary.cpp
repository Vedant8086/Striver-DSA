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
class Convertion {
    public :
        Convertion() {
            cout << "Title : Binary To Decimal OR Decimal To Binary." << endl;
        }
        int BinToDec(int N) {
            int ans = 0,i = 0;
            while(N != 0) {
                int bit = N & 1;
                if(bit == 1) {
                    ans = ans+(bit * pow(10,i));
                }
                N = N >> 1;
                i++;
            }
            return ans;
        }
        int DecToBin(int N) {
            int ans = 0,i = 0;
            while(N != 0) {
                int digit = N % 10;
                if(digit == 1) {
                    ans = ans + pow(2,i);
                }
                N = N / 10;
                i++;
            }
            return ans;
        }
        ~Convertion() {
            cout << "---------------------------Program End!!------------------------------" <<endl;
        }

};
int main() {
    Convertion C1;
    int choice,N,result = 0,result1 = 0;
    cout << "Which Conversion You Want to make : " <<endl;
    cout << "\t" << "0.Decimal To Binary" << endl << "\t" << "1.Binary To Decimal." << endl;
    cin >> choice;
    switch (choice)
    {
        case 0 :
            cout << "Enter Decimal Number : ";
            cin >> N;
            result = C1.DecToBin(N);
            cout << "Binary : " << result << endl;
            break;
        case 1:
            cout << "Enter Binary Number : ";
            cin  >> N;
            result1 = C1.BinToDec(N);
            cout << "Decimal : " << result1<< endl;
            break;
        default:
            break;
    }
    
    
    return 0;
}