class Solution {
public:
    string frequencySort(string s) {
     map<char,int>Counter;
     for(int i= 0;i<s.size();i++){
        Counter[s[i]]++;
     }
     priority_queue<pair<int,char>>pq;
      for (std::map<char, int>::iterator it = Counter.begin(); it != Counter.end(); ++it){
        pq.push(make_pair(it->second,it->first));
     }
     string res = "";
     while(!pq.empty()){
        pair<int,char>top = pq.top();
        pq.pop();
        res.append(top.first,top.second);
     }
     return res;
    }

};