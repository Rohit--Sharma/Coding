#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <map>
#include <string.h>

using namespace std;

typedef struct team 
{
	char name[32];
	short points;
	short wins;
	short losses;
	short ties;
	short maxGoalDifference;
	short maxGoalsScored;
	short gamesPlayed;
} team;

void processGame(string gInfo, map<string, team> &teamData)
{
	string team1, team2;
	char *gInf = const_cast<char*>(gInfo.c_str());
	int goals1, goals2;
	
	char *tokenizer = strtok(gInf, "#");
	
	team1 = tokenizer;
	tokenizer = strtok(NULL, "@");
	goals1 = atoi(tokenizer);
	tokenizer = strtok(NULL, "#");
	goals2 = atoi(tokenizer);
	tokenizer = strtok(NULL, "\0");
	team2 = tokenizer;
	
	//(teamData.find(team1)->second).gamesPlayed++;
	
	teamData[team1].gamesPlayed++;
	teamData[team2].gamesPlayed++;
	
	if (goals1 > goals2) {
		teamData[team1].points += 3;
		teamData[team1].wins++;
		teamData[team2].losses++;
	} else if (goals1 == goals2) {
		teamData[team1].points++;
		teamData[team2].points++;
		teamData[team1].ties++;
		teamData[team2].ties++;
	} else {
		teamData[team2].points += 3;
		teamData[team2].wins++;
		teamData[team1].losses++;
	}
	
	if (goals1 > teamData[team1].maxGoalsScored) {
		teamData[team1].maxGoalsScored = goals1;
	}
	if (goals2 > teamData[team2].maxGoalsScored) {
		teamData[team2].maxGoalsScored = goals2;
	}
	
	if ((goals1 - goals2) > teamData[team1].maxGoalDifference) {
		teamData[team1].maxGoalDifference = goals1 - goals2;
	}
	if ((goals2 - goals1) > teamData[team2].maxGoalDifference) {
		teamData[team2].maxGoalDifference = goals2 - goals1;
	}
	
	//cout << teamData[team1].name << " " << teamData[team1].points << " " << teamData[team1].wins << " " << teamData[team1].losses << " " << teamData[team1].ties << " " << teamData[team1].maxGoalDifference << " " << teamData[team1].maxGoalsScored << " " << teamData[team1].gamesPlayed << endl;
	//cout << teamData[team2].name << " " << teamData[team2].points << " " << teamData[team2].wins << " " << teamData[team2].losses << " " << teamData[team2].ties << " " << teamData[team2].maxGoalDifference << " " << teamData[team2].maxGoalsScored << " " << teamData[team2].gamesPlayed << endl << endl;
	
	return;
}

int main (int argc, char const* argv[])
{
	short n, t, g; cin >> n;		// n: # tournments, t: # teams, g: # games
	string tournName, gameInfo;	
	map<string, team> teamData;
	
	while (n--) {
		cin.get();
	
		getline(cin, tournName);
		cin >> t; cin.get();
		team *array = (team *)malloc(sizeof(team) * t);
		
		for (unsigned int i = 0; i < t; i += 1) {
			cin.getline(array[i].name, 32);
			teamData[array[i].name] = array[i];
		}
		
		cin >> g; cin.get();
		
		while (g--) {
			cin >> gameInfo;
			processGame(gameInfo, teamData);
		}
		
		for (unsigned int i = 0; i < t; i += 1) {
			cout << array[i].name << " " << array[i].points << " " << array[i].wins << " " << array[i].losses << " " << array[i].ties << " " << array[i].maxGoalDifference << " " << array[i].maxGoalsScored << " " << array[i].gamesPlayed << endl;
		}
		
		free(array);
	}
	
	return 0;
}
