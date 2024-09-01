#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    if(lost.size()==n && reserve.size()==n)return n;
    
    answer = n - lost.size();
    
    for(int i=0; i<reserve.size(); i++){
        for(int j=i; j<lost.size(); j++){
            if(lost[j]==reserve[i])continue;
            if(lost[j]==reserve[i]-1||lost[j]==reserve[i]+1){
                answer++;
                break;
            }
        }
    }
    return answer;
}

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve){
    int answer = 0;
    
    vector<int> students(n,1);
    
    for(int l : lost){
        students[l-1]--;
    }
    
    for(int r : reserve){
        students[r-1]++;
    }
    
    for(int i=0; i<n; i++){
        if(students[i] == 0){
            if(i>0 && students[i-1] == 2){
                students[i]++;
                students[i-1]--;
            } else if(i<n-1 && students[i+1]==2){
                students[i]++;
                students[i+1]--;
            }
        }
    }
    
    for(int s : students){
        if(s >= 1){
            answer++;
        }
    }
    
    return answer;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for(int i=0; i<lost.size(); i++){
        for(int j=0; j<reserve.size(); j++){
            if(lost[i]==reserve[j]){
                lost[i] = 0;
                reserve[j] = 0;
            }
            else if(lost[i]+1==reserve[j]||lost[i]-1==reserve[j]){
                lost[i] = 0;
                reserve[j] = 0;
            }
        }
    }
    answer = n;
    for(int i=0; i<lost.size(); i++){
        if(lost[i]!=0){
            answer--;
        }
    }
    return answer;
}

#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> students(n, 1);
    
    for (int l : lost) {
        students[l - 1]--;
    }
    
    for (int r : reserve) {
        students[r - 1]++;
    }
    
    for (int i = 0; i < n; i++) {
        if (i > 0 && students[i] == 2 && students[i - 1] == 0) {
            students[i]--;
            students[i - 1]++;
        }
        else if (i < n - 1 && students[i] == 2 && students[i + 1] == 0) {
            students[i]--;
            students[i + 1]++;
        }
    }
    
    int answer = 0;
    for (int s : students) {
        if (s > 0) {
            answer++;
        }
    }
    
    return answer;
}
