#include "Finder.h"
using namespace std;
std::vector<int> Finder::findSubstrings(std::string s1, std::string s2){
    std::vector<int> result;
    std::unordered_map<std::string, int> prefix_map;
    for (int i = 0; i < s2.length(); i++) {
        std::string prefix = s2.substr(0, i+1);
        if (prefix_map.find(prefix) == prefix_map.end()) {
            int index = s1.find(prefix);
            prefix_map[prefix] = index;
        }
    }
    for (int i = 0; i < s2.length(); i++) {
        std::string prefix = s2.substr(0, i+1);
        int index = prefix_map[prefix];
        result.push_back(index == std::string::npos ? -1 : index);
    }
    return result;
};
