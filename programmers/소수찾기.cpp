#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

bool isPrime(int n){
    if(n<2)return false;
    for(int i=2; i<=sqrt(n); ++i){
        if(n%i==0)return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int>ans{};
    
    sort(numbers.begin(), numbers.end());
    
    do{
        string tmp;
        for(int i=0; i<numbers.size(); ++i){
            tmp += numbers[i];
            if(isPrime(stoi(tmp)))
                ans.insert(stoi(tmp));
        }
    }
    while(next_permutation(numbers.begin(), numbers.end()));
    answer = ans.size();
    return answer;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;

// 소수 판별 함수
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// 모든 조합을 생성하는 함수
void generate_permutations(string numbers, string current, unordered_set<int>& unique_numbers) {
    if (!current.empty()) {
        int num = stoi(current);
        unique_numbers.insert(num);
    }
    for (int i = 0; i < numbers.size(); i++) {
        generate_permutations(numbers.substr(0, i) + numbers.substr(i + 1), current + numbers[i], unique_numbers);
    }
}

int solution(string numbers) {
    unordered_set<int> unique_numbers;

    // 모든 숫자 조합을 생성
    generate_permutations(numbers, "", unique_numbers);

    // 소수 개수를 세기 위한 변수
    int prime_count = 0;

    // 각 숫자가 소수인지 확인
    for (int num : unique_numbers) {
        if (is_prime(num)) {
            prime_count++;
        }
    }

    return prime_count;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    unordered_set<int> unique_numbers;
    sort(numbers.begin(), numbers.end());  
    
    do {
        for (int i = 1; i <= numbers.size(); i++) {
            int num = stoi(numbers.substr(0, i));
            unique_numbers.insert(num);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));  
    
    int prime_count = 0;
    
    for (int num : unique_numbers) {
        if (is_prime(num)) {
            prime_count++;
        }
    }
    
    return prime_count;
}
