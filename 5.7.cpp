#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 250001
typedef struct hashNode {
    int value;
    int count;
    struct hashNode* next;
}HN;

HN hashMap[M];


void addToHash(int key) {
    int keyTo = abs(key % M);
    if (hashMap[keyTo].count == 0) {
        hashMap[keyTo].value = key;
        hashMap[keyTo].count++;
        hashMap[keyTo].next = NULL;
    }
    else {
        HN* temp = &(hashMap[keyTo]), * newn;
        while (temp->next != NULL && temp->value != key) {
            temp = temp->next;
        }
        if (temp->next == NULL && temp->value != key) {
            newn = (HN*)malloc(sizeof(HN));
            newn->value = key;
            newn->count = 1;
            newn->next = NULL;
            temp->next = newn;
        }
        else {
            temp->count++;
        }
    }
}

int findHash(int key) {
    int keyTo = abs(key % M);
    if (hashMap[keyTo].count == 0 || hashMap[keyTo].value == key) {
        return hashMap[keyTo].count;
    }
    else {
        HN* temp = hashMap[keyTo].next;
        while (temp != NULL) {
            if (temp->value == key) {
                return temp->count;
            }
            temp = temp->next;
        }
        return 0;
    }
}

int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize) {
    for (int i = 0; i < M; i++) {
        hashMap[i].count = 0;
    }
    int sum = 0;
    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < BSize; j++) {
            addToHash(A[i] + B[j]);
        }
    }
    for (int i = 0; i < CSize; i++) {
        for (int j = 0; j < DSize; j++) {
            sum += findHash(-C[i] - D[j]);
        }
    }
    return sum;//×îÖÕ½á¹û
}