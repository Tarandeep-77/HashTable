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

   int hashFunction(int key) {
    return key % SIZE;
    }

    int hashFunction(float key) {
    return ((int)key) % SIZE;
    }

    int hashFunction(char key) {
    return key % SIZE;
    }

    public:
    HashTable(){
        table = new Node<K,V>*[SIZE];
        for(int i=0; i<SIZE; i++){
            table[i] = nullptr;
        }
    }

    ~HashTable(){
    for(int i = 0; i < SIZE; i++){
        Node<K,V>* current = table[i];
        while(current != nullptr){
            Node<K,V>* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
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

     void deltKey(K key){
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

    
    void search(K key){
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

};

int main(){

    // HashTable<int,float> ht;
    // ht.insert(1,2.34);
    // ht.insert(12,25.2);
    // ht.insert(3,5.2);
    // ht.display();

    
    HashTable<char,float> ht;
    ht.insert('A',2.34);
    ht.insert('B',25.2);
    ht.insert('C',5.2);
    ht.display();
    cout<<"Get function:"<< ht.get(3);

    ht.deltKey(12);
    cout<<"after deletion:"<<endl;
    ht.display();

    cout<<"Searching 12"<<endl;
    ht.search(12);
    return 0;
}