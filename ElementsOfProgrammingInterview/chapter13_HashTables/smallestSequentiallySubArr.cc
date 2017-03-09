/**
 * 
 *  Write a program that takes an array of stirngs and a set of strings and return 
 * 
 *  the indices of the starting and ending index of a shortest SEQUENTIALLY subarray of the given array
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
 #include<limits>
 
 using namespace std;
 
struct subArr
{
    int start, end;
};

subArr findSmallestSeqCoveringSubset(
        const vector<string>& paragraph, const vector<string>& keywords)
{
    // Maps each keyword to its index in the keywords arr
    unordered_map<string, int> keyword_to_idx;
    
    for (int i = 0; i < keywords.size(); ++i)
    {
        keyword_to_idx.emplace(keywords[i],i);
    }
    
    // Use indicies as keys to lookup in a vector
    vector<int> latest_occurence(keywords.size(), -1);
    
    // For each keyword, stores the len of the shortest subarray ending at the 
    // most recent occurence of that keyword that sequentially cover all keywords up to 
    // that keyword
    vector<int> shortest_subarray_len (keywords.size(),
                                        numeric_limits<int> :: max());
                                        
    int shortest_dist = numeric_limits<int> :: max();
    subArr result = {-1,-1};
    
    for (int i = 0; i < paragraph.size(); ++i)
    {
        if (keyword_to_idx.count(paragraph[i])) 
        {
            int keyword_idx = keyword_to_idx.find(paragraph[i])->second;
            if (keyword_idx == 0) // first keyword
            {
                shortest_subarray_len[keyword_idx] = 1;
            }
            else if (shortest_subarray_len[keyword_idx - 1] !=
                        numeric_limits<int>::max())
            {
                int distance_to_prev_keyword = i - latest_occurence[keyword_idx - 1];
                shortest_subarray_len[keyword_idx] = distance_to_prev_keyword + 
                                                    shortest_subarray_len[keyword_idx - 1];
            }
            
            latest_occurence[keyword_idx] = i;
            
            // Last Keyword, look for improved subarray
            if (keyword_idx == keywords.size() - 1 &&
                    shortest_subarray_len.back() < shortest_dist)
            {
                shortest_dist = shortest_subarray_len.back();
                result = {i - shortest_subarray_len.back() + 1, i};
            }
        }
    }
    
    return result;
}

int main()
{
    return 0;
}
