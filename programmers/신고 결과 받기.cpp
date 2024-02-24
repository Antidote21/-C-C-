#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
        vector<int> answer(id_list.size(), 0);
        unordered_set<string> reportSet(report.begin(), report.end());

        unordered_map<string, vector<string>> notifyListHash;
        for (auto rep : reportSet) {
            int blankIdx = rep.find(" ");
            string reporter = rep.substr(0, blankIdx);
            string reportee = rep.substr(blankIdx + 1);

            vector<string>& reporterList = notifyListHash[reportee];
            reporterList.push_back(reporter);
        }

        unordered_map<string, int> reporterHash;
        for (auto notifyList : notifyListHash) {
            vector<string>& notifyVec = notifyList.second;
            if (notifyVec.size() >= k) {
                for (auto reporter : notifyVec) {
                    reporterHash[reporter]++;
                }
            }
        }

        for (size_t i = 0; i < id_list.size(); ++i) {
            answer[i] = reporterHash[id_list[i]];
        }
        return answer;
}
