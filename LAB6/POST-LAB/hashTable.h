//name: Eza Rasheed
//id: er6qt
//date: 03-03-19
//filename: hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <list>


using namespace std;

class hashTable {
    public:
        hashTable();
        hashTable(int size);
        ~hashTable(); 
        bool find(string word);
        void insert(string word);
        int generateHash(string word);
        //int hash_prefix(string word);
        int max_size;
        
    private:
        vector <list <string>*> hash_table;
        bool checkprime(unsigned int p);
        int getNextPrime (unsigned int n);
    
};

#endif 
