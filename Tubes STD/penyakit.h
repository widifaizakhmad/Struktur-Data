#ifndef PENYAKIT_H_INCLUDED
#define PENYAKIT_H_INCLUDED

#include <iostream>

using namespace std;

#define first(L) (L).first
#define last(L) (L).last
#define info(P) (P)->info
#define prev(P) (P)->prev
#define next(P) (P)->next
#define up(P) (P)->up
#define down(P) (P)->down

// ADT Parent Disease

typedef string infotypeDisease;
typedef struct elmDisease *adrDisease;

struct elmDisease{
    infotypeDisease info;
    adrDisease next;
};

struct listDisease{ //Circular Single Linked List
    adrDisease first;
};

void createListDisease(listDisease &L);
adrDisease newElmDisease(infotypeDisease x);
void insertLastDisease(listDisease &L, adrDisease P);

// ADT Child Patient

typedef string infotypePatient;
typedef struct elmPatient *adrPatient;

struct elmPatient{
    infotypePatient info;
    adrPatient prev;
    adrPatient next;
};

struct listPatient{ //Double Linked List
    adrPatient first;
    adrPatient last;
};

void createListPatient(listPatient &L);
adrPatient newElmPatient(infotypePatient x);
void insertLastPatient(listPatient &L, adrPatient P);
void deleteAfterPatient(listPatient &L, adrPatient Prec, adrPatient &P);

// ADT Relasi

typedef struct elmRelation *adrRelation;

struct elmRelation{
    adrRelation next;
    adrDisease up;
    adrPatient down;
};

struct listRelation{ //Single Linked List
    adrRelation first;
};
void createListRelation(listRelation &L);
adrRelation newElmRelation(adrDisease D, adrPatient P);
void insertLastRelation(listRelation &L, adrRelation P);
void deleteLastRelation(listRelation &L, adrRelation &P);

// Prosedure & Function

adrDisease findDisease(listDisease L, string x);
adrPatient findPatient(listPatient L, string x);
void findSuffered(listRelation L, string x);
adrPatient findRelation(listRelation L, string x);
void countPasient(listRelation LR, string x);
void showMostDisease(listDisease LD, listRelation LR);

void showListPatient(listPatient &L);
void showAll(listDisease &D, listPatient &P, listRelation &R);
int selectMenu();

#endif // PENYAKIT_H_INCLUDED
