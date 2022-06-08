#include "Game.hpp"
#include <random>

random_device rd{};
mt19937 gen{rd()};
normal_distribution<double> homeP{77.5,4};
normal_distribution<double> awayP{75,4};


namespace amit{
    Game::Game(Team* home, Team* away) : teamHome(home),teamAway(away){
        this->scoreHome = 0;
        this-> socreAway = 0;

        this->socreAway=int(awayP(gen)+(10*this->teamHome->getTalent()));
        this->scoreHome=int(homeP(gen)+(10*this->teamHome->getTalent()));

        this->teamHome->addGoodScore(this->scoreHome);
        this->teamHome->addBadScores(this->socreAway);
        this->teamAway->addGoodScore(this->socreAway);
        this->teamAway->addBadScores(this->scoreHome);
        

        if(this->scoreHome >= this->socreAway){
            this->winCheck(this->getTeamHome());
            this->loseCheck(this->getTeamAway());
            talentCheck(this->getTeamHome(),this->getTeamAway());
            this->getTeamHome()->advanceHomeWins();
            

        }
        else{
            this->winCheck(this->getTeamAway());
            this->loseCheck(this->getTeamHome());
            talentCheck(this->getTeamAway(),this->getTeamHome());
            this->getTeamAway()->advanceWinsAbroad();
        }
    }

    //what to do for the talent statistics
    void Game::talentCheck(Team* w, Team* l){
        if(w->getTalent() < l->getTalent()){
                w->advanceUnderDogWinner();
                l->advanceBetterDogLoser();
        }
    }

    //what to do for the winner team
    void Game::winCheck(Team* t){
        t->addWin();
        t->resetCurrentLosesStreak();
        t->advanceCurrentWinStreak();
        if(t->getCurrentWinStreak() > t->getTopWinStreak()){
            t->advanceTopWinStreak();
        }
        
    }

    //what to do for the loser team
    void Game::loseCheck(Team* t){
        t->addLose();
        t->resetCurrentWinStreak();
        t->advanceCurrentLosesStreak();
        if(t->getCurrentLosesStreak() > t->getTopLoseStreak()){
            t->advanceTopLoseStreak();
        }
    }

    //getter and setters
    Team* Game::getTeamHome(){
        return this->teamHome;
    }

    Team* Game::getTeamAway(){
        return this->teamAway;
    }

    int Game::getScoreHome(){
        return this->scoreHome;
    }

    int Game::getScoreAway(){
        return this->socreAway;
    }
}