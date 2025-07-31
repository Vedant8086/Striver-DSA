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
int prec(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}
string Infix_To_Postfix(string s) {

  stack < char > st; 
  string result;

  for (int i = 0; i < s.length(); i++) {
    char c = s[i];

    
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
      result += c;

    
    else if (c == ')')
      st.push(')');

    else if (c == '(') {
      while (st.top() != ')') {
        result += st.top();
        st.pop();
      }
      st.pop();
    }

    else {
      while (!st.empty() && prec(s[i]) <= prec(st.top())) {
        result += st.top();
        st.pop();
      }
      st.push(c);
    }
  }

  while (!st.empty()) {
    result += st.top();
    st.pop();
  }
  return result;
}
string Infix_To_Prefix(string s) {
    reverse(s.begin(), s.end()); 
    string ss = Infix_To_Postfix(s);
    reverse(ss.begin(), ss.end()); 
    return ss;
}

int main() {
    string s = "x + y - z";
    cout << Infix_To_Prefix(s) << endl;
    return 0;
}