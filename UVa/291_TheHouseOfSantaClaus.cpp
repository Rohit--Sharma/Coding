#include <iostream>

int adjMat[5][5] = {
	0, 1, 1, 0, 1,
	1, 0, 1, 0, 1,
	1, 1, 0, 1, 1,
	0, 0, 1, 0, 1,
	1, 1, 1, 1, 0
};

//boolean solve(Node n) {
//    if n is a leaf node {
//        if the leaf is a goal node {
//           print n
//           return true
//        }
//        else return false
//    } else {
//        for each child c of n {
//            if solve(c) succeeds {
//                print n
//                return true
//            }
//        }
//        return false
//    }
//}

bool isLeaf(int n)
{
	for	(int i = 0; i < 5; i++)
		if (adjMat[n][i])
			if (adjMat[n][i] == 1)
				return false;
	return true;
}

bool isGoal(void)
{
	for (unsigned int i = 0; i < 5; i += 1)
		for (unsigned int j = 0; j < 5; j += 1)
			if (adjMat[i][j])
				if (adjMat[i][j] == 1)
					return false;
	return true;
}

bool solve(int n)
{
	if (isLeaf(n)) {
		if (isGoal()) {
			cout << n;
			return true;
		} else
			return false;
	} else {
		
	}
}

int main (int argc, char const* argv[])
{
	
	return 0;
}
