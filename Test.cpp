#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;


string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good snowman code") {
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(12423141)) == nospaces("_===_\n(-.o)\n/(   )>\n( : )"));
    CHECK(nospaces(snowman(21221144)) == nospaces(" ___ \n.....\n(o,o)\n<(   )>\n(   )"));
    CHECK(nospaces(snowman(23113221)) == nospaces(" ___ \n.....\n(._.)/\n/(] [)\n( : )"));
    CHECK(nospaces(snowman(33233114)) == nospaces("  _  \n /_\\ \n(o_O)\n/( : )>\n(   )"));
    CHECK(nospaces(snowman(44342332)) == nospaces(" ___ \n(_*_)\n \\(O -)\n(> <)\\ \n(" ")"));

}

TEST_CASE("Bad snowman code") {
    
    /* Illegal digits */
    CHECK_THROWS(snowman(81));
    CHECK_THROWS(snowman(3537));
    CHECK_THROWS(snowman(748216));
    CHECK_THROWS(snowman(11223345));
    CHECK_THROWS(snowman(22211634));
    CHECK_THROWS(snowman(11111119));

    /* Lower then 8 digits */
    CHECK_THROWS(snowman(123));
    CHECK_THROWS(snowman(4321));
    CHECK_THROWS(snowman(21212));
    CHECK_THROWS(snowman(321123));

    /* Higher then 8 digits */
    CHECK_THROWS(snowman(123123123));
    CHECK_THROWS(snowman(432121234));
    CHECK_THROWS(snowman(111121111));


    /* Negative digits */
    CHECK_THROWS(snowman(-1214));
    CHECK_THROWS(snowman(-423411));
    CHECK_THROWS(snowman(-14222412));
    CHECK_THROWS(snowman(-12344321));
}