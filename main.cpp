#include <iostream>
#include "Finder.h"
#include <string>
using namespace std;

int main(void){
    Finder f;
    string n1 = "4634554567";
    string n2 = "45689";
    vector<int> find = f.findSubstrings(n1,n2);
    for (int i = 0; i < find.size(); i++){
        cout << find.at(i) << endl;
    }
    return 0;
}