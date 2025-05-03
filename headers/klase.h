#include "mano_lib.h"
#include "antrastesBeTemplates.h"

class Zmogus
{
protected:
    string vardas;
    string pavarde;

public:
    Zmogus() : vardas(""), pavarde("") {}                                       // konstruktorius
    Zmogus(const string &var, const string &pav) : vardas(var), pavarde(pav) {} // konstruktorius su inputu
    virtual ~Zmogus() = 0;
    // setteriai
    void setVardas(const string &var) { vardas = var; };
    void setPavarde(const string &pav) { pavarde = pav; };
    // getteriai
    const string getVardas() const { return vardas; };
    const string getPavarde() const { return pavarde; };
};
class Stud : public Zmogus
{
private:
    double egzaminas;
    vector<int> nd;
    double galutinisSuVidurkiu = balasSuVidurkiu();
    double galutinisSuMediana = balasSuMediana();

public:
    Stud() : Zmogus("", ""), egzaminas(0), nd{}, galutinisSuVidurkiu(0), galutinisSuMediana(0) {}                                                                                    // konstruktorius
    Stud(const string &var, const string &pav, const int &egz, const vector<int> &nd_) : Zmogus(var, pav), egzaminas(egz), nd{nd_}, galutinisSuVidurkiu(0), galutinisSuMediana(0) {} // konstruktorius su inputu
    Stud(const Stud &s);
    Stud &operator=(const Stud &s);
    Stud(Stud &&s);
    Stud &operator=(Stud &&s);
    ~Stud()
    {
        vardas.clear();
        pavarde.clear();
        nd.clear();
        egzaminas = 0;
        galutinisSuVidurkiu = 0;
        galutinisSuMediana = 0;
    }
    friend istream &operator>>(istream &is, Stud &s);
    friend ostream &operator<<(ostream &os, Stud &s);
    // setteriai
    void setEgzaminas(const double &egz) { egzaminas = egz; };
    void setND(const vector<int> &nd_) { nd = nd_; };
    void setPazymys(const int &paz) { nd.push_back(paz); };
    void setGalutinisSuVidurkiu(const double &vid) { galutinisSuVidurkiu = vid; };
    void setGalutinisSuMediana(const double &med) { galutinisSuMediana = med; };
    // getteriai
    const double getEgzaminas() const { return egzaminas; };
    vector<int> getND() const { return nd; };
    int getPazymys(int &i) const { return nd.at(i); };
    double getGalutinisSuVidurkiu() const { return galutinisSuVidurkiu; };
    double getGalutinisSuMediana() const { return galutinisSuMediana; };

    // papildomos funkcijos
    bool studentuPalyginimas(const Stud &s);
    double balasSuVidurkiu()
    {
        double suma = 0;
        for (int i : nd)
        {
            suma += i;
        }
        return (suma / nd.size()) * 0.4 + egzaminas * 0.6;
    }
    double balasSuMediana()
    {
        int dydis;
        sort(nd.begin(), nd.end());
        dydis = nd.size();
        if (dydis % 2 == 0)
            return ((nd[dydis / 2] + nd[(dydis / 2) - 1]) / 2)*0.4 + egzaminas * 0.6;
        else
            return (nd[floor(nd.size() / 2)])*0.4 + egzaminas * 0.6;;
    }
};
