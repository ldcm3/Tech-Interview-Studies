/*
    - Considere a ISBN number of length 10.
    - The first 9 chars are digits and the last the sum of the first 9, mod 11. (10 is represented by 10)
    - Create a cache for looking up, insert, and remove using LRU Cache (Least Recently Used) policy.
    - If a ISBN is already present, insert should not change the price, but update it.

*/

template<size_t capacity>

class LRUCache
{
    private: 
        typedef unordered_map<int, pair<list<int>::iterator, int>> Table;
        
        list<int> lru_queue;
        Table isbn_price_table;
        
        // Force the key-value pair to move to the front
        void moveToFront(int isbn,const Table::iterator& it)
        {
            lru_queue.erase(it->second.first);
            lru_queue.emplace_front(isbn);
            it->second.first = lru_queue.begin();
        }
        
    public:
        
        bool lookup(int isbn, int* price)
        {
            if (isbn_price_table.find(isbn) == isbn_price_table.end())
                return false;
            
            *price = isbn_price_table.find(isbn)->second.second;
            
            // Move it to the front of the queue
            moveToFront(isbn,isbn_price_table.find(isbn));
            return true;
        }
        
        void insert(int isbn, int price)
        {
            auto it = isbn_price_table.find(isbn);
            
            // We add the value for key only if the key is not present 
            //- we dont update existing values
            if (it != isbn_price_table.end())
            {
                moveToFront(isbn,it);
            }
            else
            {
                if(isbn_price_table.size() == capacity)
                {
                    // removes the least recently used ISBN to get space
                    isbn_price_table.erase(lru_queue.back());
                    lru_queue.pop_back();
                }
                
                lru_queue.emplace_front(isbn);
                isbn_price_table[isbn] = {lru_queue.begin(), price};
            }
        }
    
        bool erase(int isbn)
        {
            auto it = isbn_price_table.find(isbn);
            
            if(it == isbn_price_table.end())
                return false;
            
            lru_queue. erase(it->second.first);
            isbn_price_table.erase(it);
            return true;
                
        }
}
;
int main()
{
    
    return 0;
}