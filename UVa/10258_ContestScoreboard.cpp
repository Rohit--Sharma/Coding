#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct {
	bool submitted;
	short penalty;
	short participantNo;
	bool problemsSolved[10];
	int noProblemsSolved;
} participant;

bool comp(participant a, participant b)
{
	if (a.noProblemsSolved > b.noProblemsSolved) {
		return true;
	} else if (b.noProblemsSolved > a.noProblemsSolved) {
		return false;
	}
	if (a.penalty < b.penalty) {
		return true;
	} else if (a.penalty > b.penalty) {
		return false;
	}
	return a.participantNo - b.participantNo; 
}

bool cmp (participant x, participant y)
{
    if ( x.noProblemsSolved > y.noProblemsSolved ) return true;
    if ( x.noProblemsSolved == y.noProblemsSolved && x.penalty < y.penalty ) return true;
    if ( x.noProblemsSolved == y.noProblemsSolved && x.penalty == y.penalty && x.participantNo < y.participantNo ) return true;
    return false;
}

int main (int argc, char const* argv[])
{
	int t; 
	cin >> t; cin.ignore(); cin.ignore();
	string input;
	bool printNewLine = false;
	
	while (t--) {
		if (printNewLine) {
			cout << endl;
		}
		printNewLine = true;
		
		participant participants[100];
		
		getline(cin, input);
		bzero(participants, sizeof(participant) * 100);
		
		while (input != "\0") {
			
			short contestant;
			short problem;
			short time;
			char status;
			
			char *tokenizer = strtok(const_cast<char*>(input.c_str()), " ");
			contestant = atoi(tokenizer);
			tokenizer = strtok(NULL, " ");
			problem = atoi(tokenizer);
			tokenizer = strtok(NULL, " ");
			time = atoi(tokenizer);
			tokenizer = strtok(NULL, " ");
			status = tokenizer[0];
			
			participants[contestant - 1].submitted = true;
			participants[contestant - 1].participantNo = contestant;
			
			switch (status) {
				case 'C': 
					if (!participants[contestant - 1].problemsSolved[problem - 1]) {
						participants[contestant - 1].problemsSolved[problem - 1] = true;
						participants[contestant - 1].penalty += time;
						participants[contestant - 1].noProblemsSolved++;
					}
					break;
				case 'I':
					if (!participants[contestant - 1].problemsSolved[problem - 1])
						participants[contestant - 1].penalty += 20;
					break;
				default:
					break;
			}
					
			getline(cin, input);
		}
		
		sort(participants, participants + 100, cmp);
		
		for (unsigned int i = 0; i < 100; i += 1) {
			if (participants[i].submitted) {
				cout << participants[i].participantNo << " " << participants[i].noProblemsSolved << " " << participants[i].penalty << endl;
			}
		}
	}
	
	return 0;
}







// http://uva.onlinejudge.org/external/102/10258.html
 
//========================================
// Name        : UVa_10258.cpp
// Author      : Shahab
// Version     : Accepted
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//========================================
 
// @BEGIN_OF_SOURCE_CODE

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <bitset>
#include <utility>
#include <set>
#define pi acos(-1.0)
#define N 1000000
using namespace std;
 
struct teams {
    int teamNumber;
    int solved [9 + 3]; 
    int penalty [9 + 3];
    bool submit;
} a [100 + 5];
 
void reset ()
{
    for ( int i = 0; i < 105; i++ ) {
        a [i].teamNumber = i;
        memset (a [i].solved, 0, sizeof (a [i].solved));
        memset (a [i].penalty, 0, sizeof (a [i].penalty));
        a [i].submit = false;
    }
}
 
void calculateAll ()
{
    for ( int i = 1; i < 105; i++ ) {
        for ( int j = 1; j <= 9; j++ ) {
            if ( a [i].solved [j] ) {
                a [i].solved [10]++;
                a [i].penalty [10] += a [i].penalty [j];
            }
        }
    }
}
 
bool cmp (teams x, teams y)
{
    if ( x.solved [10] > y.solved [10] ) return true;
    if ( x.solved [10] == y.solved [10] && x.penalty [10] < y.penalty [10] ) return true;
    if ( x.solved [10] == y.solved [10] && x.penalty [10] == y.penalty [10] && x.teamNumber < y.teamNumber ) return true;
    return false;
}
 
int main() {
    //freopen ("input.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);
    int penalty [9 + 3];    
    int testCase;
    scanf ("%d", &testCase);
    getchar ();
 
    bool blank = false;
    char input [1000];
 
    gets (input);
 
    while ( testCase-- ) {
        reset ();
 
        while ( gets (input) && strlen (input) ) {
            int c, p, t;
            char l;
 
            sscanf (input, "%d %d %d %c",&c, &p, &t, &l );
 
            a [c].submit = true;
 
            if ( l == 'R' || l == 'U' || l == 'E' ) continue;
 
            if ( l == 'C' ) {
                if ( !a [c].solved [p] ) {
                    a [c].solved [p] = 1;
                    a [c].penalty [p] += t;
                }
            }
            else {
                if ( !a [c].solved [p] )
                    a [c].penalty [p] += 20;
            }
        }
        
        calculateAll ();
 
        sort (a, a + 105, cmp);
 
        if ( blank )
            printf ("\n");
        blank = true;
 
        for ( int i = 0; i <= 105; i++ ) {
            if ( a [i].submit )
                printf ("%d %d %d\n", a [i].teamNumber, a [i].solved [10], a [i].penalty [10]);
        }
    }
 
    return 0;
}
