#include "headers/klase.h"

// copy constructorius
Stud::Stud( const Stud & s) : vardas(s.vardas), pavarde(s.pavarde), egzaminas(s.egzaminas), nd{s.nd}, galutinisSuVidurkiu(s.galutinisSuVidurkiu), galutinisSuMediana(s.galutinisSuMediana) {} 

// copy assignment operator
Stud & Stud::operator = (const Stud & s){ 
    if (this != &s)
    { vardas=s.vardas;
    pavarde=s.pavarde;
    egzaminas=s.egzaminas;
    nd=s.nd;
    galutinisSuVidurkiu=s.galutinisSuVidurkiu;
    galutinisSuMediana=s.galutinisSuMediana;
    }
    return *this;
}

//move konstruktorius
Stud::Stud ( Stud&& s) : vardas(move(s.vardas)), pavarde(move(s.pavarde)), egzaminas(s.egzaminas), nd{move(s.nd)}, galutinisSuVidurkiu(move(s.galutinisSuVidurkiu)), galutinisSuMediana(move(s.galutinisSuMediana)) {} 

//move assignment operatorius
Stud & Stud::operator = (Stud && s){
    if(this != &s){
        vardas= move(s.vardas);
        pavarde = move(s.pavarde);
        egzaminas = move(s.egzaminas);
        nd = move(s.nd);
        galutinisSuVidurkiu = move(s.galutinisSuVidurkiu);
        galutinisSuMediana = move(s.galutinisSuMediana);
    }
    return *this;
}

bool Stud::studentuPalyginimas(const Stud & s){
    bool lygus=false;
    if(vardas==s.vardas && pavarde==s.pavarde && egzaminas==s.egzaminas && nd==s.nd) lygus=true;
    return lygus;
}