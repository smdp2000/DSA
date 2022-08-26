class Solution {
public:
    int characterReplacement(string s, int k) {
         vector<int> counts(26, 0);
        int start = 0;
        int maxf = 0;
        int n = s.length();
        int result = 0;
        for(int end = 0; end < n; end++){
            counts[s[end]-'A']++;
            if(maxf < counts[s[end]-'A']){
                maxf = counts[s[end]-'A'];
            }
            while(end-start-maxf+1 > k){
                counts[s[start]-'A']--;
                start++;
              
            }
            result = max(result, end-start+1);
        }
        return result;
    }
};