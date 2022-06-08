#include "Leauge.hpp"
#include<iterator>
#include <bits/stdc++.h>
namespace amit{

    League::League(){
        gameStarted = false;
        for(int i =0; i<20; i++){
            this->teams.insert(this->teams.end(), new Team{to_string(i), getRandomZeroToOne()});
        }
    }
    League::League(vector<Team*> v){
        const int twenty = 20;
        gameStarted = false;
        
        unsigned i = 0;
        if(v.size() > twenty){
            throw runtime_error("size cant be more than 20");
        }

        //first copy input
        for(i = 0; i < v.size(); i++){
            this->teams.insert(this->teams.end(), v[i]);
        }

        //then fill the blanks
        for(size_t k = i; k < 20; k++){
            this->teams.insert(this->teams.end(), new Team{to_string(k), getRandomZeroToOne()});
        }
    }

    double League::getRandomZeroToOne(){
        return ((double) rand() / (RAND_MAX));
    }

    void League::runGames(){
        gameStarted = true;
        Schedule t = Schedule{this->getTeams()};

        for(size_t i = 0; i < this->getTeams().size(); i++){
            v2.insert(v2.end(),*(this->getTeams()[i]));
        }
        
        //for some reason sorting doest works with pointers to objects
        sort(v2.begin(),v2.end());



    }



    //this functions print all league statitics
    void League::runStatistics(int bestTeams){
        if(!gameStarted){
            throw runtime_error("no games started yet so cant run staticics");
        }
        if(bestTeams > 20){
            throw runtime_error("number of best teams cant be higher than 20");
        }
        int longestWinStreak = 0;
        string winStreaker = v2[0].getName();

        int longestLosingStreak = 0;
        string loserStreker = v2[0].getName();

        int moreThanless = 0;

        int againstAllChances = 0;
        string againstAllChancesName = v2[0].getName();

        int despiteAllOdds = 0;
        string despiteAllOddsName = v2[0].getName();

        int winnerAbroad = 0;
        string winnerAbroadName = v2[0].getName();

        int homeWinner = 0;
        string homeWinnerName = v2[0].getName();
        cout << "the best " << bestTeams << " teams are (from best to worst): \n" << endl;
        for(size_t i = 0; i <  bestTeams; i++){
            cout << "team " << (i+1) << endl;
            cout << "team name: " << v2[i].getName() << endl;
            cout << "victories: " << v2[i].getWins() << endl;
            cout << "loses: " << v2[i].getLoses() << endl;
            cout << "good points: " << v2[i].getGoodScore() << endl;
            cout << "bad points: " << v2[i].getBadScore() << endl;

            cout << "win/lose ratio: " << (double)v2[i].getWins() / v2[i].getLoses() << endl;
            cout<< "points summary (good points - bad points): " << v2[i].getGoodScore() - v2[i].getBadScore() << endl;
            cout << "\n" << endl;
        }

        for(size_t i = 0; i < v2.size(); i++){
            

            if(v2[i].getTopWinStreak() > longestWinStreak){
                longestWinStreak = v2[i].getTopWinStreak();
                winStreaker = v2[i].getName();
            }
            if(v2[i].getTopLoseStreak() > longestLosingStreak){
                longestLosingStreak = v2[i].getTopLoseStreak();
                loserStreker = v2[i].getName();
            }
            if(v2[i].getGoodScore() > v2[i].getBadScore()){
                moreThanless++;
            }
            if(v2[i].getUnderDogWinner() > againstAllChances){
                againstAllChances = v2[i].getUnderDogWinner();
                againstAllChancesName = v2[i].getName();
            }

            if(v2[i].getBetterDogLoser() > despiteAllOdds){
                despiteAllOdds = v2[i].getBetterDogLoser();
                despiteAllOddsName = v2[i].getName();
            }

            if(v2[i].getWinsAbroad() > winnerAbroad){
                winnerAbroad = v2[i].getWinsAbroad();
                winnerAbroadName = v2[i].getName();
            }

            if(v2[i].getHomeWins() > homeWinner){
                homeWinner = v2[i].getHomeWins();
                homeWinnerName = v2[i].getName();
            }
        }

        cout << "longest win streak: " << longestWinStreak << " made by " << winStreaker << endl;
        cout << "longest losing streak: " << longestLosingStreak << " made by " << loserStreker << endl;
        cout << moreThanless << " teams scored more than recieved" << endl;

        cout << "extra statistic 1: winning against teams with higher talent/losing to teams with lower talent" << endl;
        cout << "team " << againstAllChancesName << " won " << 
        againstAllChances << " games against adveseries with greater talent, the highest from all teams." << endl;

        cout << "team " << despiteAllOddsName << " lost " << 
        despiteAllOdds << " games against adveseries with lower talent, the highest from all teams." << endl;

        cout << "extra statistic 2: win the most games at home/away" << endl;
        cout << "team " << winnerAbroadName << " won " << 
        winnerAbroad << " games away, the highest fom all teams." << endl;

        cout << "team " << homeWinnerName << " won " << 
        homeWinner << " games at home, the highest fom all teams." << endl;

    }

    vector<Team*> League::getTeams(){
        return this->teams;
    }
}