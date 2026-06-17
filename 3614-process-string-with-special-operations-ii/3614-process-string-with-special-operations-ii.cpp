class Solution {
public:
    char processStr(string s, long long k) {
        vector<long long> len(s.size() + 1, 0);

        const long long LIM = (long long)4e18;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c >= 'a' && c <= 'z') {
                len[i + 1] = min(LIM, len[i] + 1);
            }
            else if (c == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            }
            else if (c == '#') {
                len[i + 1] = min(LIM, len[i] * 2);
            }
            else { // '%'
                len[i + 1] = len[i];
            }
        }

        if (k >= len[s.size()]) return '.';

        for (int i = (int)s.size() - 1; i >= 0; i--) {
            char c = s[i];

            long long curLen = len[i + 1];
            long long prevLen = len[i];

            if (c >= 'a' && c <= 'z') {
                if (k == prevLen) return c;
            }
            else if (c == '*') {
                // backward: deleted char reappears at end
            }
            else if (c == '#') {
                if (k >= prevLen) k -= prevLen;
            }
            else { // '%'
                k = prevLen - 1 - k;
            }
        }

        return '.';
    }
};