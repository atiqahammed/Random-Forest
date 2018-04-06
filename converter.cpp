#include <iostream>

using namespace std;


int main(void) {

	string s;
	while(cin >> s) {
		for(int i = 0; i < s.length(); i++){
			if(s[i] == ',') cout << " ";
			else cout << s[i];
		}
		cout << endl;
	}

	return 0;
}