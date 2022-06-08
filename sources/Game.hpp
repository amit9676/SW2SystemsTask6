#pragma once
#include <string>
#include "Team.hpp"

using namespace std;

namespace amit{
    class Game
    {
        private:
            Team* teamHome;
            Team* teamAway;

            int scoreHome;
            int socreAway;

            void winCheck(Team*);
            void loseCheck(Team*);
            void talentCheck(Team*, Team*);


        public:
            Game(Team*, Team*);
            Team* getTeamHome();
            Team* getTeamAway();
            int getScoreHome();
            int getScoreAway();
            


    };
}