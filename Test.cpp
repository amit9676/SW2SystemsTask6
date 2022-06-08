#include "doctest.h"
#include "sources/Leauge.hpp"
using namespace amit;

TEST_CASE("teamMaker"){
    std::vector<Team*> allTeams;
    CHECK_THROWS(allTeams.push_back(new Team("")));
    CHECK_THROWS(allTeams.push_back(new Team("\r")));
    CHECK_THROWS(allTeams.push_back(new Team("\n")));
    CHECK_THROWS(allTeams.push_back(new Team("\t")));
    CHECK_THROWS(allTeams.push_back(new Team("\r")));
    CHECK_THROWS(allTeams.push_back(new Team(" ")));
    CHECK_THROWS(allTeams.push_back(new Team("           ")));
    CHECK_NOTHROW(allTeams.push_back(new Team(":)    ",0.1)));
    CHECK_NOTHROW(allTeams.push_back(new Team(":)    ")));
    CHECK_THROWS(allTeams.push_back(new Team(" :)    ",1.1)));
    CHECK_NOTHROW(allTeams.push_back(new Team("amit")));
    CHECK_NOTHROW(allTeams.push_back(new Team("amit1")));
    CHECK_NOTHROW(allTeams.push_back(new Team("fdsfds2 dsfds")));

}

TEST_CASE("league1"){
    vector<Team*> xx = {};
    for(int i = 0; i < 10; i++){
        xx.insert(xx.end(),new Team{to_string(i)});
    }
    
    League x = League{xx};
    CHECK_EQ(x.getTeams().size(), 20);
    CHECK_THROWS(x.runStatistics(3));
    x.runGames();
    CHECK_THROWS(x.runStatistics(21));
    CHECK_NOTHROW(x.runStatistics(3));
}

TEST_CASE("league2"){
    
    League x = League{};
    CHECK_EQ(x.getTeams().size(), 20);
    CHECK_THROWS(x.runStatistics(3));
    x.runGames();
    CHECK_THROWS(x.runStatistics(21));
    CHECK_NOTHROW(x.runStatistics(3));
}
