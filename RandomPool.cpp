#include<iostream>
#include<unordered_map>
#include<string>
#include<cstdlib>
#include<time.h>
using namespace std;
/**
 * @brief
 * 该结构三个功能
 *  emplace(key):将某个key加入到该结构，做到不重复
 *  deleted(key):将原本在结构中的某个key移除
 *  getRandom():等概率随机返回结构中的任何一个key
 * 要求：
 *  三个方法的时间复杂度都是o(1)
 * @return int
 */
template<class K>
class Pool {
public:
    Pool() {
        this->size = 0;
    }
    void Insert(K key);
    void Deleted(K key);
    K getRandom();

    unordered_map<K, int>keyIndex;
    unordered_map<int, K>indexKey;

    int size;
};

template<class K>
void Pool<K>::Insert(K key) {
    if (this->keyIndex.count(key) == 0) {
        this->keyIndex.emplace(key, this->size);
        this->indexKey.emplace(this->size++, key);
    }
}

template<class K>
void Pool<K>::Deleted(K key) {
    if (this->keyIndex.count(key) != 0) {
        int deleteIndex = this->keyIndex[key];
        int lastIndex = --this->size;
        K lastKey = this->indexKey[lastIndex];

        this->keyIndex[lastKey]= deleteIndex;
        this->indexKey[deleteIndex]= lastKey;

        this->keyIndex.erase(key);
        this->indexKey.erase(lastIndex);
    }
}

template<class K>
K Pool<K>::getRandom() {
    if (this->size == 0) return NULL;
    int randomIndex = (int)(rand() % this->size); //0-size-1
    return this->indexKey[randomIndex];
}
int main() {
    srand(time(NULL));
    Pool<string> pool;
    pool.Insert("a");
    pool.Insert("b");
    pool.Insert("c");
    pool.Insert("d");

    cout<<pool.getRandom();
    system("pause");
    return 0;
}