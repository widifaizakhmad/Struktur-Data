#include "penyakit.h"

// Parent Disease

void createListDisease(listDisease &L){
    first(L) = NULL;
}

adrDisease newElmDisease(infotypeDisease x){
    adrDisease P = new elmDisease;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertLastDisease(listDisease &L, adrDisease P){
    if(first(L) == NULL){
        first(L) = P;
        next(P) = first(L);
    }else{
        next(P) = first(L);
        adrDisease Q = first(L);
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

// Child Patient

void createListPatient(listPatient &L){
    first(L) = NULL;
    last(L) = NULL;
}

adrPatient newElmPatient(infotypePatient x){
    adrPatient P = new elmPatient;
    info(P) = x;
    prev(P) = NULL;
    next(P) = NULL;
    return P;
}

void insertLastPatient(listPatient &L, adrPatient P){
    if(first(L) == NULL && last(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteAfterPatient(listPatient &L, adrPatient Prec, adrPatient &P){
    if(first(L) == NULL && last(L) == NULL){
        cout<<"Tidak terdapat pasien"<<endl;
    }else if(next(first(L)) == NULL){
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
    }else{
        if(P = first(L)){
            first(L) = next(P);
            next(P) = NULL;
        }else{
            Prec = first(L);
            while(next(Prec) != P){
                Prec = next(Prec);
            }
            next(Prec) = next(P);
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
}

// Relation

void createListRelation(listRelation &L){
    first(L) = NULL;
}

adrRelation newElmRelation(adrDisease D, adrPatient P){
    adrRelation Q = new elmRelation;
    up(Q) = D;
    down(Q) = P;
    next(Q) = NULL;
    return Q;
}

void insertLastRelation(listRelation &L, adrRelation P){
    if(first(L) == NULL){
        first(L) = P;
    }else{
        adrRelation Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void deleteLastRelation(listRelation &L, adrRelation &P){
    adrRelation Q = first(L);
    while(next(next(Q)) != NULL){
        Q = next(Q);
    }
    P = next(Q);
    up(P) = NULL;
    down(P) = NULL;
    next(Q) = NULL;
}

// Prosedure & Function

adrDisease findDisease(listDisease L, string x){
    adrDisease P = first(L);
    while(P != NULL && info(P) != x){
        P = next(P);
    }
    return P;
}

adrPatient findPatient(listPatient L, string x){
    adrPatient P = first(L);
    while(P != NULL && info(P) != x){
        P = next(P);
    }
    return P;
}

void findSuffered(listRelation L, string x){
    int i = 1;
    adrRelation P = first(L);
    while(P != NULL){
        if(info(up(P)) == x && down(P) != NULL){
            cout<<i<<". "<<info(down(P))<<endl;
            i++;
        }
        P = next(P);
    }
}

adrPatient findRelation(listRelation L, string x){
    adrRelation P = first(L);
    while(P != NULL && info(up(P)) != x){
        P = next(P);
    }
    return down(P);
}

void countPasient(listRelation LR, string x){
    adrRelation P = first(LR);
    int sum = 0;
    while(P != NULL){
        if(info(up(P)) == x && down(P) != NULL){
            sum++;
        }
        P = next(P);
    }
    cout<<"Number of patients : "<<sum<<endl;
}

void showMostDisease(listDisease LD, listRelation LR){
    int right;
    int one = 0;
    adrDisease dS = first(LD);
    adrRelation rR = first(LR);
    while(rR != NULL){
        if(up(rR) == dS){
            one++;
        }
        rR = next(rR);
    }
    adrDisease D = next(first(LD));
    while(D != first(LD)){
        right = 0;
        adrRelation R = first(LR);
        while(R != NULL){
            if(up(R) == D){
                right++;
            }
            R = next(R);
        }
        if(one < right){
            one = right;
            dS = D;
        }
        D = next(D);
    }
    cout<<"Disease with the most sufferers : "<<info(dS)<<endl;
}

void showListPatient(listPatient &L){
    if(first(L) == NULL){
        cout<<"It's Empty"<<endl;
    }else{
        adrPatient P = first(L);
        int i = 1;
        cout<<"Remaining pasients :"<<endl;
        while(P != NULL){
            cout<<i<<". "<<info(P)<<endl;
            P = next(P);
            i++;
        }
    }
}

void showAll(listDisease &LD, listPatient &LP, listRelation &LR){
    if(first(LR) == NULL){
        cout<<"It's Empty"<<endl;
    }else{
        adrRelation P = first(LR);
        int i = 1;
        while(P != NULL){
            cout<<"No. Reg : "<<i<<endl;
            cout<<info(up(P))<<" disease suffered by "<<info(down(P))<<endl;
            P = next(P);
            i++;
        }
    }
}

int selectMenu(){
    int input = 0;
    cout<<"=========================== INFORMATION =========================="<<endl;
    cout<<"1. Enter diseases data"<<endl;
    cout<<"2. Enter patients data"<<endl;
    cout<<"3. Add relation between disease and patient"<<endl;
    cout<<"4. Looking for patient with a particular disease"<<endl;
    cout<<"5. Deleting the last disease data along with sufferers"<<endl;
    cout<<"6. Deleting patient data with certain diseases"<<endl;
    cout<<"7. Display all diseases and patients data"<<endl;
    cout<<"8. Count the number of patients with a particular disease"<<endl;
    cout<<"9. Displays data on the most common diseases suffered by patients"<<endl;
    cout<<"0. Out"<<endl;
    cout<<endl;
    cout<<"Select the menu : "; cin>>input;
    return input;
}
