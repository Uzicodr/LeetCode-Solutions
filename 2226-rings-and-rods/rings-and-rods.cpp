class Solution {
public:
    int countPoints(string rings) {
        vector<tuple<bool, bool, bool>> rods(10, make_tuple(false, false, false));

        for (int i = 1; i < rings.length(); i += 2) {
            int rodidx = rings[i] - '0';
            if (rings[i - 1] == 'R') {
                get<0>(rods[rodidx]) = true;
            } else if (rings[i - 1] == 'G') {
                get<1>(rods[rodidx]) = true;
            } else if (rings[i - 1] == 'B') {
                get<2>(rods[rodidx]) = true;
            }
        }

        int ans = 0;
        for (int i = 0; i < 10; i++) {
            if (get<0>(rods[i]) && get<1>(rods[i]) && get<2>(rods[i])) {
                ans++;
            }
        }
        return ans;
    }
};
