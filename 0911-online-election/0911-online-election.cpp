class TopVotedCandidate {
public:
    vector<int> times;
    vector<int> leader;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
         int win=-1;
        unordered_map<int,int>mp;
        for(auto &p : persons){
            mp[p]++;
            if(win==-1 || mp[p]>=mp[win]){
                win=p;
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