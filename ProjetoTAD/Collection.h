#ifndef COLLECTION_H_INCLUDED
#define COLLECTION_H_INCLUDED

typedef struct __Collection__ CollectionItens;

void* createCollection(int maxItem);

int insertItem(CollectionItens *ci, void *variable);

/// Busca

void* getItem(CollectionItens *ci, void* keyName, void* keyYear, void* keyPrice, int (*compare)(void*, void*));

void* getItemByName(CollectionItens *ci, void* keyName, int (*compare)(void*, void*));

void* getItemByYear(CollectionItens *ci, void* keyYear, int (*compare)(void*, void*));

void* getItemByPrice(CollectionItens *ci, void* keyPrice, int (*compare)(void*, void*));

/// REMOÇÃO

int removeItem(CollectionItens *cd, void* keyName, void* keyYear, void* keyPrice, int (*compare)(void*, void*));

int removeItemByName(CollectionItens *cd, void* keyName, int (*compare)(void*, void*));

int removeItemByYear(CollectionItens *cd, void* keyYear, int (*compare)(void*, void*));

int removeItemByPrice(CollectionItens *cd, void* keyPrice, int (*compare)(void*, void*));

void *getFirstItem(CollectionItens *ci);

void *getNextItem(CollectionItens *ci);

int destroyCollection(CollectionItens *ci);
#endif // COLLECTION_H_INCLUDED
