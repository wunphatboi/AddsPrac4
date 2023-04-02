#include "Finder.h"
using namespace std;
std::vector<int> Finder::findSubstrings(std::string s1, std::string s2){
    std::vector<int> occurrences;
    for (int i = 1; i <= s2.length(); i++) {
        std::string prefix = s2.substr(0, i);
        if (s1.find(prefix) == std::string::npos) {
            occurrences.push_back(-1);
        } else {
            occurrences.push_back(s1.find(prefix));
        }
    }
    return occurrences;
}