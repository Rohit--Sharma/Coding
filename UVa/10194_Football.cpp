#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <map>
#include <string.h>
#include <vector>

using namespace std;

typedef struct team 
{
	char name[32];
	short points;
	short wins;
	short losses;
	short ties;
	short scored;
	short against;
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
	
	teamData[team1].scored += goals1;
	teamData[team1].against += goals2;
	
	teamData[team2].scored += goals2;
	teamData[team2].against += goals1;
	
	return;
}

bool comp(const team a, const team b)
{
	if (a.points > b.points) {
		return true;
	} else if (a.points < b.points) {
		return false;
	}
	if (a.wins > b.wins) {
		return true;
	} else if (a.wins < b.wins) {
		return false;
	} 
	if ((a.scored - a.against) > (b.scored - b.against)) {
		return true;
	}else if ((a.scored - a.against) < (b.scored - b.against)) {
		return false;
	}
	
	if (a.scored > b.scored) {
		return true;
	}else if (a.scored < b.scored) {
		return false;
	}
	
	if (a.gamesPlayed < b.gamesPlayed) {
		return true;
	}else if (a.gamesPlayed > b.gamesPlayed) {
		return false;
	}
	
	string str1 = a.name, str2 = b.name;
	transform(str1.begin(), str1.end(),str1.begin(), ::toupper);
	transform(str2.begin(), str2.end(),str2.begin(), ::toupper);
	
	return str1 < str2;
}

int main (int argc, char const* argv[])
{
	short n, t, g; cin >> n;		// n: # tournments, t: # teams, g: # games
	cin.ignore();
	string tournName, gameInfo, teamName;	
	map<string, team> teamData;
	bool printNewLine = false;
	
	while (n--) {
	
		if (printNewLine) {
			cout << endl;
		}		
		printNewLine = true;
	
		getline(cin, tournName);
		cout << tournName << endl;
		
		cin >> t; cin.get();
		
		for (unsigned int i = 0; i < t; i += 1) {
			getline(cin, teamName);
			
			team *temp = (team *)malloc(sizeof(team));
			
			bzero(temp, sizeof(team));
			
			strcpy(temp->name, teamName.data());
			teamData[teamName] = *temp;
		}
		
		cin >> g; cin.get();
		
		while (g--) {
			getline(cin, gameInfo);
			processGame(gameInfo, teamData);
		}
		
		vector<team> array;
		
		for (map<string,team>::iterator it = teamData.begin(); it != teamData.end(); it++) 
			array.push_back((*it).second);
			
		sort(array.begin(), array.end(), comp);
		
		for(int i=0; i<array.size(); ++i)
			cout << i+1 << ") " << array[i].name << " " << array[i].points << "p, " << array[i].gamesPlayed << "g (" << array[i].wins << "-" << array[i].ties << "-" << array[i].losses << "), " << array[i].scored - array[i].against << "gd (" << array[i].scored << "-" << array[i].against << ")" << endl;

		teamData.clear();
	}
	
	return 0;
}
