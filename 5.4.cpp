//分离链接法的一些实现方法
#include<stdio.h>
#include<stdlib.h>
#define MINTABLESIZE 11
struct HashTbl;
typedef struct HashTbl* HashTable;

typedef Stack List;
struct HashTbl
{
    int TableSize;
    List* TheLists;
};

HashTable
InitializeTable(int TableSize)
{
    if (TableSize < MINTABLESIZE) {
        printf("TableSize too small\n");
        return NULL;
    }

    HashTable H = NULL;
    H = (HashTable)malloc(sizeof(struct HashTbl));
    if (H == NULL) {
        printf("HashTable malloc failed\n");
        return NULL;
    }
    memset(H, 0, sizeof(struct HashTbl));

    H->TableSize = GetNextPrime(TableSize);
    H->TheLists = (List*)malloc(sizeof(List) * H->TableSize);
    if (H->TheLists == NULL) {
        printf("HashTable TheLists malloc failed\n");
        free(H);
        H = NULL;
        return NULL;
    }
    memset(H->TheLists, 0, sizeof(List) * H->TableSize);

    int cnt, cnt2;
    for (cnt = 0; cnt < H->TableSize; cnt++) {
        H->TheLists[cnt] = CreateStack();
        if (H->TheLists[cnt] == NULL) {
            printf("H->TheLists[%d]malloc failed\n", cnt);
            for (cnt2 = 0; cnt2 < cnt; cnt2++) {
                if (H->TheLists[cnt2] != NULL) {
                    DistroyStack(H->TheLists[cnt2]);
                    H->TheLists[cnt2] = NULL;
                }
            }
            if (H->TheLists != NULL) {
                free(H->TheLists);
                H->TheLists = NULL;
            }
            if (H != NULL) {
                free(H);
                H = NULL;
            }
            return NULL;
        }
    }

    return H;
}
void
Insert(ElementType Key, HashTable H)
{
    if (H == NULL) {
        printf("HashTable is NULL\n");
        return;
    }

    if (0 != Push(Key, H->TheLists[GetHashSubmit(Key, H->TableSize)])) {
        printf("Insert Key failed\n");
    }
}