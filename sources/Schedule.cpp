#include "Schedule.hpp"



namespace amit{
 

    Schedule::Schedule(vector<Team*> l)
    {
        const int twenty = 20;
        if(l.size() != twenty){
            throw runtime_error("teams size must be 20");
        }


        //add allpossible game combination (x-1)*2 games
        for(size_t i = 0; i < 20; i++){
            for(size_t j = 0; j < 20; j++){
                if(i != j){
                    this->allGames2.insert(this->allGames2.end(), new Game{l[i],l[j]});
                }
                    
            }
        }
        
    }

    vector<Game*> Schedule::getAllGames(){
        return this->allGames2;
    }

 
}