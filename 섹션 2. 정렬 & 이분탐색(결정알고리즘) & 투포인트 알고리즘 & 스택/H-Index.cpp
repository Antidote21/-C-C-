#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> citations  = {3, 0, 6, 1, 5};

int binarySearch(int A[], int low, int high, int target){
    while(low <= high){
        int mid = (low + high) / 2;
        if(A[mid] == target) return mid;
        if(A[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int solution( vector<int> a) {
    int answer = 0;
    int k = citations.size();
    sort(citations.begin(), citations.end());
    answer = citations[0];
    int lt=0, rt=k;

    for(int i=0; i<k; i++){
        if(citations[i]>=answer){
            lt++;
            rt=k-lt;
            answer=lt;
        }else if(citations[i]<=answer){
            if(answer>=lt&&answer>=rt-lt)break;
        }
    }
    return answer;
}

int main(){
    int res;
    res = solution(citations);
    cout<<res;
}
