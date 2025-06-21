
class Solution {
public:
    int minimumDeletions(std::string word, int k) {
        unordered_map<char, int> freqMap;
        
        for (char ch : word) {
            freqMap[ch]++;
        }

        vector<int> freqs;
        for ( auto& [ch, count] : freqMap) {
            freqs.push_back(count);
        }

        // If no characters, no deletions needed
        if (freqs.empty()) return 0;

        // Sort frequencies
        sort(freqs.begin(), freqs.end());
        int n = freqs.size();
        int minDeletions = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int base = freqs[i];
            int deletions = 0;

            for (int j = 0; j < i; ++j) {
                deletions += freqs[j];  // Remove all lower freq
            }

            for (int j = i + 1; j < n; ++j) {
                if (freqs[j] > base + k) {
                    deletions += freqs[j] - (base + k);
                }
            }

            // Update minimum deletions
            minDeletions = min(minDeletions, deletions);
        }

        return minDeletions;
    }
};
