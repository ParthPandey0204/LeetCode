class Solution {
public:
    int beautySum(string s) {
    int total_beauty = 0;
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        unordered_map<char, int> freq;
        int max_freq = 0;
        int min_freq = INT_MAX;

        for (int j = i; j < n; ++j) {
            char c = s[j];
            freq[c]++;
            max_freq = max(max_freq, freq[c]);
            
            min_freq = INT_MAX;
            for (const auto& entry : freq) {
                if (entry.second > 0) {
                    min_freq = min(min_freq, entry.second);
                }
            }
            
            total_beauty += (max_freq - min_freq);
        }
    }
    
    return total_beauty;
    }
};