class TopVotedCandidate {
public:
    vector<int> times;
    vector<int> leader;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;

        unordered_map<int, int> cnt;
        int win = -1;

        for (int p : persons) {
            cnt[p]++;

            if (win == -1 || cnt[p] >= cnt[win]) {
                win = p;  // latest vote wins in a tie
            }

            leader.push_back(win);
        }
    }

    int q(int t) {
        int idx = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return leader[idx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */