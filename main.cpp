#include <iostream>
#include "./library/HashTable.h"
using namespace std;

int main(){

    HashTable<int,float> ht;
    ht.insert(1,2.34);
    ht.insert(12,25.2);
    ht.insert(3,5.2);
    ht.display();

    
    // HashTable<char,float> ht;
    // ht.insert('A',2.34);
    // ht.insert('B',25.2);
    // ht.insert('C',5.2);
    // ht.display();
    cout<<"Get function:"<< ht.get(3);

    ht.deltKey(12);
    cout<<"after deletion:"<<endl;
    ht.display();

    cout<<"Searching 12"<<endl;
    ht.search(12);
    return 0;
}