#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();
    
    for(int i = 0; i < n; i++) {
        if (name[i] <= 'M') {
            answer += name[i] - 'A';
        } else {
            answer += 'Z' - name[i] + 1;
        }
    }
    
    int min_move = n - 1; 
    
    for (int i = 0; i < n; i++) {
        int next = i + 1;
     
        while (next < n && name[next] == 'A') {
            next++;
        }
      
        min_move = min(min_move, i + n - next + min(i, n - next));
    }
    
    answer += min_move;
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int total_moves = 0;  // 알파벳 변경과 커서 이동 횟수의 총합
    int length = name.size();  // 문자열 길이
    
    // 각 알파벳을 A로 바꾸는데 필요한 조이스틱 조작 횟수 계산
    for (char c : name) {
        total_moves += min(c - 'A', 'Z' - c + 1);  // 'A'에서 'Z'까지의 거리와 반대 방향의 거리 중 최솟값
    }
    
    int min_cursor_moves = length - 1;  // 커서 이동의 최소값
    
    // 커서 이동의 최소값을 계산
    for (int i = 0; i < length; i++) {
        int next = i + 1;
        
        // 연속된 'A'를 건너뛰기
        while (next < length && name[next] == 'A') {
            next++;
        }
        
        // 커서 이동의 최소값 갱신 (현재 위치에서 앞으로, 또는 뒤로 이동하는 경우 고려)
        min_cursor_moves = min(min_cursor_moves, i + length - next + min(i, length - next));
    }
    
    // 알파벳 변경 횟수와 커서 이동 횟수의 합이 정답
    return total_moves + min_cursor_moves;
}
