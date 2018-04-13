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
	string decision2;
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

	return attributes[index];

}


void createNewRoot(Node &root, vector<vector<string>> trainData, int depth) {

	
	/*for(int i = 0; i < trainData.size(); i++) {
		for(int j = 0; j < trainData[i].size(); j++)
			cout << trainData[i][j] << " ";
		cout << endl;
	}*/

	vector<int> attributes;
	getRandomArray(attributes, sizeOfForest, data[0].size() - 2);

	
	for(int i = 0; i < attributes.size(); i++)
		cout << attributes[i] << endl;

	cout << "--------------" << endl;
	

	string value;
	int index = getIndexOfHighest(attributes, trainData);



	cout << index << endl;


	map<string, int> count; 
	set<string> myset;

	for(int i = 0; i < trainData.size(); i++) {
		count[trainData[i][index]]++;		
		myset.insert(trainData[i][index]);
	}


	set<string>::iterator it=myset.begin();

	string str = *it;
	for ( ; it!=myset.end(); ++it) {
    	if(count[*it] > count[str]) {
    		str = *it;
    	}


    	//cout << ' ' << *it << " " << count[*it] << endl;
    }

	  //cout <<"--------------" <<'\n';

	  //cout << str << endl;

	//cout << trainData.size() << endl;


	//cout << trainData[0].size() << endl;

	root.index = index;
	root.isLeaf = false;
	root.condition = str;


	depth++;
	cout << "in depth " << depth << " start >> " << endl;

	if(depth > 2) {
		root.isLeaf = true;


		set<string> myset1;
		int in  = trainData[0].size() - 1;

		cout << "---------- " << in << endl;

		for(int i = 0; i < trainData.size(); i++) {
			count[trainData[i][in]]++;		
			myset1.insert(trainData[i][in]);
		}


		set<string>::iterator it1=myset1.begin();

		string str1 = *it1;
		
		cout << str1 << endl;
		
		for ( ; it1!=myset1.end(); ++it1) {
	    	if(count[*it1] > count[str1]) {
	    		str1 = *it1;
	    	}


	    	cout << ' ' << *it1 << " " << count[*it1] << endl;
	    }

	    cout << "----------------------------    " << str1 << endl;

	    root.decision = str1;


	    it1=myset1.begin();
	    str1 = *it1;

	    if(str1 == root.decision) {
	    	++it1;
			str1 = *it1;	    	
	    }

	    for ( ; it1!=myset1.end(); ++it1) {
	    	
	    	if(*it1 != root.decision) {

	    		if(count[*it1] > count[str1]) {
		    		str1 = *it1;
		    	}


		    	cout << ' ' << *it1 << " " << count[*it1] << endl;

		    }

	    	
	    }

	    //cout << str1 << endl;

	    root.decision2 = str1;


	    cout << "....... >> " << root.decision << endl;
	    cout << "....... >> " << root.decision2 << endl;

	    //cout << "hello" << endl;
		return;
	}


	Node child1, child2;

	createNewRoot(child1, trainData, depth);
	createNewRoot(child2, trainData, depth);

	root.child.push_back(child1);
	root.child.push_back(child2);

	cout << "cout of depth >> " << depth << " byr bye" << endl;






	










	 



	












	//recurse
}










int main(void) {
	freopen("data.txt", "r", stdin);
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


		
		vector<Node> forest;


		for(int i = 0; i < sizeOfForest; i++) {
			cout << "start of constructing tree number: " << i + 1 << endl;
			Node root;
			createNewRoot(root, trainData, 0);
			forest.push_back(root);
			cout << "end of constructing tree number: " << i + 1 << endl;
			cout << "---------------------------------------" << endl;
		}





		



		


		/*
		for(int i = 0; i < 10; i++) {

			Node tempNode = root;

		string result;

		while(1){


			if(tempNode.isLeaf) {
				if(tempNode.condition == testData[i][tempNode.index]) result = tempNode.decision;
				else result = tempNode.decision2;
				break;

			} else {

				if(tempNode.condition == testData[i][tempNode.index]) tempNode = tempNode.child[0];
				else tempNode = tempNode.child[1];
			}

		}




		cout << result << "     >> 0 " << testData[i][testData[0].size() - 1] << endl;

	}


	*/
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