#include<iostream>
#include "./Node.h"
using namespace std;

int SIZE=10;
template<typename K,typename V>
class HashTable{
    private:
    Node<K,V>** table;
    int hashFunction(K key);

public:
    HashTable();
    ~HashTable();
    void insert(K key, V value);
    V get(K key);
    void deltKey(K key);
    void search(K key);
    void display();

};

template<typename K, typename V>
HashTable<K, V>::HashTable() {
    table = new Node<K, V>*[SIZE];
    for (int i = 0; i < SIZE; i++)
        table[i] = nullptr;
}

template<typename K, typename V>
HashTable<K, V>::~HashTable() {
    for (int i = 0; i < SIZE; i++) {
        Node<K, V>* current = table[i];
        while (current != nullptr) {
            Node<K, V>* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
}
template<typename K,typename V>
    void HashTable<K, V>::insert(K key,V value){
        int index = hashFunction(key);
        Node<K,V>* head = table[index];

        while(head!=nullptr){
            if(head->key== key){
                head->value = value;
                return;
            }
            head = head->next;
        }

         Node<K,V>* newNode= new Node<K,V>(key,value);
         newNode->next = table[index];
         table[index] = newNode;
    }

    template<typename K, typename V>
      V HashTable<K, V>::get(K key){
        int index = hashFunction(key);
        Node<K,V>* current = table[index];
         while(current!=nullptr){
            if(current->key == key){
            return current->value;
            }
             current = current->next;
         }
          return V();
    }
template<typename K, typename V>
     void HashTable<K, V>::deltKey(K key){
        int index = hashFunction(key);
        Node<K,V>* current = table[index]; 
        Node<K,V>* prev = nullptr;

        while(current!=nullptr){
            if(current->key == key){
                if(prev == nullptr){
                    table[index] = current->next;
                }
                else{
                    prev->next=current->next;
                }
                delete current;
                cout<<"Key deleted!";
                return;
            }
            prev = current;
            current= current->next;
        }
        cout<<"key not found";
    }

    template<typename K, typename V>
    void HashTable<K, V>::search(K key){
        int index = hashFunction(key);
        Node<K,V>* current = table[index];
         while(current!=nullptr){
            if(current->key == key){
            cout<<"Key found--"<<current->value<<endl;
            return;
            }
             current = current->next;
         }
          cout<<"Key not found"<<endl;
    }

    template<typename K, typename V>
    void HashTable<K, V>::display(){
        for(int i=0; i<SIZE; i++){
            cout<<"Index "<<i<<":";
            Node<K,V>* current = table[i];

            while(current!=nullptr){
                cout<<"("<<current->key<<":"<<current->value<<")"<<"->NULL"; 
                current=current->next;
            }
            cout<<"NULL"<<endl;
        }
    }
template<typename K, typename V>
int HashTable<K, V>::hashFunction(K key) {
    return <int>(key) % SIZE;
}
