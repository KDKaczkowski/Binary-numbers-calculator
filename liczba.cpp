#include <iostream>
#include "liczbazbior.h"
#include <cstdio>
#include <vector>
using namespace std;

Liczba::Liczba(int ster) {
    while(wczytaj(ster)==0);
}
Liczba::~Liczba(){
    wart.clear();
}

void Liczba::wypisz() {
    if(wart[0]==2){
        cout<<"Zbior pusty"<<endl;
        return;
    }
    for(int i=0;i<8;i++){
        cout<<wart[i];
    }
    cout<<endl;
}

int Liczba::wczytaj(int ster){

    int temp[8];
    if(ster==2){
        temp[0]=2;
        for(int i=0;i<8;i++){
        wart.push_back(temp[i]);
        }
        return 1;
    }
    if(ster==1){
        char tab[8];
        scanf("%s", tab);

        for(int i=0;i<8;i++){
            temp[i]=tab[i]-48;
            if(temp[i]==0 || temp[i]==1){
                continue;
            }
            else{
                cout << "Wczytywanie nie powiodlo sie."<<endl<<"Zacznij wczytywanie od nowa."<<endl<<endl;
                return 0;
            }
        }
        for(int i=0;i<8;i++){
        wart.push_back(temp[i]);
        }

    }
    return 1;
}
int Liczba::val(){

    int temp;
    if(wart[0]==2){
        temp=9999;
        return temp;
    }
    temp=128*wart[1]+64*wart[2]+32*wart[3]+16*wart[4]+8*wart[5]+4*wart[6]+2*wart[7];
    if(wart[0]==1)
        temp=-temp;
    return temp;
}
