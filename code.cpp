#include <bits/stdc++.h>


using namespace std;


#define max_depth 5

struct Node {
	int index;
	bool isLeaf;
	vector<Node> child;
	string decision;
};


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

void getRandomArray(vector<int> &randomlyChoosedArray, int sizeOfTestData) {
	while(randomlyChoosedArray.size() != sizeOfTestData) {
		srand(clock());
		int randomNumber = rand() % sizeOfTestData + 1;
		randomlyChoosedArray.push_back(randomNumber);	
	}
}



void selectTrainAndTestData(vector<vector<string>> &trainData, vector<vector<string>> &testData, vector<int> randomlyChoosedArray) {
	for(int i = 0; i < data.size(); i++) {
		if (find(randomlyChoosedArray.begin(), randomlyChoosedArray.end(),i)!=randomlyChoosedArray.end()) {
			//cout << i << endl;
			testData.push_back(data[i]);
		} else {
			trainData.push_back(data[i]);
		}
	}
}


int main(void) {

	inputData();
	int sizeOfForest = sqrt(data[0].size());
	cout << sizeOfForest << endl;

	//for(int i = 0; i <  10; i++) {
		vector<vector<string>> trainData;
		vector<vector<string>> testData;

		vector<int> randomlyChoosedArray;
		//int sizeOfTestData = data.size() / 10;
		//cout << sizeOfTestData << endl;

		getRandomArray(randomlyChoosedArray, data.size() / 10);
		selectTrainAndTestData(trainData, testData, randomlyChoosedArray);




		/*
		for(int i = 0; i < trainData.size(); i++) {
			for(int j = 0; j < trainData[i].size(); j++) 
				cout << trainData[i][j] << " ";
			cout << endl;
		}*/




		/*for(int i = 0; i < randomlyChoosedArray.size(); i++) {
			cout << randomlyChoosedArray[i] << endl;
		} */

		//cout << testData.size() << endl;
		//cout << trainData.size() << endl;

		//cout << data.size() << endl;
		//cout << randomlyChoosedArray.size() << endl;







	//}




}