// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents number of words in dictionary
unsigned int words = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash word to obtain a hash value
    unsigned int index = hash(word);

    // Access linked list at that index in the hash table
    node *cursor = table[index];

    // Traverse linked list, looking for the word
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // Copy word into node
        strcpy(n->word, word);

        // Hash word to obtain a hash value
        unsigned int index = hash(word);

        // Insert node into hash table
        n->next = table[index];
        table[index] = n;

        words++;
    }

    // Close dictionary
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // If dictionary is loaded, return number of words
    if (words > 0)
    {
        return words;
    }

    // If dictionary hasn't been loaded, return 0
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate over each bucket in the hash table
    for (int i = 0; i < N; i++)
    {
        // Point cursor to start of list
        node *cursor = table[i];

        while (cursor != NULL)
        {
            // Create a temp cursor
            node *temp = cursor;

            // Move cursor to next node
            cursor = cursor->next;

            // Free the temp cursor
            free(temp);
        }

        // Set table[i] to NULL
        table[i] = NULL;
    }

    return true;
}
