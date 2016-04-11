#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int strCount(const char *haystack, const char *needle) {
        if (strlen(needle) == 0) return 0;
        if (strlen(haystack) == 0) return 0;
        int i, j;
        int ct = 0;

        int lenH = strlen(haystack), lenN = strlen(needle);
        int next[lenN+1];
        j = -1;
        next[0] = -1;
        i = 1;
        while (i < lenN) {
            while (j >= 0 && needle[i] != needle[j+1]) j = next[j];
            if (needle[i] == needle[j+1]) j++;
            next[i] = j;
            i++;
        }

        i = 0;
        j = -1;
        while (i < lenH) {
            while (j >= 0 && haystack[i] != needle[j+1]) j = next[j];
            if (haystack[i] == needle[j+1]) j++;
            if (j + 1 == lenN) ct++;
            i++;
        }
        return ct;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        string needle, haystack;
        cin >> needle >> haystack;
        cout << strCount(haystack.c_str(), needle.c_str()) << endl;
    }
    
    return 0;
}
