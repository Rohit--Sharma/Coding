#include <vector>


#define REP(i, a, b) for(int i = int(a); i <= int(b); i++)

vector<int> pset(1000);

void initSet(int _size)
{
	pset.resize(_size);
	REP (i, 0, _size - 1)
		pset[i] = i;
}

int findSet(int i)
{
	return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}

void unionSet(int i, int j)
{
	pset[findSet(i)] = findSet(j);
}

bool isSameSet(int i, int j)
{
	return findSet(i) == findSet(j);
}

// TODO
int numberOfSets()
{
	
	return 0;
}

// TODO
int sizeOfSet(int i)
{
	
	return 0;
}
