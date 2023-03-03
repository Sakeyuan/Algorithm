#include<iostream>
#include<unordered_map>
#include<string>
#include<cstdlib>
#include<time.h>
using namespace std;
/**
 * @brief
 * �ýṹ��������
 *  emplace(key):��ĳ��key���뵽�ýṹ���������ظ�
 *  deleted(key):��ԭ���ڽṹ�е�ĳ��key�Ƴ�
 *  getRandom():�ȸ���������ؽṹ�е��κ�һ��key
 * Ҫ��
 *  ����������ʱ�临�Ӷȶ���o(1)
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