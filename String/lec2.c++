/**647. Palindromic Substrings
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.***/

class Solution {
public:
    int check(string s,int i,int j){
        int count=0;
        while(i>=0 && j<s.length() && s[i]==s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int count=0;
        for(int center=0;center<s.length();center++){
            //odd
            int i=center;
            int j=center;
            int oddLenPalindromCount=check(s,i,j);
            //even
            i=center;
            j=center+1;
            int evenLenPalindromCount=check(s,i,j);
            
            count+=oddLenPalindromCount+evenLenPalindromCount;
        }
        return count;
    }
};

/**1047. Remove All Adjacent Duplicates In String
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
We repeatedly make duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.
**/

class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            //NOW WE HAVE 2 OPTION 
            //IF THE LAST ELEMENT IS MATCHED WITH CURRENT ELEMENT
            if(ans.empty()){
                ans.push_back(s[i]);
            }else if(ans.back()!=s[i]){
                ans.push_back(s[i]);
            }
            //NOT MACTEHD
            else{
                //matched and remove last character from ans
                ans.pop_back();
            }
        }
        return ans;
    }
};