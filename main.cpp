#include <iostream>
#include "liczbazbior.h"
#include <vector>


using namespace std;


int main() {
    int start, sterowanie,praca;

    praca=1;
    int N1;
    N1=0;
    cout<<"Witam w programie tworzacym i manipulujacym zbiorami 8-bitowych liczb binarny"<<endl<<endl;
    cout<<"Wybierz 1, jezeli chcesz wlaczyc menu lub 0 by wyjsc z programu"<<endl;
    while(1){
        cin>>start;
        if(start==0)
            return 0;
        else if(start==1){
            break;
        }
        else{
            cout<<"Podano zle dane, sprobuj jeszcze raz wybierajac 0 lub 1"<<endl;
        }
    }
    vector <Zbior> Zbiory;
    while(praca){
        cout<<"----------MENU WYBORU----------"<<endl;
        cout<<"1.Utworz nowy zbior pusty"<<endl;
        cout<<"2.Dodaj liczbe do zbioru"<<endl;
        cout<<"3.Znajdz najmniejsza liczbe w zbiorze"<<endl;
        cout<<"4.Znajdz najwieksza liczbe w zbiorze"<<endl;
        cout<<"5.Utworz nowy zbior bedacy suma dwoch innych"<<endl;
        cout<<"6.Dodaj zbior do istniejacego zbioru"<<endl;
        cout<<"7.lloczyn logiczny dwoch zbiorow, tworzacy nowy zbior"<<endl;
        cout<<"8.Iloczyn logiczny dwoch zbiorow, zmieniajacy istniejacy zbior"<<endl;
        cout<<"9.Drukowanie zbioru"<<endl;
        cout<<"10.Usuwanie zbioru"<<endl;
        cout<<"0.Koniec pracy programu"<<endl;
        cout<<"-------------------------------"<<endl;
        cin>>sterowanie;
        if(sterowanie!=0&&sterowanie!=1&&sterowanie!=2&&sterowanie!=3&&sterowanie!=4&&sterowanie!=5&&sterowanie!=6&&sterowanie!=7&&sterowanie!=8&&sterowanie!=9&&sterowanie!=10){
            cout<<"Nie ma takiej opcji w menu. Sprobuj jeszcze raz"<<endl;
            continue;
        }
        switch(sterowanie){
        case 0:
            {
            Zbiory.clear();

            return 0;
            }
        case 1:
            {
            Zbior sec;
            Zbiory.push_back(sec);
            cout<<"Dodano nowy zbior pusty o numerze: "<<N1<<endl;
            N1++;
            continue;
            }
        case 2:
            {
            int l;
            l=Zbiory.size();
            if(l==0){
                cout<<"Nie ma jeszcze zbioru do ktorego mozesz wpisac liczbe, najpierw utworz zbior pusty."<<endl;
                continue;
            }
            else if(l==1){
                Zbiory[0].dodaj();
                continue;
            }
            else if(l>1){
                int n;
                cout<<"Podaj numer zbioru do ktorego chcesz dodac liczbe"<<endl;
                for(int i=0;i<l;i++){
                    cout<<"Zbior numer: "<<i<<". : ";
                    cout<<Zbiory[i];
                    cout<<endl;
                }
                cin>>n;
                if(n>=l||n<0){
                    cout<<"Nie ma takiego zbioru, wracasz do menu"<<endl;
                    continue;
                }
                else{
                    Zbiory[n].dodaj();
                    continue;
                }
            }
            }
        case 3:
            {
                int l;
                l=Zbiory.size();
                if(l==0){
                    cout<<"Nie ma jeszcze zbioru w ktorym moglbys znalezc najmniejsza liczbe, najpierw utworz zbior."<<endl;
                    continue;
                }
                int n;
                cout<<"Podaj numer zbioru w ktorym chcesz znalezc najmniejsza liczbe"<<endl;
                for(int i=0;i<l;i++){
                    cout<<"Zbior numer: "<<i<<". : ";
                    cout<<Zbiory[i];
                    cout<<endl;
                }
                cin>>n;
                if(n>=l||n<0){
                    cout<<"Nie ma takiego zbioru, wracasz do menu"<<endl;
                    continue;
                }
                else{
                    cout<<"Najmniejsza liczba: ";
                    Zbiory[n].najmniejsza().wypisz();
                    continue;
                }

            }
        case 4:
            {
                int l;
                l=Zbiory.size();
                if(l==0){
                    cout<<"Nie ma jeszcze zbioru w ktorym moglbys znalezc najwieksza liczbe, najpierw utworz zbior."<<endl;
                    continue;
                }
                int n;
                cout<<"Podaj numer zbioru w ktorym chcesz znalezc najwieksza liczbe"<<endl;
                for(int i=0;i<l;i++){
                    cout<<"Zbior numer: "<<i<<". : ";
                    cout<<Zbiory[i];
                    cout<<endl;
                }
                cin>>n;
                if(n>=l||n<0){
                    cout<<"Nie ma takiego zbioru, wracasz do menu"<<endl;
                    continue;
                }
                else{
                    cout<<"Najwieksza liczba: ";
                    Zbiory[n].najwieksza().wypisz();
                    continue;
                }

            }
        case 5:
            {
                int l;
                l=Zbiory.size();
                if(l==0){
                    cout<<"Nie zostal jeszcze utworzony zaden zbior, wracasz do MENU."<<endl<<"Utworz najpierw zbior"<<endl;
                    continue;
                }
                else if(l==1){
                    int choice;
                    cout<<"Masz utworzony tylko jeden zbior. Zsumowanie go ze soba da nowy zbior bedacy kopia obecnego."<<endl;
                    cout<<"Czy chcesz to zrobic?"<<endl<<"Tak: 1  Nie: 0"<<endl;
                    cin>>choice;
                    if(choice==0)
                        continue;
                    else if(choice==1){
                        Zbiory.push_back(Zbiory[0]+Zbiory[0]);
                        continue;
                    }
                    else{
                        cout<<"Podano zla wartosc jako wybor, czynnosc nie zostala wykonana"<<endl;
                        continue;
                    }
                }
                int n,m;


                for(int i=0;i<l;i++){
                    cout<<"Zbior numer: "<<i<<". : ";
                    cout<<Zbiory[i];
                    cout<<endl;
                }
                cout<<endl<<"Podaj numery zbiorów ktore chcesz zsumowac"<<endl;
                cout<<"Zbior pierwszy: ";
                cin>>n;
                cout<<endl<<"Zbior drugi: ";
                cin>>m;
                if(n>=l||n<0||m<0||m>=l){
                    cout<<"Nie ma takiego zbioru, wracasz do menu"<<endl;
                    continue;
                }
                cout<<endl;
                Zbiory.push_back(Zbiory[n]+Zbiory[m]);
                cout<<"Dodano nowy zbior o numerze: "<<l<<endl;
                continue;
            }
        case 6:
            {
                int l;
                l=Zbiory.size();
                if(l==0){
                    cout<<"Nie zostal jeszcze utworzony zaden zbior, wracasz do MENU."<<endl<<"Utworz najpierw zbior"<<endl;
                    continue;
                }
                else if(l==1){
                    cout<<"Masz utworzony tylko jeden zbior. Dodanie go do siebie nic nie zmieni"<<endl;
                    continue;
                }
                int n,m;

                for(int i=0;i<l;i++){
                    cout<<"Zbior numer: "<<i<<". : ";
                    cout<<Zbiory[i];
                    cout<<endl;
                }
                cout<<endl<<"Podaj numer zbioru (zbior pierwszy) do ktorego chcesz dodac inny zbior(zbior drugi)."<<endl;
                cout<<"Zbior pierwszy: ";
                cin>>n;
                cout<<endl<<"Zbior drugi: ";
                cin>>m;
                if(n>=l||n<0||m<0||m>=l){
                    cout<<"Nie ma takiego zbioru, wracasz do menu"<<endl;
                    continue;
                }
                cout<<endl;
                Zbiory[n]+=Zbiory[m];
                continue;
            }
        case 7:
            {
                int l;
                l=Zbiory.size();
                if(l==0){
                    cout<<"Nie zostal jeszcze utworzony zaden zbior, wracasz do MENU."<<endl<<"Utworz najpierw zbior."<<endl;
                    continue;
                }
                else if(l==1){
                    int choice;
                    cout<<"Masz utworzony tylko jeden zbior. Iloczyn logiczny zbioru samego ze soba utworzy nowy zbior bedacy jego kopia"<<endl;
                    cout<<"Czy chcesz to zrobic?"<<endl<<"Tak: 1 Nie: 0"<<endl;
                    cin>>choice;
                    if(choice==0)
                        continue;
                    else if(choice==1){
                        Zbiory.push_back(Zbiory[0]*Zbiory[0]);
                        continue;
                    }
                    else{
                        cout<<"Podano zla wartosc jako wybor, czynnosc nie zostala wykonana"<<endl;
                        continue;
                    }

                }
                int n,m;

                for(int i=0;i<l;i++){
                    cout<<"Zbior numer: "<<i<<". : ";
                    cout<<Zbiory[i];
                    cout<<endl;
                }
                cout<<endl<<"Podaj numer zbiorow na ktorych chcesz wykonac operacje iloczynu logicznego zbiorow."<<endl;
                cout<<"Zbior pierwszy: ";
                cin>>n;
                cout<<endl<<"Zbior drugi: ";
                cin>>m;
                if(n>=l||n<0||m<0||m>=l){
                    cout<<"Nie ma takiego zbioru, wracasz do menu"<<endl;
                    continue;
                }
                cout<<endl;
                Zbiory.push_back(Zbiory[n]*Zbiory[m]);
                cout<<"Dodano nowy zbior o numerze: "<<l<<endl;
                continue;
            }
        case 8:
            {
                int l;
                l=Zbiory.size();
                if(l==0){
                    cout<<"Nie zostal jeszcze utworzony zaden zbior, wracasz do MENU."<<endl<<"Utworz najpierw zbior."<<endl;
                    continue;
                }
                else if(l==1){
                    cout<<"Masz utworzony tylko jeden zbior. Iloczyn logiczny zbioru z samym soba nic nie zmieni."<<endl;
                    continue;
                }
                int n,m;

                for(int i=0;i<l;i++){
                    cout<<"Zbior numer: "<<i<<". : ";
                    cout<<Zbiory[i];
                    cout<<endl;
                }
                cout<<endl<<"Podaj numer zbioru pierwszego oraz zbioru drugiego."<<endl<<"Zbior pierwszy zostanie zmieniony w wyniku iloczynu logicznego zbiorow"<<endl;
                cout<<"Zbior pierwszy: ";
                cin>>n;
                cout<<endl<<"Zbior drugi: ";
                cin>>m;
                if(n>=l||n<0||m<0||m>=l){
                    cout<<"Nie ma takiego zbioru, wracasz do menu"<<endl;
                    continue;
                }
                cout<<endl;
                Zbiory[n]*=Zbiory[m];
                continue;
            }
        case 9:
            {
                int l;
                l=Zbiory.size();
                if(l==0){
                    cout<<"Nie zostal jeszcze utworzony zaden zbior, wracasz do MENU."<<endl<<"Utworz najpierw zbior."<<endl;
                    continue;
                }
                for(int i=0;i<l;i++){
                    cout<<"Zbior numer: "<<i<<". : ";
                    cout<<Zbiory[i];
                    cout<<endl;
                }
                continue;
            }
        case 10:
            {
                int l;
                l=Zbiory.size();
                if(l==0){
                    cout<<"Nie zostal jeszcze utworzony zaden zbior, wracasz do MENU."<<endl<<"Utworz najpierw zbior."<<endl;
                    continue;
                }
                for(int i=0;i<l;i++){
                    cout<<"Zbior numer: "<<i<<". : ";
                    cout<<Zbiory[i];
                    cout<<endl;
                }
                int n;
                cout<<"Podaj numer zbioru ktory chcesz usunac"<<endl;
                cin>>n;
                if(n>=l||n<0){
                    cout<<"Nie ma takiego zbioru, wracasz do menu"<<endl;
                    continue;
                }
                Zbiory.erase(Zbiory.begin()+n);
            }


        }
    }
    return 0;

}
