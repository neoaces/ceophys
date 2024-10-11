/**
 * @file neolib/hmap.h
 * @brief Holds the implementation details for the hashmap and linked list.
 */

#pragma once
#include <stdio.h> // IWYU pragma: keep

#define CONFIG_SIZE 51
#define KEY_MAX 17 // MAX KEY SIZE: 16 CHARACTERS
#define VALUE_MAX 51 // MAX VALUE SIZE: 50 CHARACTERS

/**
 * @typedef NodeType
 * @brief Represents the type of node. Allows for casting of the correct type in the 
 *
 */
typedef enum NodeType {
    Integer = 0,
    Float = 1,
    String = 2,
    HashTable = 3,
} nodetype_t;

/**
 * @typedef Node
 * @brief Linked list node. Type is stored as a NodeType allowing the cast of the void* in value.
 *
 */
typedef struct Node {
    enum NodeType type;
    const char* key;
    void* value;
    struct Node* next;
} node_t;

/**
 * @typedef HashTable
 * @brief Hashtable struct. Uses a linked list to deal with collisions.
 *
 */
typedef struct HashTable {
    int table_size;
    node_t* start[];
} hashtable_t;

/**
 * @brief Calculates the hash for the given key.
 *
 * @param key - String containing the key
 * @param array_size - Size of the hashtable
 * @return - Returns the hash
 */
size_t _hash(char* key, size_t array_size);
