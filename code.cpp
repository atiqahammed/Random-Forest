#include <bits/stdc++.h>


using namespace std;


#define max_depth 5

struct Node {
	int index;
	bool isLeaf;
	vector<Node> child;
	string condition;
	//vector<string> condition;
	string decision;
};


vector<vector<string>> data;
double accouracy = 0.0;
int sizeOfForest;
map<int, double> entropyOfIndex;


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

void getRandomArray(vector<int> &randomlyChoosedArray, int sizeOfTestData, int range) {
	while(randomlyChoosedArray.size() != sizeOfTestData) {
		srand(clock());
		int randomNumber = rand() % range + 1;
		randomlyChoosedArray.push_back(randomNumber);	
	}
}



void selectTrainAndTestData(vector<vector<string>> &trainData, vector<vector<string>> &testData, vector<int> randomlyChoosedArray) {
	for(int i = 0; i < data.size(); i++) {
		if (find(randomlyChoosedArray.begin(), randomlyChoosedArray.end(),i)!=randomlyChoosedArray.end()) {
			testData.push_back(data[i]);
		} else {
			trainData.push_back(data[i]);
		}
	}
}

double getEntropy(int index, vector<vector<string>> trainData) {

	if(entropyOfIndex[index] >= 0) {
		return entropyOfIndex[index];
	}

	double entropy = 0.0;
	map<string, int> count;
	vector<string> allValue; 

	for(int i = 0; i < trainData.size(); i++) {
		count[trainData[i][index]]++;		
		if(!(find(allValue.begin(), allValue.end(), trainData[i][index])!=allValue.end()))
			allValue.push_back(trainData[i][index]);
	}

	//cout << trainData.size() << endl;

	//double entropy = 0.0;
	for(int i = 0; i <  allValue.size(); i++) {
		
		double probability = (double)count[allValue[i]] / trainData.size();
		//cout << probability << endl;
		entropy += probability * log2(probability);
	}

	entropy *= -1;
	entropyOfIndex[index] = entropy;

	return entropy;
}




int getIndexOfHighest(vector<int> attributes, vector<vector<string>> trainData) {

	int index = 0;
	double min_entropy = 1.0;
	for(int i = 0; i < attributes.size(); i++) {
		//cout << attributes[i]
		double entropy = getEntropy(attributes[i], trainData);
		if(entropy < min_entropy) {
			min_entropy = entropy;
			index = i;
		}
		//cout << entropy << endl;
		//cout << attributes[i] << endl;
	}

	//cout << index << endl;

	return index;

}


void createNewRoot(Node &root, vector<vector<string>> trainData, int depth) {

	
	/*for(int i = 0; i < trainData.size(); i++) {
		for(int j = 0; j < trainData[i].size(); j++)
			cout << trainData[i][j] << " ";
		cout << endl;
	}*/

	vector<int> attributes;
	getRandomArray(attributes, sizeOfForest, data[0].size() - 2);

	/*
	for(int i = 0; i < attributes.size(); i++)
		cout << attributes[i] << endl;

	*/

	string value;
	int index = getIndexOfHighest(attributes, trainData);



	map<string, int> count;
	vector<string> allValue; 

	for(int i = 0; i < trainData.size(); i++) {
		count[trainData[i][index]]++;		
		if(!(find(allValue.begin(), allValue.end(), trainData[i][index])!=allValue.end()))
			allValue.push_back(trainData[i][index]);
	}


	int valueIndex = 0;

	for(int i = 1; i <  allValue.size(); i++) {
		
		if(count[allValue[i]] > count[allValue[valueIndex]]) {
			valueIndex = i;
		}
		//cout << allValue[i] << " " << count[allValue[i]] << endl;

		//double probability = (double)count[allValue[i]] / trainData.size();
		//cout << probability << endl;
		//entropy += probability * log2(probability);
	}




	//cout << index << endl;










	root.index = index;
	root.condition = allValue[valueIndex];



	depth++;
	if(depth > max_depth)
		return;












	//recurse
}










int main(void) {

	inputData();
	sizeOfForest = sqrt(data[0].size());

	//for(int i = 0; i <  10; i++) {
		vector<vector<string>> trainData;
		vector<vector<string>> testData;

		vector<int> randomlyChoosedArray;
		//int sizeOfTestData = data.size() / 10;
		//cout << sizeOfTestData << endl;

		getRandomArray(randomlyChoosedArray, data.size() / 10, data.size() - 2);
		selectTrainAndTestData(trainData, testData, randomlyChoosedArray);
		for(int j = 0; j < data[0].size(); j++)
			entropyOfIndex[j] = -1.0;


		Node root;

		createNewRoot(root, trainData, 1);
		//cout << data[0].size() << endl;

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