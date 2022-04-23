class Solution {
public:
    unordered_map<string, string> code, url;
    const string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    
    
    string getcode(){
        
        string code = "";
        for (int i = 0; i < 6; i++) code += chars[rand() % 62];
        return "http://tinyurl.com/" + code;
    }

    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(url.find(longUrl)!=url.end()) return url[longUrl];
        
        string cod = getcode();
        
        while(code.find(cod)!=code.end())
            cod = getcode();
        
        code[cod] = longUrl;
        url[longUrl] = cod;
        return cod;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
                return code[shortUrl];

        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));