class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int i,j,cnt;
        i=j=cnt=0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        while(i<players.size() && j<trainers.size()){
            if(players[i]<=trainers[j]){
                cnt++;
                i++;
            }
            j++;
        }
        return cnt;
    }
};