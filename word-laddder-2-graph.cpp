class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(st.find(endWord) == st.end())
            return {};
        st.erase(beginWord);
        queue<vector<string>>q;
        q.push({beginWord});
        vector<string>usedlevel;
        usedlevel.push_back(beginWord);
        int level=1;
        vector<vector<string>>ans;
        while(!q.empty()){

    vector<string> vec=q.front();
    q.pop();

    if(!ans.empty() && vec.size() > ans[0].size())
        break;

    if(vec.size()>level){

        level=vec.size();

        for(const auto &it:usedlevel)
            st.erase(it);

        usedlevel.clear();
    }

    string word=vec.back();

    if(word==endWord){

        if(ans.empty())
            ans.push_back(vec);
        else if(ans[0].size()==vec.size())
            ans.push_back(vec);

        continue;
    }

    for(int i=0;i<word.size();i++){

        char original=word[i];

        for(char c='a';c<='z';c++){

            if(c==original)
                continue;

            word[i]=c;

            if(st.count(word)){

                vec.push_back(word);

                q.push(vec);

                usedlevel.push_back(word);

                vec.pop_back();
            }
        }

        word[i]=original;
    }
}
        return ans;
    }
};
