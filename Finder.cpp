#include "Finder.h"
using namespace std;
std::vector<int> Finder::findSubstrings(std::string s1, std::string s2){
     vector<int> result;
    unordered_map<string, int> prefixMap;
    int n = s1.size(), m = s2.size();

    // create prefixMap with all prefixes of s2
    for (int i = 0; i < m; i++) {
        string prefix = s2.substr(0, i+1);
        if (prefixMap.find(prefix) == prefixMap.end()) {
            prefixMap[prefix] = -1;
        }
    }

    // search for prefixes in s1 and update prefixMap with their index
    for (int i = 0; i < n; i++) {
        string prefix = "";
        for (int j = i; j < n; j++) {
            prefix += s1[j];
            if (prefixMap.find(prefix) != prefixMap.end()) {
                if (prefixMap[prefix] == -1) {
                    prefixMap[prefix] = i;
                }
            }
        }
    }

    // add results to vector
    for (int i = 0; i < m; i++) {
        string prefix = s2.substr(0, i+1);
        if (prefixMap[prefix] == -1) {
            result.push_back(-1);
        } else {
            result.push_back(prefixMap[prefix]);
        }
    }

    return result;
};


