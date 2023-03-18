#include "penyakit.h"

int main()
{
    listDisease LD;
    listPatient LP;
    listRelation LR;

    createListDisease(LD);
    createListPatient(LP);
    createListRelation(LR);

    infotypeDisease dataDisease;
    infotypePatient dataPatient;

    adrDisease D, rD;
    adrPatient P, rP, pPrec;
    adrRelation R;

    string cariDisease, relaPatient, relaDisease, YN;
    int i, inputD, inputP, inputR, choice;

    choice = selectMenu();

    while(choice != 0){
        switch(choice){
        case 1:
            cout<<"How much disease data : ";
            cin>>inputD;
            for(i = 1;i <= inputD;i++){
                cout<<"Enter Disease "<<i<<" : ";
                cin>>dataDisease;
                D = newElmDisease(dataDisease);
                insertLastDisease(LD, D);
            }
            cout<<endl;
            cout<<"Back to the main menu? (Y/N) : ";
            cin>>YN;
            if(YN == "Y"){
                break;
            }else{
                cout<<"You have exited the program"<<endl;
                return 0;
            }
        case 2:
            cout<<"How much patient data : ";
            cin>>inputP;
            for(i = 1;i <= inputP;i++){
                cout<<"Enter Pasient "<<i<<" : ";
                cin>>dataPatient;
                P = newElmPatient(dataPatient);
                insertLastPatient(LP, P);
            }
            cout<<endl;
            cout<<"Back to the main menu? (Y/N) : ";
            cin>>YN;
            if(YN == "Y"){
                break;
            }else{
                cout<<"You have exited the program"<<endl;
                return 0;
            }
        case 3:
            cout<<"How much relation data : ";
            cin>>inputR;
            for(i = 1;i <= inputR;i++){
                cout<<"What disease  : ";
                cin>>relaDisease;
                cout<<"Suffered by   : ";
                cin>>relaPatient;
                rD = findDisease(LD, relaDisease);
                rP = findPatient(LP, relaPatient);
                R = newElmRelation(rD, rP);
                insertLastRelation(LR, R);
            }
            cout<<endl;
            cout<<"Back to the main menu? (Y/N) : ";
            cin>>YN;
            if(YN == "Y"){
                break;
            }else{
                cout<<"You have exited the program"<<endl;
                return 0;
            }
        case 4:
            cout<<"What disease data are you looking for? Sufferer : ";
            cin>>dataDisease;
            if(first(LR) == NULL){
                cout<<"Relation is empty"<<endl;
            }else{
                findSuffered(LR, dataDisease);
            }
            cout<<endl;
            cout<<"Back to the main menu? (Y/N) : ";
            cin>>YN;
            if(YN == "Y"){
                break;
            }else{
                cout<<"You have exited the program"<<endl;
                return 0;
            }
        case 5:
            deleteLastRelation(LR, R);
            break;
        case 6:
            cout<<"What sufferer do you want to delete : ";
            cin>>dataPatient;
            P = findRelation(LR, dataPatient);
            deleteAfterPatient(LP, pPrec, P);
            showListPatient(LP);
            cout<<endl;
            cout<<"Back to the main menu? (Y/N) : ";
            cin>>YN;
            if(YN == "Y"){
                break;
            }else{
                cout<<"You have exited the program"<<endl;
                return 0;
            }
        case 7:
            showAll(LD, LP, LR);
            cout<<endl;
            cout<<"Back to the main menu? (Y/N) : ";
            cin>>YN;
            if(YN == "Y"){
                break;
            }else{
                cout<<"You have exited the program"<<endl;
                return 0;
            }
        case 8:
            cout<<"What sufferers do you want to count : ";
            cin>>dataDisease;
            countPasient(LR, dataDisease);
            cout<<endl;
            cout<<"Back to the main menu? (Y/N) : ";
            cin>>YN;
            if(YN == "Y"){
                break;
            }else{
                cout<<"You have exited the program"<<endl;
                return 0;
            }
        case 9:
            showMostDisease(LD, LR);
            cout<<endl;
            cout<<"Back to the main menu? (Y/N) : ";
            cin>>YN;
            if(YN == "Y"){
                break;
            }else{
                cout<<"You have exited the program"<<endl;
                return 0;
            }
        }
        cout<<endl;

        choice = selectMenu();
    }
    cout<<endl;
    cout<<"You have exited the program"<<endl;
}
