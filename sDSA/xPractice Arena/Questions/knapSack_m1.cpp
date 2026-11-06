/* Question : Fractional Knapsack
   Methods:
   - solve_greedy()  : fractional knapsack (greedy)
   - solve_01()      : 0/1 knapsack (dp)          [todo]
   - solve_bounded() : bounded knapsack            [todo]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class KnapSack {
private:

    vector<int> price;
    vector<int> weight;
    int capacity;

    // ── helpers ──────────────────────────────────────────
    struct Group {
        float ratio;
        int   price;
        int   weight;
    };

    static bool Comparator(const Group& a, const Group& b) {
        return a.ratio > b.ratio;
    }

    bool isValid() {
        return price.size() == weight.size() && !price.empty();
    }

public:

    // ── constructor ───────────────────────────────────────
    KnapSack(vector<int> p, vector<int> w, int cap)
        : price(p), weight(w), capacity(cap) {}

    // ── method 1 : greedy (fractional) ───────────────────
    float solve_greedy() {

        if (!isValid()) return 404;

        int nSize = price.size();

        vector<Group> items(nSize);
        for (int i = 1; i < nSize; i++) {
            items[i] = { (float)price[i] / weight[i], price[i], weight[i] };
        }
        sort(items.begin() + 1, items.end(), Comparator);

        int   currentWeight = 0;
        float currentProfit = 0;

        for (int i = 1; i < nSize; i++) {

            if (currentWeight + items[i].weight <= capacity) {
                currentWeight += items[i].weight;
                currentProfit += items[i].price;
            } else {
                int   remaining = capacity - currentWeight;
                float fracProfit = ((float)remaining / items[i].weight) * items[i].price;
                currentProfit += fracProfit;
                break;
            }
        }

        return currentProfit;
    }

    // ── method 2 : dp (0/1 knapsack) ─────────────────────
    int solve_01() {
        if (!isValid()) return -1;

        int nSize = price.size() - 1;  // exclude dummy at [0]

        // dp[i][w] = max profit using first i items with capacity w
        vector<vector<int>> dp(nSize + 1, vector<int>(capacity + 1, 0));

        for (int i = 1; i <= nSize; i++) {
            for (int w = 0; w <= capacity; w++) {

                // option 1 — skip item i
                dp[i][w] = dp[i-1][w];

                // option 2 — take item i (only if it fits)
                if (weight[i] <= w) {
                    int take = dp[i-1][w - weight[i]] + price[i];
                    dp[i][w] = max(dp[i][w], take);
                }
            }
        }

        return dp[nSize][capacity];
    }

    // ── method 3 : bounded knapsack ──────────────────────
    int solve_bounded() {
        // todo
        return -1;
    }
};

// ── MAIN ──────────────────────────────────────────────────
int main() {
    //! all in 1-based indexing
    vector<int> price  = {0, 25, 24, 15};
    vector<int> weight = {0, 18, 15, 10};
    int capacity = 20;

    KnapSack ks(price, weight, capacity);

    cout << "Greedy  : " << ks.solve_01()  << endl;

    return 0;
}

/*
   Test cases:
   vector<int> price  = {0, 25, 24, 15};
   vector<int> weight = {0, 18, 15, 10};
   capacity = 20;
   expected greedy = 31.5
*/
