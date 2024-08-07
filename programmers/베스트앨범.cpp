#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Song{
    int num;
    int count;
};

bool cmp(const Song& a, const Song& b){
    if(a.count==b.count){
        return a.num<b.num;
    }
    return a.count > b.count;
}

bool cmp2(const pair<string, int> &a, const pair<string, int> & b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<Song>> genreMap;
    unordered_map<string, int> totalPlays;  
    
    for(int i=0; i<genres.size(); i++){
        genreMap[genres[i]].push_back({i,plays[i]});
        totalPlays[genres[i]] +=plays[i];
    }
    vector<pair<string, int>> sortedGenres(totalPlays.begin(), totalPlays.end());
    sort(sortedGenres.begin(), sortedGenres.end(), cmp2);
    
    for(auto genre : sortedGenres){
        vector<Song>& songs = genreMap[genre.first];
        sort(songs.begin(), songs.end(), cmp);
        int cnt=0;
        for(auto song: songs){
            answer.push_back(song.num);
            if(++cnt>=2)break;
        }
    }
    return answer;
}

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

// Song 구조체 정의
struct Song {
    string genre;
    int play;
    int id;
};

// 장르별 총 재생 횟수를 저장하는 구조체 정의
struct GenreInfo {
    string genre;
    int totalPlay;
};

// Song 정렬을 위한 비교 함수
bool compareSongs(const Song& a, const Song& b) {
    if (a.play == b.play) return a.id < b.id;
    return a.play > b.play;
}

// GenreInfo 정렬을 위한 비교 함수
bool compareGenres(const GenreInfo& a, const GenreInfo& b) {
    return a.totalPlay > b.totalPlay;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<Song>> genreMap; // 장르별 Song 리스트
    unordered_map<string, int> genrePlayCount; // 장르별 총 재생 횟수

    // 입력 데이터를 기반으로 데이터 구조 초기화
    for (int i = 0; i < genres.size(); i++) {
        genreMap[genres[i]].push_back({genres[i], plays[i], i});
        genrePlayCount[genres[i]] += plays[i];
    }

    // 장르별 Song 리스트 정렬
    for (auto& entry : genreMap) {
        sort(entry.second.begin(), entry.second.end(), compareSongs);
    }

    // GenreInfo 리스트 생성 및 정렬
    vector<GenreInfo> genreInfos;
    for (const auto& entry : genrePlayCount) {
        genreInfos.push_back({entry.first, entry.second});
    }
    sort(genreInfos.begin(), genreInfos.end(), compareGenres);

    // 결과 생성
    for (const auto& genreInfo : genreInfos) {
        const auto& songs = genreMap[genreInfo.genre];
        for (int i = 0; i < min(2, static_cast<int>(songs.size())); i++) {
            answer.push_back(songs[i].id);
        }
    }

    return answer;
}
