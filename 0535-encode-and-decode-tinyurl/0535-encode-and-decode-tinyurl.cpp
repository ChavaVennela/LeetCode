class Solution {
public:
    long long a=0;
    map<string, string>mymap;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string p=to_string(a);
        mymap[p]=longUrl;
        a++;
        return p;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mymap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));