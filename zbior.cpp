#include <iostream>
#include <vector>
#include "liczbazbior.h"

using namespace std;

Zbior::Zbior(){
    Liczba temp(2);
    liczby.push_back(temp);
}


Zbior::~Zbior(){
    liczby.clear();
}

void Zbior::dodaj(){
    cout<<"Podaj liczbe binarna ktora chcesz dodac"<<endl;
    Liczba binar(1);
    if(liczby[0].wart[0]==2){
        for(int i=0;i<8;i++){
            liczby[0].wart[i]=binar.wart[i];
        }
        return;
    }
    int l;
    l=liczby.size();
    int temp, temp2;
    temp=binar.val();
    for(int i=0;i<l;i++){
        temp2=liczby[i].val();
        if(temp==temp2){
            cout<<"Taka liczba juz znajduje sie w tym zbiorze"<<endl;
            return ;
        }
    }
    liczby.push_back(binar);
    return;
}

Liczba Zbior::najmniejsza(){
    if(liczby[0].wart[0]==2){
        cout<<"Jest to zbior pusty, nie ma w nim najmniejszej cyfry, zwracam 20000000 jako pustke"<<endl;
        return liczby[0];
    }
    int l;
    l=liczby.size();
    if(l==1) return liczby[0];
    int temp,temp2, i,nr;
    nr=0;
    temp=liczby[0].val();
    for(i=1;i<l;i++){
        temp2=liczby[i].val();
        if(temp>temp2){
            temp=temp2;
            nr=i;
        }
    }
    return liczby[nr];
}

Liczba Zbior::najwieksza(){
    if(liczby[0].wart[0]==2){
        cout<<"Jest to zbior pusty, nie ma w nim najwiekszej cyfry, zwracam 20000000 jako pustke"<<endl;
        return liczby[0];
    }
    int l;
    l=liczby.size();
    if(l==1) return liczby[0];
    int temp,temp2, i, nr;
    nr=0;
    temp=liczby[0].val();
    for(i=1;i<l;i++){
        temp2=liczby[i].val();
        if(temp<temp2){
            temp=temp2;
            nr=i;
        }
    }
    return liczby[nr];
}

std::ostream & operator<<(std::ostream &wyjscie, const Zbior &s){
    if(s.liczby[0].wart[0]==2){
        wyjscie<<"zbior pusty"<<endl;
        return wyjscie;
    }
    int l;
    l=s.liczby.size();
    for(int i=0;i<l;i++){
        wyjscie<<i<<". ";
        for(int m=0;m<8;m++){
            wyjscie<<s.liczby[i].wart[m];
        }
        wyjscie<<"    ";
    }

    return wyjscie;
}

Zbior Zbior::operator+(const Zbior &s){
    Zbior pom;
    if(s.liczby[0].wart[0]==2 && liczby[0].wart[0]==2){
        cout<<"Dodajesz dwa zbiory puste, zwracam 20000000, jako zbior pusty"<<endl;
    return pom;
    }
    if(s.liczby[0].wart[0]==2){
        return pom;
    }

    if(liczby[0].wart[0]==2)
        return pom;

    int l,k,checker;

    l=liczby.size();
    for(int i=0;i<8;i++)
    pom.liczby[0].wart[i]=liczby[0].wart[i];
    for(int i=1;i<l;i++){
        pom.liczby.push_back(liczby[i]);
    }
    k=s.liczby.size();
    for(int i=0;i<k;i++){
        checker=0;
        for(int n=0;n<l;n++){
            if(pom.wartosc(n)==s.wartosc(i))
                checker++;
        }
        if(checker==0)
            pom.liczby.push_back(s.liczby[i]);
    }

    return pom;
}

Zbior Zbior::operator+=(const Zbior &s){
    if(s.liczby[0].wart[0]==2 && liczby[0].wart[0]==2){
        cout<<"Dodajesz dwa zbiory puste, zwracam 20000000, jako zbior pusty"<<endl;
        return s;
    }
    if(s.liczby[0].wart[0]==2){
        return *this;
    }

    if(liczby[0].wart[0]==2)
        return s;

    int l,k, checker;
    l=liczby.size();
    k=s.liczby.size();
    for(int i=0;i<k;i++){
            checker=0;
        for(int n=0;n<l;n++){
            if(s.wartosc(i)==this->wartosc(n))
                checker++;
        }
        if(checker==0)
            this->liczby.push_back(s.liczby[i]);
    }

    return *this;
}

Zbior Zbior::operator*=(const Zbior &s){
    if(s.liczby[0].wart[0]==2 && liczby[0].wart[0]==2){
        cout<<"Iloczyn logiczny dwoch zbiorow pustych. Zwracam 20000000, jako zbior pusty"<<endl;
        return *this;
    }
    if(s.liczby[0].wart[0]==2){
        cout<<"Iloczyn logiczny zbioru pustego z innym zbiorem. Zwracam 20000000, jako zbior pusty"<<endl;
        return *this;
    }

    if(liczby[0].wart[0]==2){
        cout<<"Iloczyn logiczny zbioru pustego z innym zbiorem. Zwracam 20000000, jako zbior pusty"<<endl;
        return s;
    }
    int l,k,check;
    l=liczby.size();
    k=s.liczby.size();
    for(int i=0;i<l;i++){
        check=0;
        for(int n=0;n<k;n++){
            if(s.wartosc(n)==this->wartosc(i)){
                check++;
            }
        }
        if(check==0){
            this->liczby.erase(this->liczby.begin()+i);
			i--;
			l--;
		}
    }

    return *this;
}

Zbior Zbior::operator*(const Zbior &s){
    Zbior pom;
    if(s.liczby[0].wart[0]==2 && liczby[0].wart[0]==2){
        cout<<"Iloczyn logiczny dwoch zbiorow pustych. Zwracam 20000000, jako zbior pusty"<<endl;
        return pom;
    }
    if(s.liczby[0].wart[0]==2){
        cout<<"Iloczyn logiczny zbioru pustego z innym zbiorem. Zwracam 20000000, jako zbior pusty"<<endl;
        return pom;
    }

    if(liczby[0].wart[0]==2){
        cout<<"Iloczyn logiczny zbioru pustego z innym zbiorem. Zwracam 20000000, jako zbior pusty"<<endl;
        return pom;
    }


    int l,k,check;
    l=liczby.size();
    k=s.liczby.size();
    for(int i=0;i<8;i++)
        pom.liczby[0].wart[i]=liczby[0].wart[i];

    for(int i=1;i<l;i++)
        pom.liczby.push_back(liczby[i]);

    for(int i=0;i<l;i++){
        check=0;
        for(int n=0;n<k;n++){
            if(s.wartosc(n)==this->wartosc(i)){
                check++;
            }
        }
        if(check==0){
            pom.liczby.erase(pom.liczby.begin()+i);
			
        }
    }

    return pom;

}

int Zbior::wartosc(int n)const{

    int temp;
    if(liczby[n].wart[0]==2){
        temp=9999;
        return temp;
    }
    temp=128*liczby[n].wart[1]+64*liczby[n].wart[2]+32*liczby[n].wart[3]+16*liczby[n].wart[4]+8*liczby[n].wart[5]+4*liczby[n].wart[6]+2*liczby[n].wart[7];
    if(liczby[n].wart[0]==1)
        temp=-temp;
    return temp;
}
