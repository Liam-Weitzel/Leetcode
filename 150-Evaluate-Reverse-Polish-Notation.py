#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> tokenStack;
        string validOperators = "+-*/";

        for(int i = 0; i < tokens.size(); i++) {
            if(validOperators.find(tokens[i]) != std::string::npos) {
                //is an operator
                if (tokens[i] == "+") {
                    long second = tokenStack.top();
                    tokenStack.pop();
                    long first = tokenStack.top();
                    tokenStack.pop();
                    tokenStack.push(first+second);
                } else if (tokens[i] == "-") {
                    long second = tokenStack.top();
                    tokenStack.pop();
                    long first = tokenStack.top();
                    tokenStack.pop();
                    tokenStack.push(first-second);
                } else if (tokens[i] == "*") {
                    long second = tokenStack.top();
                    tokenStack.pop();
                    long first = tokenStack.top();
                    tokenStack.pop();
                    tokenStack.push(first*second);
                } else if (tokens[i] == "/") {
                    long second = tokenStack.top();
                    tokenStack.pop();
                    long first = tokenStack.top();
                    tokenStack.pop();
                    tokenStack.push(first/second);
                }
            } else {
                //is a number
                tokenStack.push(atoi(tokens[i].c_str()));
            }
        }

        return tokenStack.top();
    }
};