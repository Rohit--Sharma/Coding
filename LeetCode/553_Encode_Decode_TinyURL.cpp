#include <iostream>
#include <string>
#include <map>
#include <time.h>

using namespace std;

class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while(myMap.find(key) != myMap.end()) {
            key = getRand();
        }
        myMap[key] = longUrl;
        return "https://tinyurl.com/" + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return myMap[shortUrl.substr(20, 6)];
    }

private:
    string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<string, string> myMap;
    int random = rand();
    string key = getRand();

    string getRand() {
        string sb;
        for (int i = 0; i < 6; i++) {
            sb += alphabet[rand() % 62];
        }
        return sb;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main()
{
    srand(time(NULL));

    Solution solution;
    cout << Solution().encode("https://www.google.com/") << endl;
    cout << solution.decode(solution.encode("https://www.google.com/")) << endl;

    return 0;
}