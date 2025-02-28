#include "mano_lib.h"
#include "antrastes.h"

int main()
{
    srand(time(NULL));
    std::setlocale(LC_ALL, "en_US.UTF-8");
    int meniuPasirinkimas;
    vector<Stud> studentai;
    while (true)
    {
        try
        {
            cout << "Ką norėtum daryti?" << endl;
            cout << "1 - Suvesti duomenis ranka" << endl;
            cout << "2 - Sugeneruoti pažymius" << endl;
            cout << "3 - Sugeneruoti pažymius, vardus ir pavardes" << endl;
            cout << "4 - Nuskaityti duomenis iš failo" << endl;
            cout << "5 - Testuoti kodą ir išvesti 3 laikų vidurkį" << endl;
            cout << "6 - Generuoti failą" << endl;
            cout << "7 - Skaidyti failą pagal rezultatą" << endl;
            cout << "8 - Baigti darbą" << endl;
            cin >> meniuPasirinkimas;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw "Įvedėte ne skaičių!";
            }
            else if (meniuPasirinkimas < 1 || meniuPasirinkimas > 8)
                throw "Įvedėte netinkamą skaičių!";
            else
                break;
        }
        catch (const char *e)
        {
            cout << e << endl;
            continue;
        }
    }
    switch (meniuPasirinkimas)
    {
    case 4:
    {
        int isvedimoPasirinkimas;
        nuskaitymasSuBuferiu(studentai, failoPasirinkimas("Iš kurio failo norėtumėte nuskaityti duomenis?"));
        rusiavimas(studentai);
        while (true)
        {
            try
            {
                cout << "Kaip norite išvesti duomenis?" << endl;
                cout << "1 - į terminalą" << endl;
                cout << "2 - į failą" << endl;
                cin >> isvedimoPasirinkimas;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw "Įvedėte ne skaičių!";
                }
                else if (isvedimoPasirinkimas < 1 || isvedimoPasirinkimas > 2)
                    throw "Įvedėte netinkamą skaičių!";
                else
                    break;
            }
            catch (const char *e)
            {
                cout << e << endl;
                continue;
            }
        }
        if (isvedimoPasirinkimas == 1)
            isvedimas(studentai, galutinioBaloPasirinkimas(), cout);
        else
        {
            ofstream fout("rez.txt");
            isvedimas(studentai, galutinioBaloPasirinkimas(), fout);
            fout.close();
        }
    }
    break;
    case 5:
    {
        testas(failoPasirinkimas("Su kuriuo failu norėtumėte testuoti kodą?"));
    }
    break;
    case 6:
    {                
        int dydzioPasirinkimas;
        while(true)
        {
            try
            {
                cout << "Kokio ilgio failą norėtume generuoti?" << endl;
                cout << "1000" << endl;
                cout << "10000" << endl;
                cout << "100000" << endl;
                cout << "1000000" << endl;
                cout << "10000000" << endl;
                cin >> dydzioPasirinkimas;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw "Įvedėte ne skaičių!";
                }
                else if(dydzioPasirinkimas != 1000 && dydzioPasirinkimas != 10000 && dydzioPasirinkimas != 100000 && dydzioPasirinkimas!= 1000000 && dydzioPasirinkimas != 10000000)
                {
                    throw "Pasirinkote netinkamą failo ilgį";
                }
                else break;
            }
            catch(const char * e)
            {
                cout << e << endl;
                continue;
            }
        }
        auto t1=std::chrono::high_resolution_clock::now();
        failoGeneravimas(dydzioPasirinkimas);
        auto t2=std::chrono::high_resolution_clock::now();
        cout << "Failo generavimas uztruko: " << (t2-t1) /1.0s << " s." << endl;
    }break;
    case 7:
    {
        vector <Stud> protingi;
        vector <Stud> neprotingi;
        auto t1=std::chrono::high_resolution_clock::now();
        nuskaitymasSuBuferiu(studentai, failoPasirinkimas("Kuri faila noretumete testuoti?"));
        auto t2=std::chrono::high_resolution_clock::now();
        cout << "Failo nuskaitymas truko: " << (t2-t1)/1.0s << " s." << endl;
        int galutinisBalas=galutinioBaloPasirinkimas();
        auto t3=std::chrono::high_resolution_clock::now();
        isskaidymasIGrupes(studentai, protingi, neprotingi, galutinisBalas);
        auto t4=std::chrono::high_resolution_clock::now();
        cout << "Isskaidymas pagal galutini bala truko: " << (t4-t3)/1.0s << " s." << endl;
    }
    case 8:
    {
        return 0;
        break;
    }
    default:
    {
        ivedimas(studentai, meniuPasirinkimas);
        rusiavimas(studentai);
        isvedimas(studentai, galutinioBaloPasirinkimas(), cout);
    }
    break;
    }
}