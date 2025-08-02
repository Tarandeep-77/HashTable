#include <iostream>

using namespace std;
int SIZE=10;

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

template<typename K,typename V>
class HashTable{
    private:
    Node<K,V>** table;

    int hashFunction(K key){
        return key%SIZE;
    }

    public:
    HashTable(){
        table = new Node<K,V>*[SIZE];
        for(int i=0; i<SIZE; i++){
            table[i] = nullptr;
        }
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
    }

    void display(){
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

    V get(K key){
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
};


int main(){

   HashTable<int,float> ht;
    ht.insert(1,2.34);
    ht.insert(12,25.2);
    ht.insert(3,5.2);

    ht.display();

    cout<<"Get function:"<< ht.get(3);
    return 0;
}