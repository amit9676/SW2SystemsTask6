#pragma once
#include <string>
#include <iostream>
using namespace std;

namespace amit{
    class Team
    {
        private:
            string name;
            double talent;
            int wins;
            int loses;

            int winsAbroad;
            int homeWins;

            int underDogWinner;
            int betterDogLoser;

            int goodScore;
            int badScore;

            int topWinStreak;
            int topLoseStreak;
            int currentWinStreak;
            int currentLoseStreak;

            void initilize();
            void strCheck(string);



        public:
            Team(string name, double talent);
            Team(string name);
            string getName();
            double getTalent();
            void setTalent(double value);

            int getWins();
            int getLoses();

            int getGoodScore();
            int getBadScore();

            void addWin();
            void addLose();

            void addGoodScore(int val);
            void addBadScores(int val);

            int getTopWinStreak();
            int getTopLoseStreak();

            int getCurrentWinStreak();
            int getCurrentLosesStreak();

            void advanceTopWinStreak();
            void advanceTopLoseStreak();

            void advanceCurrentWinStreak();
            void advanceCurrentLosesStreak();

            void resetCurrentWinStreak();
            void resetCurrentLosesStreak();

            int getUnderDogWinner();
            int getBetterDogLoser();

            void advanceUnderDogWinner();
            void advanceBetterDogLoser();

            int getWinsAbroad();
            int getHomeWins();

            void advanceWinsAbroad();
            void advanceHomeWins();

            bool operator < (Team);
            

    };
}


