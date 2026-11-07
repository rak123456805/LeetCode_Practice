class Solution {
public:
    typedef pair<int,int>p;
    typedef tuple<long,int,int>t;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();
        vector<int>result(m);
        //free server
        priority_queue<p,vector<p>,greater<p>>freeserver;
        //busy server
        priority_queue<t,vector<t>,greater<t>>busyserver;
        for(int i=0;i<n;i++){
            freeserver.push({servers[i],i});
        }
        for(int i=0;i<m;i++){
            //move busy server to free server if they are free y ith time
            while(!busyserver.empty() &&get<0>(busyserver.top())<=i){
                auto [f,w,id]=busyserver.top();
                busyserver.pop();
                freeserver.push({w,id});
            }
            if(freeserver.empty()){
                auto [f,w,id]=busyserver.top();
                busyserver.pop();
                result[i]=id;
                busyserver.push({f+tasks[i],w,id});
            }else{
                auto [w,id]=freeserver.top();
                freeserver.pop();
                result[i]=id;
                busyserver.push({i+tasks[i],w,id});
            }
        }
        return result;
    }
};