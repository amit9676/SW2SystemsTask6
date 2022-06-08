#pragma once
#include "Schedule.hpp"
using namespace std;

namespace amit{
    class League
    {
        private:
            vector<Team*> teams;
            vector<Team> v2 = {};
            double getRandomZeroToOne();
            bool gameStarted;
            
            

        public:
            League();
            League(vector<Team*>);
            void runGames();
            void runStatistics(int);
            vector<Team*> getTeams();
            
            


    };
}