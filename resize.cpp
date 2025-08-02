#include <iostream>
using namespace std;

template<typename K, typename V>
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
template<typename K,typename V>
class HashTable{
    private:
   Node<K,V>** table;
    int capacity=10;
    int size=0;
    int hashFunction(K key){
        return key%capacity;
    }

    public:
    HashTable(){
        
        table = new Node<K,V>*[capacity];
        for(int i=0; i<capacity; i++){
            table[i] = nullptr;
        }
    }

    void resize(){
        int oldCap = capacity;
        capacity = capacity*2;
        Node<K,V>** oldTable = table;

        table = new Node<K,V>*[capacity];
        for(int i=0; i<capacity; i++){
            table[i]=nullptr;
        }

        size=0;
        for(int i=0; i<oldCap; i++){
            Node<K,V>* current= oldTable[i];
            while(current != nullptr){
                insert(current->key,current->value);
                Node<K,V>* temp = current;
                current=current->next;
                delete temp;
            }
        }
        delete[] oldTable;

    }

     void insert(K key,V value){
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

         size++;
         if(size>0.75*capacity){
            resize();
         }

    }

     void display(){
        for(int i=0; i<capacity; i++){
            cout<<"Index "<<i<<":";
            Node<K,V>* current = table[i];

            while(current!=nullptr){
                cout<<"("<<current->key<<":"<<current->value<<")"<<"->"; 
                current=current->next;
            }
            cout<<"NULL"<<endl;
        }
    }


};

int main(){

    HashTable<int,float> ht;
    ht.insert(1,2.34);
    ht.insert(12,25.2);
    ht.insert(3,5.2);
    ht.insert(22,66.2);
    ht.insert(6,7.3);
    ht.display();
    return 0;
}