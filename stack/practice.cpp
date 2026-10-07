#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') { //opening charcters
                st.push(s[i]);
            } else { ///closing charcters
                if(st.size() == 0) { // closing brackets > opening brackets
                    return false;
                }

                if((st.top() == '(' && s[i] == ')') ||
                    (st.top() == '{' && s[i] == '}') ||
                    (st.top() == '[' && s[i] == ']')) {
                    st.pop();
                } else { //no match
                    return false;
                }
            } 
        }

        return st.size() == 0;

    }
};