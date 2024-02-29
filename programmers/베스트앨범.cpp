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
