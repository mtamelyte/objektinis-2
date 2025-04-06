#include "mano_lib.h"
class Stud
{
private:
    std::string vardas;
    std::string pavarde;
    double egzaminas;
    std::vector<int> nd;
    double galutinisSuVidurkiu;
    double galutinisSuMediana;

public:
    Stud() : vardas(""), pavarde(""), egzaminas(0), nd{}, galutinisSuVidurkiu(0), galutinisSuMediana(0) {} // konstruktorius
    ~Stud() {}
    // setteriai
    void setVardas(const string &var) { vardas = var; };
    void setPavarde(const string &pav) { pavarde = pav; };
    void setEgzaminas(const double &egz) { egzaminas = egz; };
    void setND(const vector<int> &nd_) { nd = nd_; };
    void setPazymys(const int &paz) { nd.push_back(paz); };
    void setGalutinisSuVidurkiu(const double &vid) { galutinisSuVidurkiu = vid; };
    void setGalutinisSuMediana(const double &med) { galutinisSuMediana = med; };
    // getteriai
    string getVardas() const { return vardas; };
    string getPavarde() const { return pavarde; };
    double getEgzaminas() const { return egzaminas; };
    vector<int> getND() const { return nd ;};
     int getPazymys(int &i) const { return nd.at(i); };
    double getGalutinisSuVidurkiu() const { return galutinisSuVidurkiu; };
    double getGalutinisSuMediana() const { return galutinisSuMediana; };
}