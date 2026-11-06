#include <iostream>
#include <vector>

#include <utility>
#include <numeric>

using namespace std;

class Solution {
public:
    int score(vector<string>& cards, char x) {
        vector<int> left(26, 0), right(26, 0);

        int both = 0;

        // Count eligible cards
        for (auto& card : cards) {
            if (card[0] == x && card[1] == x) {
                both++;
            }else if (card[0] == x) {
                left[card[1] - 'a']++;
            }else if (card[1] == x) {
                right[card[0] - 'a']++;
            }
        }

        // Maximum pairs possible within one group
        auto getPairs = [](vector<int>& freq) {
            int total = 0, maxFreq = 0;

            for (int f : freq) {
                total += f;
                maxFreq = max(maxFreq, f);
            }

            return min(total / 2, total - maxFreq);
        };

        int p1 = getPairs(left);
        int p2 = getPairs(right);

        int total = accumulate(left.begin(), left.end(), 0)
                  + accumulate(right.begin(), right.end(), 0);

        int maxInternal = p1 + p2;
        int ans = 0;

        // Try possible internal pair counts
        for (int p = 0; p <= maxInternal; p++) {
            int remaining = total - 2 * p;

            int points = p + min(both, remaining);

            ans = max(ans, points);
        }

        return ans;
    }
};
