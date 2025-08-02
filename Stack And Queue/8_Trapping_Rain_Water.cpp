#include <iostream>
#include <iomanip>
#include <thread>
#include <typeinfo>
#include <cstring>
#include <bits/stdc++.h>
#include <string>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <exception>
#include <stdexcept>
#include <fstream>
using namespace std;
int trap(vector<int> &height)
{
    int lmax, rmax, total = 0;
    lmax = rmax = 0;
    int l = 0, r = height.size() - 1;
    while (l < r)
    {
        if (height[l] <= height[r])
        {
            if (lmax > height[l])
            {
                total += (lmax - height[l]);
            }
            else
            {
                lmax = height[l];
            }
            l = l + 1;
        }
        else
        {
            if (rmax > height[r])
            {
                total += (rmax - height[r]);
            }
            else
            {
                rmax = height[r];
            }
            r = r - 1;
        }
    }
    return total;
}
int main()
{
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(v) << endl;
    return 0;
}