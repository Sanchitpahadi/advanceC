#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 22


/*
  //hash table was a lil bit of hard to visualize concept 
  //after writting this code the tihngs came into my mind
  // so dont for got to include stdio.h stlib.h and string.h

    hashTable *ht = ht_create();

    ht_insert(ht, "age",    25);
    ht_insert(ht, "score",  100);
    ht_insert(ht, "health", 80);

    ht_print(ht);

    int val = ht_find(ht, "score");
    printf("score = %d\n", val);

    ht_delete(ht, "score");


*/
typedef struct Node
{
    char *key;
    int value;
    struct Node *next;
}Node;


typedef struct { Node *buckets[TABLE_SIZE];}hashTable;


unsigned int  hash (const char *key)
{
 unsigned int h = 0;
 while(*key)
 {
    h = (h*31)+*key++;
    
 }
  return h % TABLE_SIZE;
}

hashTable *ht_create()
{
    hashTable *ht = calloc(1,sizeof(hashTable));
    return ht;
}

void ht_insert(hashTable *ht, const char *key, int value)
{
    unsigned int index = hash(key);
    Node *curr = ht->buckets[index];
    while(curr)
    {
        if(strcmp(curr->key,key)==0)
        {
            curr->value = value;
            return;
        }
        curr = curr->next;
    }

    Node * n = malloc(sizeof(Node));
    n->key = strdup(key);
    n->value = value;
    n->next = ht->buckets[index];
    ht->buckets[index] = n;

}

int ht_find(hashTable *ht, const char *key)
{
    unsigned int index = hash(key);
    Node *curr = ht->buckets[index];

    while(curr)
    {
        if(strcmp(curr->key,key)==0)
        {
            return curr->value;
        }
        curr = curr->next;    
    }

    return -1;
}

void ht_delete(hashTable *ht , const char *key)
{
    unsigned int index = hash(key);
    Node *curr = ht->buckets[index];
    Node *prev = NULL;

    while(curr)
    {
        if(strcmp(curr->key,key)==0)
        {
            if(prev) prev->next = curr->next;
            else  ht->buckets[index] = curr ->next;
            free(curr->key);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

}


void ht_print(hashTable*ht)
{
    for(int i =0;i<TABLE_SIZE;i++)
    {
        printf("[%d]->",i);
        Node *curr = ht->buckets[i];
        while(curr)
        {
          printf("[%s][%d]->",curr->key,curr->value);
        curr = curr->next;
        }
        printf("NULL \n");

    }
}




#endif