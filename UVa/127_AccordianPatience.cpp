#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<string> pile[52];

bool canPlace(char *card, short position)
{
	if (card[0] == pile[position].top().at(0) || card[1] == pile[position].top().at(1)) {
		return true;
	}
	return false;
}

void insert(char *card, short position)
{
	if ((position - 3 >= 0) && canPlace(card, position - 3)) {
		insert(card, position - 3);
	}
}

void anyMoreMoves(short position)
{
	int pos = position - 3, pos2 = position - 1;
	
	while (pos > -1 && pile[pos].empty()) {
		pos--;
	}
	
	if ((pos >= 0) && ((pile[position].top().at(0) == pile[pos].top().at(0)) || (pile[position].top().at(1) == pile[pos].top().at(1)))) {	
		string tmp = pile[position].top();
		pile[position].pop();
		pile[pos].push(tmp);
		anyMoreMoves(pos);
		if (!pile[position].empty()) {
			anyMoreMoves(position);
		}
		return;
	} 
	
	
	while (pos2 > -1 && pile[pos2].empty()) {
		pos2--;
	}
	
	if ((pos2 >= 0) && ((pile[position].top().at(0) == pile[pos2].top().at(0)) || (pile[position].top().at(1) == pile[pos2].top().at(1)))) {
		string tmp = pile[position].top();
		pile[position].pop();
		pile[pos2].push(tmp);
		anyMoreMoves(pos2);
		if (!pile[position].empty()) {
			anyMoreMoves(position);
		}
		return;
	} 
	
	else 
		return;
}

int main (int argc, char const* argv[])
{
	char hash; cin >> hash;
	char temp[3] = {0};
	short currentPile = 0;
	
	while (hash != '#') {
		
		temp[0] = hash;
		cin >> temp[1];
		
		pile[currentPile].push(temp);
		//insert(temp, currentPile);
		anyMoreMoves(currentPile);
		
		for (unsigned int i = 0; i < 51; i += 1) {
			currentPile++;
			cin >> temp;
			pile[currentPile].push(temp);
			//insert(temp, currentPile);
			anyMoreMoves(currentPile);
		}
		
		for (unsigned int i = 0; i < 52; i += 1) {
			cout << i << ": ";
			while (!pile[i].empty()) {
				cout << pile[i].top() << " ";
				pile[i].pop();
			}
			cout << "\n";
		}
		
		cin >> hash;
	}
	
	return 0;
}
