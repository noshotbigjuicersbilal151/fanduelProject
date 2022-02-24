#include <iostream> 
#include "Team.hpp"
#include <vector> 
#include <string>
class Team{ 
	private:
		int salaryCap; 
		vector<Player*> teamPlayers; 
		std::string teamName; 
	public: 
		Team(std::string name){
		std::string teamName; 
	}
};

bool team_check(teamPlayers){
	int def_count = 0;
	int center_count = 0; 
	int pg_count = 0; 
	int pf_count = 0; 
	int sg_count = 0; 
	int sf_count = 0; 
	for( auto& it : teamPlayers){
		if(player*position == def){
			if(def_count < 2){
				def_count++;
			}
			else{ 
				return false;
			}			 
		}
		else if(player*position == point_guard){
			if(pg_count < 2 ){
				pg_count++; 
			} 
			else{ 
				return false
			} 
		}	
			
		else if(player*position == power_forward){
			if(pf_count < 2){
			 	pf_count++;
			}
			else{ 
				return false; 
			}
		}
		else if(player*position == center){ 
			if(center_count == 0){
				center_count++;
			}	 
			else{ 
				return false; 
			}
		}
		else if(player*position == shooting_guard){ 
			if(sg_count < 2){ 
				sg_count++;
			}
			else{	
				return false; 
			} 
		} 
		else if(player*position == small_foward){
			if(sf_count < 2){
				sf_count++; 
			}
			else{ 
				return false; 
			} 
		
		}
		return true; 
}

bool Teamcount(teamPlayers){
	int teamCount = 0;
	for(auto& it : TeamPlayers){
		totalcount++; 
	} 
	if(teamCount <= 9){
		return true; 
	}
	else{
		return false; 
	}
}

