#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, int> um;
    for(int i=0; i<nums.size(); i++){
        um.insert(make_pair(nums[i], i));
    }
    int cnt = nums.size()/2;

    if(um.size()>cnt){
        answer = cnt;
    }else{
        answer=um.size();
    }
    return answer;
}
