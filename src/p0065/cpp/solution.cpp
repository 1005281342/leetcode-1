#include <iostream>
#include <string>
#include <cstdlib>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool isNumber(const string &s) {
        int curr = 1;
        for (auto c : s) {
            switch (curr) {
            case 1:
                if (isblank(c)) { curr = 1; break; }
                if ( issign(c)) { curr = 2; break; }
                if (isdigit(c)) { curr = 3; break; }
                if (  isdot(c)) { curr = 4; break; }
                return false;
            case 2:
                if (isdigit(c)) { curr = 3; break; }
                if (  isdot(c)) { curr = 4; break; }
                return false;
            case 3:
                if (isdigit(c)) { curr = 3; break; }
                if (  isdot(c)) { curr = 5; break; }
                if (  isexp(c)) { curr = 6; break; }
                if (isblank(c)) { curr = 9; break; }
                return false;
            case 4:
                if (isdigit(c)) { curr = 5; break; }
                return false;
            case 5:
                if (isdigit(c)) { curr = 5; break; }
                if (  isexp(c)) { curr = 6; break; }
                if (isblank(c)) { curr = 9; break; }
                return false;
            case 6:
                if ( issign(c)) { curr = 7; break; }
                if (isdigit(c)) { curr = 8; break; }
                return false;
            case 7:
                if (isdigit(c)) { curr = 8; break; }
                return false;
            case 8:
                if (isdigit(c)) { curr = 8; break; }
                if (isblank(c)) { curr = 9; break; }
                return false;
            case 9:
                if (isblank(c)) { curr = 9; break; }
                return false;
            }
        }
        return curr == 3 || curr == 5 || curr == 8 || curr == 9;
    }

private:
    bool issign(char c) { return c == '+' || c == '-'; }
    bool isdot(char c) { return c == '.'; }
    bool isexp(char c) { return c == 'e'; }
};
