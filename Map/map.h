#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
using namespace std;

template <typename Key, typename Value, typename Hash = std::hash<Key>>
class Map {
  private:
    vector<list<pair<Key, Value>>> buckets;
    Hash hasher;
    size_t num_elements;

    size_t getBucketIndex(Key& key) {
      return hasher(key) % buckets.size();
    }
  public:
    Map(size_t initial_cap = 5): buckets(initial_cap), num_elements(0) {}
    
    void put(Key key, Value value) {
        if (num_elements == this->buckets.capacity()) { //if size = capacity, double the capacity
            this->buckets.resize(this->buckets.capacity() * 2);
        }
      size_t index = getBucketIndex(key); //find index where value gets inserted
      for (auto& kv: this->buckets[index]) { //checking key, value to each key value in each list
        if (kv.first == key) {
          kv.second = value;
          return;
        }
      }
      buckets[index].emplace_back(pair(key, value)); //insert pair into bucket
      this->num_elements++;
    }

    size_t getNumElements() {
        return this->num_elements;
    }
    size_t getCapacity() {
        return this->buckets.capacity();
    }

    Value* find(Key key) {
        size_t index = getBucketIndex(key);
        for (auto& kv: this->buckets[index]) {
            if (kv.first == key) {
                cout << "Key found at (" << index << ")" << endl;
                return &kv.second;
            }
        }
        return nullptr;
    }
    
    void remove(Key key) {
        size_t index = getBucketIndex(key);
        auto& bucket_list = this->buckets[index];
        for (auto it = bucket_list.begin(); it != bucket_list.end(); it++) {
            if (it->first == key) {
                bucket_list.erase(it);
                num_elements--;
                return;
            }
        }
    }
    void displayMap() {
        for (int i = 0; i < this->buckets.size(); i++) {
            for (auto& kv: this->buckets[i]) {
                cout << "{" << kv.first << ", " << kv.second << "}" << endl;
            }
        }
    }
};

#endif