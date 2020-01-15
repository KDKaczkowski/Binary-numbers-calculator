#ifndef LICZBA_H_INCLUDED
#define LICZBA_H_INCLUDED
#include <vector>
#include <iostream>
using namespace std;

class Liczba{
    public:
    vector <int> wart;              //Wektor przechowujacy dana liczbe

    Liczba(int);                    //konstruktor liczby, pobierac wartosc 2 lub 1. Dla wartosci 2 tworzy liczbe symoblizujaca pusty zbior
                                    //dla wartosci 1 tworzy liczbe taka jaka poda uzytkownik przy pomocy funkcji wczytaj
    ~Liczba();
    void wypisz();                  //wypisuje dana liczbe na ekran
    int val();                      //zwraca wartosc liczby w systemie dziesietnym
    int wczytaj(int ster);
};

class Zbior{
    public:
    vector <Liczba> liczby;         //wektor symbolizujacy zbior, przechowuje liczby binarne zawarte w zbiorze

public:
    Zbior();                        //konstruktor, tworzy zbior pusty
    ~Zbior();                       // destruktor usuwa dany zbior
    //void wypelnij();
    void dodaj();                   //funkcja ktora dodaje do zbioru liczbe podana przez uzytkownika, sprawdzajac czy juz nie ma takiej
    int wartosc(int n)const;        //funkcja zwracajaca wartosc dla danej liczby o numerze n w zbiorze
    Liczba najmniejsza();           //Funckja zwraca najmniejsza liczbe z danego zbioru
    Liczba najwieksza();            //Funkcja zwraca najwieksza liczbe z danego zbioru

    friend std::ostream & operator<<(std::ostream &wyjscie, const Zbior &s);      //Przeciazenie operatora (<<) dla klasy
    Zbior operator +(const Zbior &s);                                   //Przeciazenie operatora (+) dla klasy
    Zbior operator +=(const Zbior&s);                                   //Przeciazenie operatora (+=) dla klasy
    Zbior operator *(const Zbior &s);                                   //Przeciazenie operatora (*) dla klasy
    Zbior operator *=(const Zbior &s);                                  //Przeciazenie operatora (*=) dla klasy


};

#endif
