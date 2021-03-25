#include "Collection.h"
#include <stdlib.h>
typedef struct __Collection__{
    int maxItem;
    int quantItem;
    void **element;
    int currentItem;
}CollectionItens;

void* createCollection(int maxItem){
    CollectionItens *ci;
    if (maxItem > 0){
        ci = (CollectionItens*)malloc(sizeof(CollectionItens));
        if (ci != NULL){
          ci->element = (void**)malloc(sizeof(void*)*maxItem);
          if (ci->element != NULL){
            ci->currentItem = -1;
            ci->quantItem = 0;
            ci->maxItem = maxItem;
            return ci;
          };
         free(ci);
        };
    };
    return NULL;
};

// Retornando 0 para FALSE e 1 para TRUE
/// Aloca 1 de cada vez
int insertItem(CollectionItens *ci, void* variable){
    if (ci != NULL){
        if( variable != NULL && ci->element != NULL){
          if(ci->quantItem < ci->maxItem){
            ci->element[ci->quantItem] = variable;
            ci->quantItem++;
            return 1;
          };
        };
    };
    return 0;

};

//Função compare retorna 0 para FALSE e 1 para TRUE
void* getItem(CollectionItens *ci, void* keyName, void* keyYear, void* keyPrice, int (*compare)(void*,void*)){
    int i=0;
    if(ci != NULL){
        if(ci->element != NULL){
            for(i=0; i< ci->quantItem; i++){
              if( (compare(keyName, ci->element[i]) == 1)&& (compare(keyYear, ci->element[i]) == 1) && (compare(keyPrice, ci->element[i]) == 1) ){
                return ci->element[i];
              }
            };
        };
    };
    return NULL;
};

void* getItemByName(CollectionItens *ci, void* keyName, int (*compare)(void*,void*)){
    int i;
    if(ci != NULL){
        if(ci->element != NULL){
            for(i=0; i< ci->quantItem; i++){
              if( compare(keyName, ci->element[i]) == 1){
                return ci->element[i];
              }
            };
        };
    };
    return NULL;
};

void* getItemByYear(CollectionItens *ci, void* keyYear, int (*compare)(void*, void*)){
    int i=0;
    if(ci != NULL){
        if(ci->element != NULL){
            for(i=0; i< ci->quantItem; i++){
              if( compare(keyYear, ci->element[i]) == 1){
                return ci->element[i];
              }
            };
        };
    };
    return NULL;
};

void* getItemByPrice(CollectionItens *ci, void* keyPrice, int (*compare)(void*, void*)){
    int i=0;
    if(ci != NULL){
        if(ci->element != NULL){
            for(i=0; i< ci->quantItem; i++){
              if( compare(keyPrice, ci->element[i]) == 1){
                return ci->element[i];
              }
            };
        };
    };
    return NULL;
};

// 0 = FALSE || 1 = TRUE
int removeItem(CollectionItens *ci, void* keyName, void* keyYear, void* keyPrice, int (*compare)(void*, void*)){
    int i;
    if (ci != NULL){
        if(ci->element != NULL){
          if (ci->quantItem > 0){
            for(i=0; i<ci->quantItem; i++){
                if ( (compare(keyName, ci->element[i]) == 1) && (compare(keyYear, ci->element[i]) == 1) && (compare(keyPrice, ci->element[i]) == 1) ){
                    while(i<ci->quantItem-1){
                      ci->element[i] = ci->element[i+1];
                      i++;
                    };
                    ci->quantItem--;
                    return 1;
                };
            };
          };
        };
    };
    return 0;
};

int removeItemByName(CollectionItens *ci, void* keyName, int (*compare)(void*, void*)){
    int i;
    if (ci != NULL){
        if(ci->element != NULL){
          if (ci->quantItem > 0){
            for(i=0; i<ci->quantItem; i++){
                if ( compare(keyName,ci->element[i]) == 1 ){
                    while(i<ci->quantItem-1){
                      ci->element[i] = ci->element[i+1];
                      i++;
                    };
                    ci->quantItem--;
                    return 1;
                };
            };
          };
        };
    };
    return 0;
};

int removeItemByYear(CollectionItens *ci, void* keyYear, int (*compare)(void*, void*)){
    int i;
    if (ci != NULL){
        if(ci->element != NULL){
          if (ci->quantItem > 0){
            for(i=0; i<ci->quantItem; i++){
                if ( compare(keyYear, ci->element[i]) == 1 ){
                    while(i<ci->quantItem-1){
                      ci->element[i] = ci->element[i+1];
                      i++;
                    };
                    ci->quantItem--;
                    return 1;
                };
            };
          };
        };
    };
    return 0;
};

int removeItemByPrice(CollectionItens *ci, void* keyPrice, int (*compare)(void*, void*)){
    int i;
    if (ci != NULL){
        if(ci->element != NULL){
          if (ci->quantItem > 0){
            for(i=0; i<ci->quantItem; i++){
                if ( compare(keyPrice, ci->element[i]) == 1 ){
                    while(i<ci->quantItem-1){
                      ci->element[i] = ci->element[i+1];
                      i++;
                    };
                    ci->quantItem--;
                    return 1;
                };
            };
          };
        };
    };
    return 0;
};

void *getFirstItem(CollectionItens *ci){
    if (ci!=NULL){
      if (ci->element != NULL){
        if (ci->quantItem>0){
            ci->currentItem = 0;
            return ci->element[ci->currentItem];
        };
      };
    };
    return NULL;
};

void *getNextItem(CollectionItens *ci){
    if (ci!=NULL){
      if(ci->element != NULL){
        ci->currentItem++;
        if (ci->currentItem < ci->quantItem){
            return ci->element[ci->currentItem];
        }
      };
    };
    return NULL;
};

int destroyCollection(CollectionItens *ci){
        if(ci!=NULL){
            if(ci->element != NULL){
                free(ci->element);
                free(ci);
                return 1;
            };
        };
        return 0;
};

