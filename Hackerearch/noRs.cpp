#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--) {
		string s;
		cin >> s;

		int k_count = 0;
		int last_kcount = 0;
		int r_count = 0;

		for ( int i = 0; i < s.size(); i++ ) {
			if (s[i] == 'R') {
				r_count++;
				if ( last_kcount < k_count )
					last_kcount = k_count;
				k_count--;

				if ( k_count <= 0 ) 
					k_count = 0;
			}
			else {
				k_count++;
			}
		}

		if ( r_count < s.size() )
			cout << r_count + (last_kcount > k_count ? last_kcount : k_count) << '\n';
		else 
			cout << r_count - 1 << '\n';
	}
	
	return 0;
}
