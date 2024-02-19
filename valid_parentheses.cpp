#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
    stack<char> stk;

    for(auto c:s){
        if ( c== '(' || c == '{' || c == '[') {
            stk.push(c);
        } else { 
            if( !stk.empty() && stk.top() == '('  && c==')'){
                stk.pop();
            } else if( !stk.empty() && stk.top() == '{' && c == '}'){
                stk.pop();
            } else if( !stk.empty() && stk.top() == '[' && c==']'){
                stk.pop();
            } else{
                return false;
            }
        }
    } 
    if(stk.empty()) {
        return true;
    } else { 
        return false;
    }
}

int main(int argc, char* argv[]) {
    cout << boolalpha << isValid(argv[1]) << endl;
    return 0;
}

// use command line argument to send a string to the function. output is either true or false.