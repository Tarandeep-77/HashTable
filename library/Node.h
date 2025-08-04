#include<iostream>

template<typename K,typename V>
class Node{
    public:
    K key;
    V value;
    Node<K,V>* next;

    Node(K k,V v){
        key = k;
        value = v;
        next = nullptr;
    }
};