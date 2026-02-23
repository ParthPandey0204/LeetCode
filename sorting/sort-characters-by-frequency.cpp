class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> Counter;
        for(char c : s){
            Counter[c]++;
        }
        priority_queue<pair<int , char>>pq;
        for(auto p : Counter){
            pq.push({p.second , p.first});
        }
        string res = "";
        while(!pq.empty()){
            pair<int, char>top = pq.top();
            pq.pop();
            res.append(top.first , top.second);
        }
        return res;
    }
};