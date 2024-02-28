#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


struct Song {
    int index; // 고유 번호
    int play; // 재생 횟수
};

bool cmp(const Song& a, const Song& b) {
    if (a.play == b.play) {
        return a.index < b.index;
    }
    return a.play > b.play;
}

bool cmp2(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, vector<Song>> genreMap;
    unordered_map<string, int> playTotal;

    for (int i = 0; i < genres.size(); ++i) {
        genreMap[genres[i]].push_back({i, plays[i]});
        playTotal[genres[i]] += plays[i];
    }

    vector<pair<string, int>> sortedGenres(playTotal.begin(), playTotal.end());
    sort(sortedGenres.begin(), sortedGenres.end(), cmp2);

    for (const auto& genre : sortedGenres) {
        vector<Song>& songs = genreMap[genre.first];
        sort(songs.begin(), songs.end(), cmp);
        int count = 0;
        for (const auto& song : songs) {
            answer.push_back(song.index);
            if (++count >= 2) break; 
        }
    }

    return answer;
}
