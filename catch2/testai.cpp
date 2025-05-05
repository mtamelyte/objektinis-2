#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../headers/klase.h"
#include "../headers/mano_lib.h"

TEST_CASE("Testuojamas konstruktorius", "[Constructor]"){
    Stud s1, s2;
    CHECK(s1==Stud("","",0, {}));
    REQUIRE(s1==s2);
}