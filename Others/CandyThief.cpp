//Problem        : Candy Thief
//Language       : C++
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

struct Prop {
    string name;
    int poss_thief;
    int def_not;
	vector<string> parents;
	
	Prop (string nm, int thief, int no_th): name(nm), poss_thief(thief), def_not(no_th) {}
};

int main() {
	int num_candies = 0, num_rec = 0;
	cin >> num_candies >> num_rec;
	string inp;
	getline(cin, inp);	// discard the end of first line

	vector<Prop *> people;

	while (num_rec--) {
		getline(cin, inp);
		stringstream str_stream_inp(inp);
		string tok;
		vector<string> tokens;
		while(getline(str_stream_inp, tok, ' ')) { 
			cout << "Tok: " << tok << endl;
			tokens.push_back(tok);
		}
		int curr_candies = stoi(tokens[0]);
		if (tokens.size() == 2) {
			if (curr_candies < num_candies) {
				people.push_back(new Prop(tokens[1], 1, 0));
				num_candies = curr_candies;
				continue;
			} else if (curr_candies == num_candies) {
				people.push_back(new Prop(tokens[1], 0, 1));
				continue;
			}
		} else {
			if (curr_candies < num_candies) {
				for (int i = 1; i < tokens.size(); i++) {
					// stolen

					// 
					if (people.size() == 0) {
						people.push_back(new Prop(tok, 1, 0));
					}

					num_candies = curr_candies;
				}
			}
		}
		
	} 
    return 0;
}
