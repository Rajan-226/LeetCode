class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> vis(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        int ans=2;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                string temp=q.front();
                q.pop();
                for(int j=0;j<temp.size();j++){
                    char ch=temp[j];
                    for(char c='a';c<='z';c++){
                        temp[j]=c;
                        if(vis.find(temp)!=vis.end()){
                            if(temp==endWord)   return ans;
                            q.push(temp);
                            vis.erase(temp);
                        }
                    }
                    temp[j]=ch;
                }
                
                
            }
            ans++;
        }
        return 0;
    }
};