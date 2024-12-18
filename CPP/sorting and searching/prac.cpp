#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    float val;
    cin >> val;
    string s = to_string(val);
    int decimalPos = s.find('.');
    if (decimalPos != string::npos && s.length() > decimalPos + 3) {
        s = s.substr(0, decimalPos + 4);
    }
    int countTrailingZeros = 0;
    int i = s.length() - 1;
    while (i > 0 && (s[i] == '0' || s[i] == '.')) {
        if (s[i] == '0') {
            countTrailingZeros++;
        }
        if (s[i] == '.') {
            break;
        }
        i--;
    }
    s.erase(s.length() - countTrailingZeros, countTrailingZeros);
    if (s.back() == '.') {
        s.pop_back();
    }
    cout << s << endl;
    return 0;
}