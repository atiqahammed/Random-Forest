#include <bits/stdc++.h>


using namespace std;




vector<vector<string>> data;
double accouracy = 0.0;


void converStringToData(string s, vector<string> &instance) {
	
	stringstream stream(s);
	string value;
	while(stream >> value)
		instance.push_back(value);	
}

void inputData() {

	string s;
	while(getline(cin, s)) {
		vector<string> instance;
		converStringToData(s, instance);
		data.push_back(instance);
	}
}

getRandomArray(vector<int> &randomlyChoosedArray, int sizeOfTestData) {
	
}



int main(void) {

	inputData();

	//for(int i = 0; i <  10; i++) {
		vector<vector<string>> trainData;
		vector<vector<string>> testData;

		vector<int> randomlyChoosedArray;
		int sizeOfTestData = data.size() / 10;


		//cout << sizeOfTestData << endl;

		getRandomArray(randomlyChoosedArray, sizeOfTestData);









	//}




}