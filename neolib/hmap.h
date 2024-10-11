#pragma once
#include <stdio.h>

#define CONFIG_SIZE 51
#define KEY_MAX 17 // MAX KEY SIZE: 16 CHARACTERS
#define VALUE_MAX 51 // MAX VALUE SIZE: 50 CHARACTERS

enum NodeType {
    Integer = 0,
    Float = 1,
    String = 2,
    HashTable = 3,
};

typedef struct Node {
    enum NodeType type;
    const char* key;
    void* value;
    struct Node* next;
} node_t;

typedef struct HashTable {
    int table_size;
    node_t nodes[];
} hashtable_t;

/**
 * @brief Calculates the hash for the given key.
 *
 * @param key - String containing the key
 * @param array_size - Size of the hashtable
 * @return - Returns the hash
 */
size_t _hash(char* key, size_t array_size); 
