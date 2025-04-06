#include "mano_lib.h"
 class Stud
 {
 private:
     std::string vardas;
     std::string pavarde;
     double egzaminas;
     std::vector<double> nd;
     double galutinisSuVidurkiu;
     double galutinisSuMediana;
 
 public:
     Stud() : var(""), pav(""), egz(0), nd{} {} // konstruktorius
     ~Stud {}                                   // destruktorius
     // setteriai
     void setVardas(const string &var) { vardas = var };
     void setPavarde(const string &pav) { pavarde = pav };
     void setEgzaminas(const double &egz) { egzaminas = egz };
     void setND(const vector<double> &nd_) { nd = nd_ };
     void setPazymys(const double &paz) { nd.push_back(paz) };
     void setGalutinisSuVidurkiu(const double &vid) { galutinisSuVidurkiu = vid };
     void setGalutinisSuMediana(const double &med) { galutinisSuMediana = med };
     // getteriai
     string getVardas() const { return vardas };
     string getPavarde() const { return pavarde };
     double getEgzaminas() const { return egzaminas };
     vector<double> getND() const { return nd };
     double getPazymys(int &i) const { return nd.at(i) };
     double getGalutinisSuVidurkiu() const { return galutinisSuVidurkiu };
     double getGalutinisSuMediana() const { return galutinisSuMediana };
 };