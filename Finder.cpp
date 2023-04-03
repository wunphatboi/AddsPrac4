#include "Finder.h"
using namespace std;
vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result(s2.size(), -1);
    size_t last_found = string::npos;

    for (size_t i = 0; i < s2.size(); i++) {
        // Only search for prefix if the previous prefix was found
        size_t start_index = last_found == string::npos ? 0 : last_found + 1;
        size_t found = s1.find(s2.substr(0, i + 1), start_index);

        if (found != string::npos) {
            result[i] = found;
            last_found = found;
        }
    }

    return result;
};