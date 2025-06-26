// You are given an array 'arr' of length 'n' containing integers within the range '1' to 'x'.



// Your task is to count the frequency of all elements from 1 to n.

// Note:
// You do not need to print anything. Return a frequency array as an array in the function such that index 0 represents the frequency of 1, index 1 represents the frequency of 2, and so on.
// Example:
// Input: ‘n’ = 6 ‘x’ = 9 ‘arr’ = [1, 3, 1, 9, 2, 7]    
// Output: [2, 1, 1, 0, 0, 0]
// Explanation: Below Table shows the number and their counts, respectively, in the array
// Number         Count 
//  1                2
//  2                1
//  3                1
//  4                0
//  5                0
//  6                0

/**SOLUTION-->*/
#include<bits/stdc++.h>
using namespace std;
vector<int> countFrequency(int n, int x, vector<int>& nums) {
    vector<int> hash(n, 0); // Initialize vector with n elements, all set to 0
    for(int i = 0; i < nums.size(); i++) {
        if (nums[i] <= n) { // Ensure the number is within the range we're counting frequencies for
            hash[nums[i] - 1]++; // Decrement by 1 to adjust for zero-based indexing
        }
    } 
    return hash;
}

/**************QUESTION-2**********/
// Given an array 'v' of 'n' numbers.



// Your task is to find and return the highest and lowest frequency elements.


// If there are multiple elements that have the highest frequency or lowest frequency, pick the smallest element.



// Example:
// Input: ‘n' = 6, 'v' = [1, 2, 3, 1, 1, 4]

// Output: 1 2

// Explanation: The element having the highest frequency is '1', and the frequency is 3. The elements with the lowest frequencies are '2', '3', and '4'. Since we need to pick the smallest element, we pick '2'. Hence we return [1, 2]

#include <vector>
#include <map>
#include <utility> // for std::pair

std::vector<int> getFrequencies(std::vector<int>& v) {
    std::map<int,int> mpp;
    // Count the frequencies of each element
    for(int i = 0; i < v.size(); i++) {
        mpp[v[i]]++;
    }
    
    int highestFrequency = 0;
    int lowestFrequency = v.size() + 1; // Initialize to a value higher than the max possible frequency
    int highestFrequencyElement = -1;
    int lowestFrequencyElement = -1;
    
    // Find the element with the highest and lowest frequencies
    for(auto it = mpp.begin(); it != mpp.end(); it++) {
        if(it->second > highestFrequency) {
            highestFrequency = it->second;
            highestFrequencyElement = it->first;
        }
        if(it->second < lowestFrequency) {
            lowestFrequency = it->second;
            lowestFrequencyElement = it->first;
        }
    }
    
    return {highestFrequencyElement, lowestFrequencyElement};
}
