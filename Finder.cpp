#include "Finder.h"
using namespace std;
std::vector<int> Finder::findSubstrings(std::string s1, std::string s2){
    std::vector<int> result;
    std::unordered_map<std::string, int> prefixIndices;
    for (int i = 0; i < s2.length(); i++) {
        std::string prefix = s2.substr(0, i+1);
        if (prefixIndices.find(prefix) == prefixIndices.end()) {
            int index = s1.find(prefix);
            prefixIndices[prefix] = (index == std::string::npos) ? -1 : index;
        }
    }
    for (int i = 0; i < s2.length(); i++) {
        std::string prefix = s2.substr(0, i+1);
        result.push_back(prefixIndices[prefix]);
    }
    return result;
}