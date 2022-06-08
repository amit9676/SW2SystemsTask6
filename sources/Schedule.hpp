#pragma once
//#include "League.hpp"
#include "Game.hpp"
//#include "Game.hpp"
#include <vector>

namespace amit
{
    class Schedule{
        private:
            vector<Game*> allGames2;

        public:
            Schedule(vector<Team*>);
            vector<Game*> getAllGames();

    };
}
