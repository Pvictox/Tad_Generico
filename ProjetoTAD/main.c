#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Collection.h"
#define MAXCHAR 30
#define MAXDISCOS 10

typedef struct __Disc__{
    char nameDisc[MAXCHAR];
    int yearPublication;
    float priceDisc;
}Disco;

int comparaItem(void* key, void* item){
    char *pName = (char*)key;
    int *pYear = (int*)key;
    float *pPrice = (float*)key;
    Disco *disco = (Disco*)item;
    if (pName != NULL){
        if (strcmp(pName, disco->nameDisc) == 0){
            return 1;
        };
    }
    if(*pYear == disco->yearPublication){
        return 1;
    }else if (*pPrice == disco->priceDisc){
        return 1;
    };

    return 0;
};

int main()
{
    CollectionItens *coll;
    coll = NULL;
    Disco **d, **storageDisc, *result;
    d = NULL;
    result = NULL;
    char nome[30];
    int ano, op=0, cont=0, i, op2;
    float preco;
    while (op < 6){
        system("cls");
        printf("1 - Adiciona Disco\n2 - Busca Disco\n3 - Deleta Disco\n4 - Mostra todos\n5 - Destruir\n");
        scanf("%d", &op);
        fflush(stdin);
        switch(op){
        case 1: //Adiciona
            if (coll == NULL){
                coll = createCollection(MAXDISCOS);
                d = (Disco**)malloc(sizeof(Disco*)*MAXDISCOS);
            }
            if (cont < MAXDISCOS){
                d[cont] = (Disco*)malloc(sizeof(Disco));
                if (d[cont] != NULL){
                    printf("Nome do disco:\n");
                    scanf("%[^\n]s", (d[cont]->nameDisc));
                    fflush(stdin);
                    printf("Ano de publicacao\n");
                    scanf("%d", &(d[cont]->yearPublication));
                    printf("Preco do disco\n");
                    scanf("%f", &(d[cont]->priceDisc));
                    if ( insertItem(coll, (void*)d[cont]) == 1 ){
                        printf("Sucesso\n");
                        cont++;
                    }else{
                        printf("Erro");
                    };
                };
            }else{
                printf("Operacao negada. Limite: %d || Cadastrados: %d\n", MAXDISCOS, cont);
            };
            system("pause");
            break;
        case 2:  //Busca
            if (coll != NULL){
                printf("1 - Por nome\n2- Por ano\n3- Por preco\n4 - Por todos\n");
                scanf("%d", &op2);
                fflush(stdin);
                switch (op2){
                    case 1:
                        printf("Nome do disco:\n");
                        scanf("%[^\n]s", nome);
                        fflush(stdin);
                        result = (Disco*)getItemByName(coll, (void*)&nome, comparaItem);
                        if (result != NULL){
                            printf("Nome: %s\nAno: %d\nPreco: %2.f\n", result->nameDisc, result->yearPublication, result->priceDisc);
                        }else{
                            printf("Nada encontrado\n");
                        };
                        result == NULL;
                        break;
                    case 2:
                        printf("Ano de publicacao\n");
                        scanf("%d", &ano);
                        fflush(stdin);
                        result = (Disco*)getItemByYear(coll, (void*)&ano, comparaItem);
                        if (result != NULL){
                            printf("Nome: %s\nAno: %d\nPreco: %2.f\n", result->nameDisc, result->yearPublication, result->priceDisc);
                        }else{
                            printf("Nada encontrado\n");
                        };
                        result == NULL;
                        break;
                    case 3:
                        printf("Preco do disco\n");
                        scanf("%f", &preco);
                        fflush(stdin);
                        result = (Disco*)getItemByPrice(coll, (void*)&preco, comparaItem);
                        if (result != NULL){
                            printf("Nome: %s\nAno: %d\nPreco: %2.f\n", result->nameDisc, result->yearPublication, result->priceDisc);
                        }else{
                            printf("Nada encontrado\n");
                        };
                        result == NULL;
                        break;
                    case 4:
                        printf("Nome do disco:\n");
                        scanf("%[^\n]s", nome);
                        fflush(stdin);
                        printf("Ano de publicacao\n");
                        scanf("%d", &ano);
                        printf("Preco do disco\n");
                        scanf("%f", &preco);
                        result = (Disco*)getItem(coll, (void*)&nome, (void*)&ano, (void*)&preco, comparaItem);
                        if (result != NULL){
                            printf("Nome: %s\nAno: %d\nPreco: %2.f\n", result->nameDisc, result->yearPublication, result->priceDisc);
                        }else{
                            printf("Nada encontrado\n");
                        };
                        result == NULL;
                        break;

                }
            }else{
                printf("Nao ha colecao criada\n");
            };
            system("pause");
            break;
        case 3: //Deleta
            if (coll != NULL){
                printf("1 - Por nome\n2- Por ano\n3- Por preco\n4 - Por todos\n");
                scanf("%d", &op2);
                fflush(stdin);
                switch(op2){
                case 1:
                    printf("Nome do disco:\n");
                    scanf("%[^\n]s", nome);
                    fflush(stdin);
                    if ( removeItemByName(coll,(void*)&nome, comparaItem) == 1){
                        printf("Deletado com sucesso\n");
                        cont--;
                    }else{
                        printf("Erro ao Deletar\n");
                    };
                    break;
                case 2:
                    printf("Ano de publicacao\n");
                    scanf("%d", &ano);
                    if ( removeItemByYear(coll,(void*)&ano, comparaItem) == 1){
                        printf("Deletado com sucesso\n");
                        cont--;
                    }else{
                        printf("Erro ao Deletar\n");
                    };
                    break;
                case 3:
                    printf("Preco do disco\n");
                    scanf("%f", &preco);
                    if ( removeItemByPrice(coll,(void*)&preco, comparaItem) == 1){
                        printf("Deletado com sucesso\n");
                        cont--;
                    }else{
                        printf("Erro ao Deletar\n");
                    };
                    break;
                case 4:
                    printf("Nome do disco:\n");
                    scanf("%[^\n]s", nome);
                    fflush(stdin);
                    printf("Ano de publicacao\n");
                    scanf("%d", &ano);
                    printf("Preco do disco\n");
                    scanf("%f", &preco);
                    if ( removeItem(coll,(void*)&nome, (void*)&ano, (void*)&preco, comparaItem) == 1){
                        printf("Deletado com sucesso\n");
                        cont--;
                    }else{
                        printf("Erro ao Deletar\n");
                    };
                    break;
                };
            }else{
                printf("Nao ha colecao criada\n");
            };
            system("pause");
            break;
        case 4: //Mostra todos
            if (coll != NULL){
                result = getFirstItem(coll);
                if (result != NULL){
                   while (result != NULL){
                        printf("------------------------------\n");
                        printf("Nome: %s\nAno: %d\nPreco: %2.f\n", result->nameDisc, result->yearPublication, result->priceDisc);
                        result = getNextItem(coll);
                   };
                }else{
                    printf("Nada na colecao\n");
                }
            }else{
                printf("Nao ha colecao criada\n");
            };
            result = NULL;
            system("pause");
            break;
        case 5: //Destruir
                if (destroyCollection(coll) == 1){
                    printf("Colecao deletada\n");
                    if(d != NULL){
                        d = NULL;
                    };
                    coll = NULL;
                    cont =0;
                }else{
                    printf("Erro ao deletar colecao\n");
                }
            system("pause");
            break;
        default:
            if (coll != NULL){
                destroyCollection(coll);
            };
            if(d != NULL){
                for(i=0; i<cont;i++){
                    free(d[i]);
                };
                    free(d);
            };
                break;
        };
    };

    return 0;
}
