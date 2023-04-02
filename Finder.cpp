#include "Finder.h"
using namespace std;
std::vector<int> Finder::findSubstrings(std::string s1, std::string s2){
    std::vector<int> result(s2.size(), -1); 
    std::unordered_map<std::string, int> index_map;
    for (int i = 0; i < s1.size(); ++i) {
        for (int j = 0; j < s2.size(); ++j) {
            std::string prefix = s2.substr(0, j + 1);
            if (index_map.find(prefix) == index_map.end() && s1.substr(i, j + 1) == prefix) {
                index_map[prefix] = i;
                result[j] = i;
            }
        }
        if (index_map.size() == s2.size()) {
            return result;
        }
    }
    return result;
}