#include <cstddef>

// This is an LRU cache with strings as keys. It should store N values. If the
// cache is full and a value is added, the least recently accessed value should
// be evicted.
// The cache should contain two member functions as follows:
//   1) Given a key string return a value if it is present in the cache
//   2) Given a key string and a value, place the value in the cache

#include <map>
#include <string>

template <typename Value, std::size_t N>
class LRUCache {
  
public:
  Value checkValue(const std::string & key)  const;
  void addValue(const std::string & key, const Value val);

private:
  std::map<std::string, Value> cache;
  
};


// .cpp
template <typename Value, std::size_t N>
Value LRUCache::checkValue(const std::string &key) const {
      Value empty;

      if (cache.find(key) != cache.end())  {
        return cache.at(key);
      }else    
        return empty;
  
}

template <typename Value, std::size_t N>
void addValue(const std::string & key, const Value val)  {
      
      if(cache.size() == N){
          cache.erase(cache.begin());
      }
    
      cache.insert(std::map<std::string, Value>::value_type(key, val));
}



