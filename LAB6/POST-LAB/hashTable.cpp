//name: Eza Rasheed
//id: er6qt
//date: 03-04-19
//filename: hashTable.cpp

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "hashTable.h"
//#include <math.h>

using namespace std;

hashTable::hashTable(int size) { //help
    max_size = 0;
    int prime_size = getNextPrime(size);
    hash_table.resize(prime_size);
    
    for (int i = 0; i < size; i++){
        hash_table[i] = NULL;
    }
}

hashTable::~hashTable() {
    //delete hash_table;
}

//create an iterator from list class
//iterate throguht the list and if i* == string word you wanna find
//return true, else return false

bool hashTable::find(string word) { 
    int val = generateHash(word);
     if (hash_table[val] == NULL) {
         return false;
    }
    for (list<string>::iterator i = hash_table[val]->begin(); i != hash_table[val]->end(); i++) { //help: www.cplusplus.com/reference/list/list/begin/
        if (word == *i) {
            return true;
        }
    }
    return false;
}
    
void hashTable::insert(string word) {
    int longest_len = word.length();
    if (longest_len > max_size) {
        max_size = longest_len;
    }
    
//     for (int i = 3; p <= longest_len; i++) {
//         hash_prefix.insert(word.substr(0,i));
//     }
    

    int val = generateHash(word);
    if (hash_table[val] == NULL) {
        hash_table[val] = new list<string>;
            //int val = generateHash(word);
    }
    hash_table[val]->push_back(word);
}

int hashTable::generateHash(string word) { //help
    unsigned int h_val = 0;
    int len = word.length();
    //int tbl_size = 0;
    int tbl_size = hash_table.size();
    
    for (int i = 0; i < len; i++){
        //h_val = h_val + (word[i]*pow(37,i));
        h_val = (h_val * 37) + word[i]; 
    }
    return h_val % tbl_size;
}

// int hashTable::hash_prefix(string word) { 
//     unsigned int h_val_pre = 0;
//     int len = word.length();
//     for (int i = 0; i < len; i++) {
//         h_val_pre = h_val_pre + word[i];
//     }
//     return h_val_pre % tbl_size;
// }

bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}
