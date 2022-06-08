#include "Team.hpp"
#include <random>


namespace amit{
    Team::Team(string nam, double talent) :name(nam), talent(talent){
        if(talent < 0 || talent > 1){
            throw runtime_error("talent must be between 0 and 1");
        }
        strCheck(name);
        this->initilize();
    }

    Team::Team(string nam) :name(nam){
        strCheck(name);
        this->talent = ((double) rand() / (RAND_MAX));
        this->initilize();
    }

    //check for valid string
    void Team::strCheck(string str){
        bool noordinaryLetterYet = false;
        if(str.empty()){
            throw std::invalid_argument("no valid name");
        }
        for (size_t i = 0; i < str.length(); i++)
        {
            if(str.at(i)>= 33 && str.at(i) <=126){
                noordinaryLetterYet = true;
            }
            if (str.at(i) < 32 || !isprint(str.at(i)))
            {
                throw std::invalid_argument("non valid name");
            }
        }
        if(!noordinaryLetterYet){
            throw runtime_error("string is only spaces/non printable characters");
        }
    }

    void Team::initilize(){
        this->goodScore = 0;
        this-> badScore = 0;
        this->wins = 0;
        this->loses = 0;
        this->underDogWinner = 0;
        this->betterDogLoser = 0;

        this->topWinStreak = 0;
        this->topLoseStreak = 0; 
    }

    //getter and setters
    string Team::getName(){
        return this->name;
    }

    double Team::getTalent(){
        return this->talent;
    }

    void Team::setTalent(double value){
        this->talent = value;
    }

    int Team::getWins(){
        return this->wins;
    }

    int Team::getLoses(){
        return this->loses;
    }

    int Team::getGoodScore(){
        return this->goodScore;
    }

    int Team::getBadScore(){
        return this->badScore;
    }

    void Team:: addWin(){
        this->wins++;
    }

    void Team:: addLose(){
        this->loses++;
    }

    void Team:: addGoodScore(int val){
        this->goodScore+=val;
    }

    void Team:: addBadScores(int val){
        this->badScore+= val;
    }

    int Team::getTopWinStreak(){
        return this->topWinStreak;
    }
    int Team::getTopLoseStreak(){return this->topLoseStreak;}

    int Team::getCurrentWinStreak(){return this->currentWinStreak;}
    int Team::getCurrentLosesStreak(){return this->currentLoseStreak;}

    void Team::advanceTopWinStreak(){this->topWinStreak++;}
    void Team::advanceTopLoseStreak(){this->topLoseStreak++;}

    void Team::advanceCurrentWinStreak(){this->currentWinStreak++;}
    void Team::advanceCurrentLosesStreak(){this->currentLoseStreak++;}

    void Team::resetCurrentWinStreak(){this->currentWinStreak = 0;}
    void Team::resetCurrentLosesStreak(){this->currentLoseStreak = 0;}

    int Team::getUnderDogWinner(){return this->underDogWinner;}
    int Team::getBetterDogLoser(){return this->betterDogLoser;}

    void Team::advanceUnderDogWinner(){this->underDogWinner++;}
    void Team::advanceBetterDogLoser(){this->betterDogLoser++;}

    int Team::getWinsAbroad(){return this->winsAbroad;}
    int Team::getHomeWins(){return this->homeWins;}

    void Team::advanceWinsAbroad(){this->winsAbroad++;}
    void Team::advanceHomeWins(){this->homeWins++;}



    //used for sorting function (primary sort - win/lose ratio. secondary sort: good score - bad score)
    bool Team::operator<(Team t){
        if((double)this->getWins() / this->getLoses() == (double)t.getWins() / t.getLoses()){
            return (this->getGoodScore() - this->getBadScore()) > (t.getGoodScore() - t.getBadScore());
        }
        return (double)this->getWins() / this->getLoses() > (double)t.getWins() / t.getLoses();
    }
}