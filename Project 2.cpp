#include<iostream>
#include<chrono>
#include "BST.h"
#include "MaxHeap.h"
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
void runFunc(string testType,int testNum);
int main() {
	/*
	//Get random values
	vector<int> hundredRand;
	vector<int> thousandRand;
	vector<int> tenThousandRand;

	for (int i = 0; i < 500; i++) {
		hundredRand.push_back(i);
	}

	for (int i = 0; i < 5000; i++) {
		thousandRand.push_back(i);
	}

	for (int i = 0; i < 50000; i++) {
		tenThousandRand.push_back(i);
	}

	random_shuffle(hundredRand.begin(), hundredRand.end());
	random_shuffle(thousandRand.begin(), thousandRand.end());
	random_shuffle(tenThousandRand.begin(), tenThousandRand.end());


	//Create txt file 1;
	ofstream file;
	file.open("Test1Asc.txt");
	for (int i = 0; i < 500; i++) {
		file << i << endl;
	}
	file.close();

	//Create txt file 2;
	file.open("Test4Desc.txt");
	for (int i = 499; i >= 0; i--) {
		file << i << endl;
	}
	file.close();


	//Create txt file 3;
	file.open("Test7Rand.txt");
	for (int i = 0; i < 500; i++) {
		file << hundredRand.at(i) << endl;
	}
	file.close();

	//Create txt file 4;
	file;
	file.open("Test2Asc.txt");
	for (int i = 0; i < 5000; i++) {
		file << i << endl;
	}
	file.close();

	//Create txt file 5;
	file.open("Test5Desc.txt");
	for (int i = 4999; i >= 0; i--) {
		file << i << endl;
	}
	file.close();


	//Create txt file 6;
	file.open("Test8Rand.txt");
	for (int i = 0; i < 5000; i++) {
		file << thousandRand.at(i) << endl;
	}
	file.close();

	//Create txt file 7;

	file;
	file.open("Test3Asc.txt");
	for (int i = 0; i < 50000; i++) {
		file << i << endl;
	}
	file.close();

	//Create txt file 8;
	file.open("Test6Desc.txt");
	for (int i = 49999; i >= 0 ; i--) {
		file << i << endl;
	}
	file.close();


	//Create txt file 9;
	file.open("Test9Rand.txt");
	for (int i = 0; i < 50000; i++) {
		file << tenThousandRand.at(i) << endl;
	}
	file.close();

	*/


	string testType;
	int testNum;
	while (1) {
		cout << "Type BST or MH: ";
		cin >> testType;

		if (testType == "BST" || testType == "MH") {
			cout << endl << "Type a number from 1-9" << endl;
			cout << "1. 500 ascending \t 2. 5000 ascending \t 3. 50000 ascending" << endl;
			cout << "4. 500 descending \t 5. 5000 descending \t 6. 50000 descending" << endl;
			cout << "7. 500 random \t\t 8. 5000 random \t 9. 50000 random" << endl;
			cout << endl;
			cin >> testNum;
			cout << endl;
			runFunc(testType, testNum);
			cout << endl << "*********************************************END********************************************************" << endl;

		}
		else {
			cout << "Invalid data type" << endl;
		}
	}

}

void runFunc(string testType, int testNum) {

	vector<int> test1;

	//Test1
	//ifstream files("Test1Asc.txt");
	//Test2
	//ifstream files1("Test2Asc.txt");
	//Test3
	ifstream files2("Test3Asc.txt");
	//Test4
	//ifstream files3("Test4Desc.txt");
	//Test5
	//ifstream files4("Test5Desc.txt");
	//Test6
	ifstream files5("Test6Desc.txt");
	//Test7
	//ifstream files6("Test7Rand.txt");
	//Test8
	//ifstream files7("Test8Rand.txt");
	//Test9
	ifstream files8("Test9Rand.txt");
	string line;
	switch (testNum) {
	/*case 1:
		while (getline(files, line)) {
			test1.push_back(stoi(line));
		}
		break;
	case 2:
		while (getline(files1, line)) {
			test1.push_back(stoi(line));
		}
		break;*/
	case 3:
		while (getline(files2, line)) {
			test1.push_back(stoi(line));
		}
		break;
	/*case 4:
		while (getline(files3, line)) {
			test1.push_back(stoi(line));
		}
		break;
	case 5:
		while (getline(files4, line)) {
			test1.push_back(stoi(line));
		}
		break;*/
	case 6:
		while (getline(files5, line)) {
			test1.push_back(stoi(line));
		}
		break;
	/*case 7:
		while (getline(files6, line)) {
			test1.push_back(stoi(line));
		}
		break;
	case 8:
		while (getline(files7, line)) {
			test1.push_back(stoi(line));
		}
		break;*/
	case 9:
		while (getline(files8, line)) {
			test1.push_back(stoi(line));
		}
		break;
	}

	cout << "Testing Test No " << testNum << endl;


	if (testType == "BST") {



		auto start = chrono::steady_clock::now();

		BSTNode* a = new BSTNode(test1.at(0));
		BSTNode* root = a;
		for (int i = 1; i < test1.size(); i++) {
			a->Insertion(root, test1.at(i));
		}

		auto end = chrono::steady_clock::now();
		cout << "Ascending BST Insertion Elapsed: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds" << endl;

		//Search

		start = chrono::steady_clock::now();

		a->preOrderTraversal(root);
		cout << endl;

		end = chrono::steady_clock::now();
		cout << "Ascending BST Preorder Traversal Elapsed: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds" << endl;

		//Deletion

		start = chrono::steady_clock::now();

		//function
		for (int i = 0; i < test1.size(); i++) {
			root = a->deletion(root, test1.at(i));
		}

		end = chrono::steady_clock::now();
		cout << "Ascending BST Deletion Elapsed: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds" << endl;

	}
	else if (testType == "MH") {
		auto start = chrono::steady_clock::now();
		vector<int> ans;
		for (int i = 0; i < test1.size(); i++) {
			insertion(ans, test1.at(i));
		}

		auto end= chrono::steady_clock::now();
		cout << "Ascending MH Insertion Elapsed: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds" << endl;
		cout << "Size: " << ans.size() << endl;
		//Search

		start = chrono::steady_clock::now();

		levelOrderTraversal(ans);
		cout << endl;

		end = chrono::steady_clock::now();
		cout << "Ascending MH Preorder Traversal Elapsed: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds" << endl;

		//Deletion

		start = chrono::steady_clock::now();

		//function
		for (int i = 0; i < test1.size(); i++) {
			deletion(ans);
		}

		end = chrono::steady_clock::now();
		cout << "Ascending MH Deletion Elapsed: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds" << endl;
	}

}