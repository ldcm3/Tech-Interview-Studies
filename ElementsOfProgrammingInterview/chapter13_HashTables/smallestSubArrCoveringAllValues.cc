/**
 * 
 *  Write a program that takes an array of stirngs and a set of strings and return 
 * 
 *  the indices of the starting and ending index of a shortest subarray of the given array
 * 
 * that covers the set
 * 
 *  SOLUTION 
 * 
 *  Complexity is O(n), where n is the length of the array
 *  
 *  - Disadvantage: We need to keep the subarrays in memory
 * 
 * */
 
 #include<iostream>
 #include<vector>
 #include<unordered_set>
 #include<unordered_map>
 
 using namespace std;
 
struct subArr
{
    int start, end;
};

 subArr smallestSubArr (const vector<string>& paragraph,
                                const unordered_set<string>& keywords)
{
        unordered_map<string, int> keywords_to_cover;
        
        for (const string& keyword : keywords)
            ++keywords_to_cover[keyword];
        
        subArr result = subArr{-1,-1};
        
        int remaining_to_cover = keywords.size();
        int left = 0;
        int right = 0;
        
        for(right = 0; right < paragraph.size(); ++right)
        {
            if (keywords.count(paragraph[right])  &&
                --keywords_to_cover[paragraph[right]] >= 0)
            {
                --remaining_to_cover;
            }
        }
        
        // Keeps advancing left until keywords_to_cover does not contain all keywords
        
        while (remaining_to_cover == 0)
        {
            if ((result.start == -1 && result.end == -1) ||
                right - left < result.end - result.start)
            {
                result = {left,right};
            }
            
            if (keywords.count(paragraph[left]) &&
                ++keywords_to_cover[paragraph[left]] > 0)
            {
                ++remaining_to_cover;        
            }
            
            ++left;
        }
        
        return result;
    
}
 int main()
 {
     
     return 0;
 }