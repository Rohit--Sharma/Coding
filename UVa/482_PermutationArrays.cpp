#include <stdio.h>
//#include <vector>
//using namespace std;


//int main (int argc, char const* argv[])
//{
//	int t, temp; scanf("%d", &t);
//	vector<int> permutation;
//	vector<float> data;
//	vector<float> directAddrTable;
//	char c;
//	float tempf;
//	
//	while (t--) {
//		getchar();
//		do {
//			scanf("%d", &temp);
//			permutation.push_back(temp);
//		} while ((c = getchar()) != '\n');
//		do {
//			scanf("%f", &tempf);
//			data.push_back(tempf);
//		} while ((c = getchar()) != '\n');
//		directAddrTable.resize(data.size());
//		printf("Hello\n");
//		for (unsigned int i = 0; i < data.size(); i += 1) {
//			directAddrTable[permutation[i] - 1] = data[i];
//		}
//		
//		for (unsigned int i = 0; i < data.size(); i += 1) {
//			printf("%f\n", directAddrTable[i]);
//		}
//	}
//	
//	return 0;
//}

// Attempt-2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct array
{
	int data;
	string num;
} a[10000];

bool comp(array a, array b)
{
	if (a.data < b.data) {
		return true;
	}
	return false;
}

int main (int argc, char const* argv[])
{
	int t; scanf("%d", &t);
	char input[100000], *tokenizer;
	int index;
	getchar();
	
	bool flag = false;
	
	while (t--) {
		index = 0;
		
		getchar();
		gets(input);	
		
		tokenizer = strtok(input, " ");
		while (tokenizer) {
			a[index++].data = atoi(tokenizer);
			tokenizer = strtok(NULL, " ");
		}
		
		index = 0;
		gets(input);
		tokenizer = strtok(input, " ");
		while (tokenizer) {
			a[index++].num = tokenizer;
			tokenizer = strtok(NULL, " ");
		}
	
		sort(a, a + index, comp);
		
		if (flag) {
			putchar('\n');
		}
		
		flag = true;
		
		for (unsigned int i = 0; i < index; i += 1) {
			//printf("%s\n", a[i].num);
			cout << a[i].num << endl;
		}
	}
	return 0;
}
