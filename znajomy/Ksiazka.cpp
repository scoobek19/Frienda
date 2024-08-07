//
// Created by lip_k on 4/15/2024.
//
#include "Ksiazka.h"

Ksiazka::Ksiazka() {};
void Ksiazka::dodaj(Osoba przyj) {
    ksiaz.push_back(przyj);
    sortuj();
    przemebluj();
}

void Ksiazka::usun(int id) {
    ksiaz.erase(ksiaz.begin()+id);
    przemebluj();

}

void Ksiazka::sortuj(){
    sort(ksiaz.begin(),ksiaz.end(),
         [](Osoba left, Osoba right)
         { return left.getImie() < right.getImie();});
}

const vector<Osoba>& Ksiazka::lista()const{
    return ksiaz;
};

void Ksiazka::przemebluj() {
    int k=0;
    for(auto& x:ksiaz){
        x.setID(k);
        k=k+1;
    }
}

bool Ksiazka::czy_pusta() {
    return ksiaz.empty();
}

void Ksiazka::wypozycz(const Osoba &wlasciciel, const Osoba &wypozyczajacy, const std::string& tytul_ksiazki) {
    wypozyczenia.push_back(Wypozyczenie{
        .wlasciciel = wlasciciel,
        .wypozyczajacy = wypozyczajacy,
        .tytul_ksiazki = tytul_ksiazki,
        .czas_wypozyczenia = std::chrono::system_clock::now()
    });
}

const Osoba& Ksiazka::znajdz_osobe(int id) const {
    for (auto& osoba : lista()) {
        if (osoba.getID() == id) {
            return osoba;
        }
    }

    throw "brak osoby o podanym id: " + to_string(id);
}

const vector<Wypozyczenie>& Ksiazka::wszystkie_wypozyczenia() const {
    return wypozyczenia;
}