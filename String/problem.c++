/**Given a string s, your task is to reverse only the alphabetical letters in the string, keeping all non-alphabetical characters in their original positions. The modified string should maintain the original length and order of non-letter characters. */
class Solution {
public:
    string reverseOnlyLetters(const string& s) {
        // Implement logic to reverse only the letters in `s`
      int n=s.length();
      int i=0,j=n-1;
      string ans=s;
      while(i<j){
       while(i<j && !isalpha(ans[i])){
            i++;
        }
       while(i<j && !isalpha(ans[j])){
            j--;
        }
        if(i<j){
            swap(ans[i],ans[j]);
            i++;
            j--;
        }
      }
      return ans;
    }
};

/**234. Longest Common Prefix in a String
Given an array of strings strs, your task is to find the longest common prefix string among them. If there is no common prefix, return an empty string "". */
class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        // Implement logic to find the longest common prefix
        // string ans="";
        string s=strs[0];
        // sort(s.begin(),s)
        for(int i=1;i<strs.size();i++){
            string temp="";
            for(int j=0;j<s.size() && j<strs[i].size(); j++){
                if(strs[i][j]==s[j]){
                    temp+=s[j];
                }else{
                    break;
                }
            }
            s=temp;
            if(s=="")return "";
        }
        return s;
    }
};

/**235. Reverse Vowels of a String
Your task is to implement a function that takes a string s as input and returns the string after reversing only its vowels. Vowels in this context are 'a', 'e', 'i', 'o', 'u', and they can appear in both lowercase ('a', 'e', 'i', 'o', 'u') and uppercase ('A', 'E', 'I', 'O', 'U') forms. The order and position of the consonants and other non-vowel characters in the string should remain unchanged. */
class Solution {
public:
    bool isVowel(char ch){
        ch=tolower(ch);
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    string reverseVowels(const string& s) {
        // Implement logic to reverse only vowels in `s`
        string sh=s;//as s is sent as const so we have to make a copy
        int st=0,end=sh.length()-1;
        while(st<end){
            if(isVowel(sh[st]) && isVowel(sh[end])){
                swap(sh[st],sh[end]);
                st++;end--;
            }else if(isVowel(sh[st])==0){//s[st] is not vowel
                st++;
            }else{//s[end] is not vowel
                end--;
            }
        }
        return sh;
    }
};

/**237. Reorganize String
Given a string s, your task is to rearrange the characters so that no two adjacent characters are the same. If rearrangement is not possible, return an empty string "". */
class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {0};

        for(int i=0; i<s.size(); i++){
            hash[s[i]-'a']++;
        }

        // Find most freq. char
        char max_freq_char;
        int max_freq = INT_MIN;
        for(int i=0; i<26; i++){
            if(hash[i] > max_freq){
                max_freq = hash[i];
                max_freq_char = i + 'a';
            }
        }
        
        if(max_freq > (s.size() + 1) / 2) {
            return "";
        }

        int index = 0;
        while(max_freq > 0){
            s[index] = max_freq_char;
            --max_freq;
            index += 2;
        }

        hash[max_freq_char - 'a'] = 0;

        // Fill rest of the chars
        for(int i=0; i<26; i++){
            while(hash[i] > 0){
                index = index >= s.size() ? 1 : index;
                s[index] = i + 'a';
                hash[i]--;
                index += 2;
            }
        }
        return s;
    }
};

/**238. Group Anagrams
Given an array of strings strs, your task is to group the anagrams together. An anagram is a word or phrase formed by rearranging the letters of another, using all the original letters exactly once. For instance, the words listen and silent are anagrams of each other.
The output can be returned in any order, where each group of anagrams is represented as a separate list of strings. This means if two or more words in the input can be rearranged only using the same letters, they should appear together in the output. */

class Solution {
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        // Implement logic to group anagrams
        unordered_map<string,vector<string>>mpp;
        int n=strs.size();

        for(int i=0;i<n;i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(strs[i]);
        }

        vector<vector<string>>ans;
        for(auto& it:mpp){
            sort(it.second.begin(),it.second.end());
            ans.push_back(it.second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

/**240. Find the Index of the First Occurrence in a String
In this problem, you are given two strings: haystack and needle. Your task is to find the index at which the string needle first occurs in the string haystack. Return this index as an integer. If needle is not a substring of haystack, you should return -1. */
class Solution {
public:
    int strStr(const string& haystack, const string& needle) {
        // Implement logic to find the first occurrence of `needle` in `haystack`
        int m=haystack.size();
        int n=needle.size();
        
        if(n>m)return -1;

        for(int i=0;i<=m-n;i++){
            if(haystack.substr(i,n)==needle){
                return i;
            }
        }
        return -1;
    }
};

/**245. Remove All Adjacent Duplicates in String II
Given a string s, a duplicate removal operation will remove k adjacent duplicates from the string. Your task is to repeatedly perform this operation until no more k-duplicate removals can be done, and return the resulting string.
A duplicate is defined as k contiguous characters in the string that are the same. */
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;

        for (char c : s) {
            if (!stk.empty() && stk.top().first == c) {
                stk.top().second++;
            } else {
                stk.push({c, 1});
            }
            
            if (stk.top().second == k) {
                stk.pop();
            }
        }

        string result;
        while (!stk.empty()) {
            auto [character, count] = stk.top();
            stk.pop();
            result.insert(result.begin(), count, character);
        }

        return result;
    }
};

/**247. Add Strings
Given two non-negative integers, num1 and num2, represented as strings, you need to add these numbers and return the result as a string.
You must handle the addition of these numbers without converting them into integers directly or using built-in functions that handle large integers. */
class Solution {
public:
    string addStrings(string num1, string num2) {
        // User will implement the logic here
        int i=num1.size()-1,j=num2.size()-1;
        int sum=0;
        int carry=0;
        string result="";
        while(i>=0 || j>=0 || carry>0){
            int x=(i>=0)?num1[i--]-'0':0;
            int y=(j>=0)?num2[j--]-'0':0;
            sum=x+y+carry;
            result+=(sum%10)+'0';//convert it to string
            carry=sum/10;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

/**249. Valid Palindrome
Given a string s, the task is to determine whether the string is a valid palindrome. A palindromic string reads the same backward as forward when ignoring cases and removing all non-alphanumeric characters.
Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true
Explanation: After removing non-alphanumeric characters and converting to lowercase, the string becomes "amanaplanacanalpanama", which is a palindrome.
Example 2:
Input: "race a car"
Output: false
Explanation: After processing, the string becomes "raceacar", which is not a palindrome.
The function should return true or false based on whether the processed string is a palindrome. */
class Solution {
public:
    bool isvalidCh(char ch){
        if(ch>=0 && ch<=9)return true;
        if(ch>='a' && ch<='z')return true;
        if(ch>='A' && ch<='Z')return true;
        return false;
    }
    string normalString(string s){
        string newStr="";
        for(int i=0;i<s.length();i++){
            if(isvalidCh(s[i])){
                if(s[i]>='A' && s[i]<='Z'){
                    s[i]=s[i]-'A'+'a';//convert it into lower case
                }
                newStr.push_back(s[i]);
            }
        }
        return newStr;
    }
    bool isPalindrome(string s) {
        // User will add logic here
        string st=normalString(s);
        int lo=0,e=st.length()-1;
        while(lo<=e){
            if(st[lo]!=st[e])return false;
            lo++;
            e--;
        }
        return true;
    }
};

/**251. Remove All Occurrences of a Substring
Given two strings, s and part, the task is to remove all occurrences of the string part within s. You should continue removing occurrences of part from s until it is no longer present in the string s. Once all occurrences have been removed, return the final version of the string s. This is a straightforward string manipulation problem that can be solved by iteratively removing the substring part from s while it exists.
Example
Example 1:
Input: s = "ababcab", part = "ab"
Output: "c"
Explanation: The first occurrence of "ab" is removed from "ababcab", resulting in "abcab", then "ab" is removed again from "abcab", resulting in "cab", and finally, "ab" is removed from "cab", leaving "c".
Example 2:
Input: s = "abcd", part = "xyz"
Output: "abcd"
Explanation: Since "xyz" is not present in "abcd", the string remains unchanged.
Approach this problem by systematically checking and removing part from s until no occurrences remain. */

class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Logic to be implemented by the user
        while(s.find(part)!=-1){
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};

/**455. Find length of a String
Given a string, determine and return the total number of characters it contains. This includes all types of characters such as lowercase and uppercase English letters, digits, punctuation, and spaces.
The length is calculated by counting each character from the first to the last. This means that spaces and punctuation marks are included in the count.
For example, consider the string "Hello, World!". Its length is 13 because all characters, including the space and punctuation, are counted.
Example:
Input: "OpenAI"
Output: 6
Explanation: The string "OpenAI" has six characters: 'O', 'p', 'e', 'n', 'A', and 'I'. Thus, the length is 6.**/
int findStringLength(const string& input) {
    // Your code here
    // return input.size();
    int i=0;
    while(input[i]!='\0'){
        i++;
    }
    return i;
}

/**456. Reverse a Character Array
You are given a character array that you need to reverse in-place. The challenge entails modifying the original array without allocating additional space for another array.
The function will receive the character array as input and must return the array with its elements reversed. It is crucial to achieve this in-place by altering the positions of elements directly within the input array.
Example:
Example 1:
Input: ['h', 'e', 'l', 'l', 'o']
Output: ['o', 'l', 'l', 'e', 'h']
Example 2:
Input: ['A', 'B', 'C', 'D']
Output: ['D', 'C', 'B', 'A']
Note:
The array can contain both uppercase and lowercase characters.
It's important to swap elements within the array to reverse it without using additional space.
 */
class Solution {
public:
    void reverseCharArray(vector<char>& arr) {
        // Your code goes here
        // reverse(arr.begin(),arr.end());
        int i=0,j=arr.size()-1;
        while(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
};

/**457. Check if a String is a Palindrome
Given a string s, determine if it is a palindrome. A string is considered a palindrome when read the same both forwards and backwards.
For example, the string "racecar" is a palindrome because it reads the same in both directions. However, "hello" is not a palindrome because it doesn’t read the same from start to end and end to start. */
bool isPalindrome(string s) {
    // Implement logic here
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

/**456. Reverse a Character Array
You are given a character array that you need to reverse in-place. The challenge entails modifying the original array without allocating additional space for another array.
The function will receive the character array as input and must return the array with its elements reversed. It is crucial to achieve this in-place by altering the positions of elements directly within the input array.
Example:
Example 1:
Input: ['h', 'e', 'l', 'l', 'o']
Output: ['o', 'l', 'l', 'e', 'h']
Example 2:
Input: ['A', 'B', 'C', 'D']
Output: ['D', 'C', 'B', 'A']
Note:
The array can contain both uppercase and lowercase characters.
It's important to swap elements within the array to reverse it without using additional space.
 */
class Solution {
public:
    void reverseCharArray(vector<char>& arr) {
        // Your code goes here
        // reverse(arr.begin(),arr.end());
        int i=0,j=arr.size()-1;
        while(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
};

/** 458. Convert a String to Uppercase
Write a function that takes a given string s and returns a new string where all the lowercase letters of s are converted to uppercase. The function should only process ASCII characters, leaving digits, punctuation, and any other non-lowercase letters unchanged.
Example
Input:
s = "Hello, World!"
Output:
"HELLO, WORLD!"
Explanation:
The lowercase letters 'e', 'l', 'o', and 'r' in the input string are transformed to their respective uppercase letters 'E', 'L', 'O', and 'R'. All other characters, such as punctuation and spaces, remain unaffected.
Note:
The function should not utilize any external libraries for string manipulation.**/

class Solution {
public:
    string toUpperCase(string s) {
        // Your code goes here
        for(int i=0;i<s.size();i++){
            //we ionly convert if the char are in small case
            if(s[i]>='a' && s[i]<='z'){
                s[i]=s[i]-'a'+'A';
            }
        }
        return s;
    }
};

/**459. Convert a String to Lowercase
You are given a string consisting of both uppercase and lowercase alphabetical characters. Your task is to convert all the characters in the string to lowercase.
Write a function that receives a string s and returns the same string but with all characters in lowercase.
Example:
Example 1:
Input: "HeLLo WoRLd"
Output: "hello world"
Example 2:
Input: "PYTHON"
Output: "python"
Explanation
In Example 1, the input string "HeLLo WoRLd" contains both uppercase and lowercase characters. After conversion, it becomes "hello world".
In Example 2, the input "PYTHON" contains only uppercase letters, hence all characters are converted to lowercase "python".
 */
class Solution {
public:
    string toLowerCase(string s) {
        // Your code here
        for(int i=0;i<s.size();i++){
            //we only convert to lowecase if it is in uppercase
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=s[i]-'A'+'a';
            }
        }
        return s;
    }
};

/**460. Replace a Character in a String
Given a string s, you are required to replace all occurrences of a target character c1 with another character c2 within the string.
You need to modify the original string such that each instance of c1 is replaced by c2.
Write a function that takes three parameters: the string s, the character c1 which is to be replaced, and the character c2 to replace c1 with.
Example:
Input:
s = "hello" c1 = 'l' c2 = 'x'
Output:
hexxo
Explanation:
The original string is hello.
Every occurrence of the character l is replaced by x.
The result is hexxo.
Note:
The function should maintain the case of c1 and c2 as provided in the input. For instance, if c1 is lowercase, the function should replace only the lowercase occurrences of c1 in the string. */
string replaceCharacter(string s, char c1, char c2) {
    // Write your code here
     // Placeholder
     for(int i=0;i<s.size();i++){
        if(s[i]==c1){
            s[i]=c2;
        }
     }
     return s;
}

/*461. Decode a Message
You're given a message that was encoded using a custom mapping, and the task is to decode this message. The encoding works as follows:
Each lowercase letter 'a' to 'z' is mapped to a number string in the range of '1' to '26'.
A sequence of the message string is formed by concatenating these numbers.
You are required to decode such a number string back to the original message.
Example
Input:
message = "123456"
Output
"abcdef"
Explanation
The number 1 maps to 'a', 2 to 'b', 3 to 'c', and so forth. Hence, the sequence 123456 decodes to abcdef.
Note:
The given input string will only contain numeric characters ('1' - '9'). Each number will always decode to a valid character.**/
class Solution {
public:
    string decodeMessage(string message) {
        // Implement the decoding logic here
        string ans="";
        for(int i=0;i<message.size();i++){
            char ch=message[i]-'1'+'a';
            ans+=ch;
        }
        return ans;
    }
};

/**In this problem, you are given an array of characters, chars, which represents a sequence of characters. Your task is to compress this sequence using the following rules:
For each group of consecutive repeating characters, replace the group with the character followed by the number of times it appears in that group.
If the group consists of only one character, that character should remain unchanged.
This compression should be done in-place, meaning you use O(1) extra memory beyond the input array itself.
After modifying the input array, your goal is to return the new length of the compressed character list.
Example
Input:chars = ['a','a','b','b','c','c','c']
Output:6
 */

 class Solution {
public:
    int compress(vector<char>& s) {
        int index = 0; // where to write compressed characters
        int i = 0;     // read pointer

        while (i < s.size()) {
            char currentChar = s[i];
            int count = 0;

            // Count consecutive repeating characters
            while (i < s.size() && s[i] == currentChar) {
                i++;
                count++;
            }

            // Write the character
            s[index++] = currentChar;

            // Write the count if more than 1
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    s[index++] = c;
                }
            }
        }

        return index;
    }
};

/**244. Number of Laser Beams in a Bank
Given a 2D string array called bank, representing a security bank, where each string bank[i] corresponds to a row of security devices:
'1' signifies an active security device.
'0' signifies an inactive security device.
The task is to determine the total number of laser beams generated. Laser beams are formed between every two rows that each have at least one active device. Specifically, if one row has x active security devices and another has y, the number of laser beams between these two rows is given by x * y.
You need to compute and return the aggregate number of laser beams in the entire bank.
Example
Input:
bank = [
 "011001",
 "000000",
 "010100",
 "001000"
]
Output:8
 */

 class Solution {
public:
   int countDevices(string& s){
    int count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1')count++;
    }
    return count;
   }

    int numberOfBeams(vector<string>& bank) {
        // Implement logic to calculate number of laser beams
    vector<int>devices;
    for(auto row:bank){
        devices.push_back(countDevices(row));
    }
     int beams=0;
    
        for(int i=0;i<devices.size()-1;i++){
            int j=i+1;
            while(j<devices.size()){
                beams+=devices[i]*devices[j];
                if(devices[j]==0)j++;
                else break;
            }
        }
    return beams;
    }
};

/**LEETCODE 890. Find and Replace Pattern
Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter. */

class Solution {
public:
   void normaliseString(string &s){
        //creatng mapping
        char st='a';
        unordered_map<char,char>mpp;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(mpp.find(ch)==mpp.end()){
                mpp[ch]=st;
                st++;
            }
        }
        //creating a std pattern using this mapping
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            char mappedCh=mpp[ch];
            s[i]=mappedCh;
        }
   }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        normaliseString(pattern);

        for(auto it:words){
            string currentStr=it;
            normaliseString(currentStr);
            if(pattern==currentStr){
                ans.push_back(it);
            }
        }
        return ans;
    }
};

/**791. Custom Sort String
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.
Return any permutation of s that satisfies this property. */
string orderCpy;
class Solution {
public:
    static bool cmp(char ch1,char ch2){
        return orderCpy.find(ch1)<orderCpy.find(ch2);
    }
    string customSortString(string order, string s) {
        orderCpy=order;
        sort(s.begin(),s.end(),cmp);
        return s;
    }
};

/**2391. Minimum Amount of Time to Collect Garbage
You are given a 0-indexed array of strings garbage where garbage[i] represents the assortment of garbage at the ith house. garbage[i] consists only of the characters 'M', 'P' and 'G' representing one unit of metal, paper and glass garbage respectively. Picking up one unit of any type of garbage takes 1 minute.
You are also given a 0-indexed integer array travel where travel[i] is the number of minutes needed to go from house i to house i + 1.
There are three garbage trucks in the city, each responsible for picking up one type of garbage. Each garbage truck starts at house 0 and must visit each house in order; however, they do not need to visit every house.
Only one garbage truck may be used at any given moment. While one truck is driving or picking up garbage, the other two trucks cannot do anything.
Return the minimum number of minutes needed to pick up all the garbage. */

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickP=0;//pickup time for p
        int pickM=0;//pickup time for m
        int pickG=0;//pickup time for g

        int lastHouseP=0;
        int lastHouseM=0;
        int lastHouseG=0;

        for(int i=0;i<garbage.size();i++){
            string currHouseGarbage=garbage[i];
            for(int j=0;j<currHouseGarbage.size();j++){
                char garbageType=currHouseGarbage[j];
                if(garbageType=='P'){
                    pickP++;
                    lastHouseP=i;
                }else if(garbageType=='M'){
                    pickM++;
                    lastHouseM=i;
                }else if(garbageType=='G'){
                    pickG++;
                    lastHouseG=i;
                }
            }
        }
        int travelP=0;
        int travelM=0;
        int travelG=0;

        for(int i=0;i<lastHouseP;i++){
            travelP+=travel[i];
        }
        for(int i=0;i<lastHouseM;i++){
            travelM+=travel[i];
        }
        for(int i=0;i<lastHouseG;i++){
            travelG+=travel[i];
        }
      int totalTime=(pickP+pickM+pickG)+(travelP+travelM+travelG);
      return totalTime;
    }
};