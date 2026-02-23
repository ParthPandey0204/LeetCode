class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       if(strs.empty()) return "";
       string common_string = strs[0];
       for(int i = 1 ; i < strs.size(); i++){
        string temp = strs[i];
        int j =0;
        while(j < common_string.size() && j< temp.size() && common_string[j]== temp[j]){
        j++;
        }
     common_string = common_string.substr(0,j);
     if(common_string.empty())
      return "";
       }
      return common_string;
    }
};