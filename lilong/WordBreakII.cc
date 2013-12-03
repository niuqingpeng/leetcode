class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> result;
        if(checkLetter(s, dict)){
            genWordList(s, dict, result, "");    
        }
        return result;
    }
    
    //pruning: if the letter in s don't occure in the dictionary, we don't bother to run the expensive recursion.
    bool checkLetter(string s, unordered_set<string> &dict){
        int strLen = s.length();
        for(int i = 0; i < strLen; ++i){
            int flag = 0;
            for(auto iter = dict.begin(); iter!= dict.end(); ++iter){
                if((*iter).find_first_of(s[i]) != -1){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                return false; 
            }
        }
        return true;
    }

    void genWordList(string s, unordered_set<string> &dict, vector<string> &result, string item){
        int strLen = s.length();
        unordered_set<string>::const_iterator iter;
        
        if(strLen == 0){
            result.push_back(item);
            return;
        }    
        
        for(int len = 1; len <= strLen; ++len){
            string subStr = s.substr(0, len);
            iter = dict.find(subStr);
            if(iter != dict.end()){
                string tmpItem = "";
                if(item.length() > 0) tmpItem = item + " " + subStr;  
                else tmpItem = subStr;
                genWordList(s.substr(len), dict, result, tmpItem);
            }
        }
        
        return;
    }
};
