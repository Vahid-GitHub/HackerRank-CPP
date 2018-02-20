#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
// #include <cassert>
using namespace std;

struct Node
{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache
{
   protected:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache:public Cache
{
    int c_len;
    public:
        LRUCache(int m) {
            cp = m;
            c_len = 0;
            head = NULL;
            tail = NULL;
        }
        void set(int k, int v);
        int get(int k);
};

void LRUCache::set (int k, int v) {
    if (mp.find(k) == mp.end()) {   // If this is a new key
        // Create new Node
        Node* new_node = new Node(head, NULL, k, v);
        mp[k] = new_node;
        // cout << mp[k]->value << endl;
        if (c_len == 0) {   // What happen at the beginning
            // Attach new node to head
            head = new_node;
            tail = head;
        } else if (c_len < cp) {  // When the Cache is not full
            // Attach new node to head
            head->next = new_node;
            head = new_node;
        } else {        // When the Cache is full
            // Attach new node to head
            head->next = new_node;
            head = new_node;
            // Remove old node from map and tail
            mp.erase(tail->key);
            tail = tail->next;
            delete (tail->prev);
        }
        c_len++;
    } else { // If this key exist before
        mp[k]->value = v;
    }
}

int LRUCache::get(int k) {
    return( (mp.find(k) == mp.end()) ? -1 : mp[k]->value );
}

int main() {
    int M;
    cin >> M ;
    LRUCache lru(M);
    lru.set(1, 2);
    cout << lru.get(1) << endl;
    cout << lru.get(2) << endl;
    lru.set(1, 4);
    cout << lru.get(1) << endl;
    cout << lru.get(2) << endl;
    lru.set(2, 6);
    cout << lru.get(1) << endl;
    cout << lru.get(2) << endl;
    lru.set(3, 9);
    cout << lru.get(1) << endl;
    cout << lru.get(2) << endl;
    cout << lru.get(3) << endl;
    lru.set(1, 10);
    cout << lru.get(1) << endl;
    cout << lru.get(2) << endl;
    cout << lru.get(3) << endl;

    return ( 0 ) ;
}
