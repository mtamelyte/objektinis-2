#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../headers/klase.h"
#include "../headers/mano_lib.h"

TEST_CASE("Testuojamas konstruktorius", "[Constructor]"){
    Stud s1, s2;
    REQUIRE(s1==Stud("","",0, {}));
    REQUIRE(s1==s2);
}

TEST_CASE("Testuojamas kopijavimo konstruktorius", "[Copy][constructor]"){
    Stud s1("Monika", "Tamelyte", 10, {8, 9, 10});
    Stud s2(s1);
    REQUIRE(s1==s2);
}

TEST_CASE("Testuojamas kopijavimo priskyrimo operatorius", "[Copy][assignment][operator]"){
    Stud s1("Monika", "Tamelyte", 10, {8, 9, 10});
    Stud s2=s1;
    REQUIRE(s1==s2);
}

TEST_CASE("Testuojamas move konstruktorius", "[Move][constructor]"){
    Stud studentas1("Monika", "Tamelyte", 10, {8, 9, 10});
    Stud studentas2(move(studentas1));
    REQUIRE(studentas2==Stud("Monika", "Tamelyte", 10, {8, 9, 10}));
    REQUIRE(studentas1==Stud("", "", 0, {}));
}

TEST_CASE("Testuojamas move priskyrimo operatorius", "[Move][assignment][operator]"){
    Stud studentas1("Monika", "Tamelyte", 10, {8, 9, 10});
    Stud studentas2=move(studentas1);
    REQUIRE(studentas2==Stud("Monika", "Tamelyte", 10, {8, 9, 10}));
    REQUIRE(studentas1==Stud("", "", 0, {}));
}
/*
void ivestiesTestas(){
    istringstream ivestis("Monika Tamelyte 3 6 1 9 10 4 5");
    Stud studentas;
    ivestis >> studentas;
    vector <int> testPaz={3, 6, 1, 9, 10, 4};
    if(studentas.getVardas()=="Monika" && studentas.getPavarde()=="Tamelyte" && studentas.getND()==testPaz && studentas.getEgzaminas()==5)
    {
        cout << "Input operator veikia" << endl;
    }
}

void isvestiesTestas(){
    ostringstream isvestis, isvestisTest;
    Stud studentas;
    studentas.setVardas("Monika");
    studentas.setPavarde("Tamelyte");
    studentas.setGalutinisSuVidurkiu((vidurkis({3, 6, 1, 9, 10, 4}) * 0.4) + (5 * 0.6));
    isvestisTest << setw(16) << "Monika" << setw(16) << "Tamelyte" << setw(20) << fixed << setprecision(2) << ((vidurkis({3, 6, 1, 9, 10, 4}) * 0.4) + (5 * 0.6)) << endl;
    isvestis << studentas;
    if(isvestis.str()==isvestisTest.str()) cout << "Output operator veikia" << endl;
}


void destruktoriausTestas(){
    Stud jonas;
    jonas.setVardas("Jonas");
    jonas.~Stud();
    if(jonas.getVardas()!="Jonas") cout << "Destruktorius veikia" << endl;
}*/