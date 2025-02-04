#include <iostream>
#include <unordered_map>
#include <list>
#include <stdexcept>

class LRUCache {
private:
    // 每個元素儲存 (key, value) pair，最前端為最近使用的元素
    std::list<std::pair<int, int>> cacheList;
    
    // 透過 unordered_map 儲存 key 與對應到 list 中位置的 iterator
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap;
    
    // 最大容量
    int capacity;

public:
    // 建構子：檢查 capacity，並初始化容量
    LRUCache(int capacity) : capacity(capacity) {
        if (capacity < 0)
            throw std::runtime_error("Capacity cannot be negative");
    }

    // 取得 key 對應的 value
    // 若存在則將該元素移動到最前端（代表最近使用），並回傳 value；否則回傳 -1
    int get(int key) {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end())
            return -1; // 找不到元素

        // 將該元素移動到 cacheList 的前端
        cacheList.splice(cacheList.begin(), cacheList, it->second);
        return it->second->second;
    }

    // 插入或更新 key 對應的 value
    void put(int key, int value) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            // key 已存在：更新 value 並移到最前端
            it->second->second = value;
            cacheList.splice(cacheList.begin(), cacheList, it->second);
            return;
        }

        // 若容量已滿，刪除最久未使用（位於 list 後端）的元素
        if (cacheList.size() == static_cast<size_t>(capacity)) {
            auto last = cacheList.back();
            cacheMap.erase(last.first);
            cacheList.pop_back();
        }

        // 插入新元素到 list 的前端
        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();
    }
};

//
// 測試範例
//
int main() {
    try {
        LRUCache cache(3);  // 建立一個容量為 3 的 LRUCache
        
        // 測試 put 操作
        cache.put(1, 100);
        cache.put(2, 200);
        cache.put(3, 300);
        
        std::cout << "Get key 2: " << cache.get(2) << std::endl;  // 期望輸出 200
        
        // 這裡 key 2 應該被移到最前端
        cache.put(4, 400);  // 插入新元素，容量滿了，所以 key 1（最久未使用）將被移除
        
        std::cout << "Get key 1: " << cache.get(1) << std::endl;  // 期望輸出 -1 (因為已被移除)
        std::cout << "Get key 3: " << cache.get(3) << std::endl;  // 期望輸出 300
        std::cout << "Get key 4: " << cache.get(4) << std::endl;  // 期望輸出 400
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}