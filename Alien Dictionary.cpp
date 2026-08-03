// A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

// Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

// However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

// A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

// Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

// Examples:

// Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
// Output: true
// Explanation: A possible correct order of letters in the alien dictionary is "bdac".
// The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
// The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
// The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
// The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
// So, 'b' → 'd' → 'a' → 'c' is a valid ordering.
// Input: words[] = ["caa", "aaa", "aab"]
// Output: true
// Explanation: A possible correct order of letters in the alien dictionary is "cab".
// The pair "caa" and "aaa" suggests 'c' appears before 'a'.
// The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary. 
// So, 'c' → 'a' → 'b' is a valid ordering.
// Input: words[] = ["ab", "cd", "ef", "ad"]
// Output: ""
// Explanation: No valid ordering of letters is possible.
// The pair "ab" and "ef" suggests "a" appears before "e".
// The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
    string findOrder(vector<string> &words) { //bfs traversal
        // code here
        int n=words.size();
        
        vector<int>freq(26,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                freq[words[i][j]-'a']=1;
            }
        }
        
        int k=0;
        
        for(int i=0;i<26;i++)
        {
            k+=freq[i];
        }
        
        vector<vector<int>>adj(26);
        vector<int>indeg(26,0);
        
        for(int i=0;i<n-1;i++)
        {
            string s1=words[i],s2=words[i+1];
            int j=0,l=0;
            
            while(j<s1.size() && l<s2.size() && s1[j]==s2[l])
            j++,l++;
            
            if(j==s1.size())
            continue;
            
            if(j == s2.size() && s1.size() > s2.size())
            return "";
            
            adj[s1[j]-'a'].push_back(s2[l]-'a');
            indeg[s2[l]-'a']++;
            
        }
        
        queue<int>q;
        
        for(int i=0;i<26;i++)
        if(freq[i] && !indeg[i])
        q.push(i);
        string ans;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            char c='a'+node;
            ans+=c;
            
            for(int j=0;j<adj[node].size();j++)
            {
                indeg[adj[node][j]]--;
                if(!indeg[adj[node][j]])
                q.push(adj[node][j]);
            }
        }
        
        
        if (ans.size()!=k)
        return "";
        
        return ans;
    }
    
};