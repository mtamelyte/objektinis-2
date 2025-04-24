#include "mano_lib.h"
class Stud
{
private:
    string vardas;
    string pavarde;
    double egzaminas;
    vector<int> nd;
    double galutinisSuVidurkiu;
    double galutinisSuMediana;

public:
    Stud() : vardas(""), pavarde(""), egzaminas(0), nd{}, galutinisSuVidurkiu(0), galutinisSuMediana(0) {} // konstruktorius
    Stud( const string & var, const string & pav, const int & egz, const vector<int> & nd_) : vardas(var), pavarde(pav), egzaminas(egz), nd{nd_}, galutinisSuVidurkiu(0), galutinisSuMediana(0) {} // konstruktorius su inputu
    Stud( const Stud & s);
    Stud & operator = (const Stud & s);
    Stud ( Stud&& s);
    Stud & operator = (Stud && s);
    ~Stud() {
        vardas.clear();
        pavarde.clear();
        nd.clear();
    }
    friend istream & operator >> ( istream & is, Stud & s );
    friend ostream & operator << ( ostream & os, Stud & s );
    // setteriai
    void setVardas(const string &var) { vardas = var; };
    void setPavarde(const string &pav) { pavarde = pav; };
    void setEgzaminas(const double &egz) { egzaminas = egz; };
    void setND(const vector<int> &nd_) { nd = nd_; };
    void setPazymys(const int &paz) { nd.push_back(paz); };
    void setGalutinisSuVidurkiu(const double &vid) { galutinisSuVidurkiu = vid; };
    void setGalutinisSuMediana(const double &med) { galutinisSuMediana = med; };
    // getteriai
    const string getVardas() const { return vardas; };
    const string getPavarde() const { return pavarde; };
    const double getEgzaminas() const { return egzaminas; };
    vector<int> getND() const { return nd; };
    int getPazymys(int &i) const { return nd.at(i); };
    double getGalutinisSuVidurkiu() const { return galutinisSuVidurkiu; };
    double getGalutinisSuMediana() const { return galutinisSuMediana; };

    // papildomos funkcijos
    bool studentuPalyginimas(const Stud & s);
};
