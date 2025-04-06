#include "mano_lib.h"
 class Stud
 {
 private:
     std::string vardas;
     std::string pavarde;
     double egzaminas;
     std::vector<double> nd;
 
 public:
     Stud() : var(""), pav(""), egz(0), nd{} {} // konstruktorius
     ~Stud {}                                   // destruktorius
     // setteriai
     void setVardas(const string &var) { vardas = var };
     void setPavarde(const string &pav) { pavarde = pav };
     void setEgzaminas(const double &egz) { egzaminas = egz };
     void setND(const vector <double> & nd_) { nd=nd_};
     //getteriai
     string getVardas() const { return vardas };
     string getPavarde() const { return pavarde };
     double getEgzaminas () const {return egzaminas };
     vector <double> getND () const { return nd} ;
 };