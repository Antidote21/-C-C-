#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long min = 1;
    long long max = (long long)*max_element(times.begin(), times.end()) * n;
    
    while(min <= max){
        long long mid = (min + max)/2;
        long long sum = 0;
        for(int i=0; i<times.size(); i++){
            sum += (mid/(long long)times[i]);
        }
        if(sum >= n){
            max = mid - 1;
            answer = mid;
        }
        else min = mid + 1;
    }
    
    return answer;
}
