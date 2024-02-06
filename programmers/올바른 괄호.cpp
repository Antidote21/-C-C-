#include<string>
#include<stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;
    int cnt = 0;
    int size = s.size();
    
    for(int i=0; i<s.size(); i++){
        st.push(s[i]);
    }
    
    if(st.top()=='('){
        answer=false;
        return answer;
    }
    
    while(!st.empty()){
        if(st.top()==')'){
            st.pop();
            cnt+=1;
        }else{
            st.pop();
        }
    }
    if((size-cnt)!=cnt)answer=false;
    else answer=true;
    
    return answer;
}
//괄호 개수를 각각 판단하여 사용하는 것만으로는 부족 && 굳이 stack에 push하고 그걸 다시 꺼내면서 검사는 비효율적

#include <string>
#include <stack>

using namespace std;

bool solution(string s) {
    stack<char> st;
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push(s[i]);
        } else if(s[i] == ')') {
            if(!st.empty()) {
                st.pop();
            } else {
                return false; 
            }
        }
    }

    return st.empty();
}
