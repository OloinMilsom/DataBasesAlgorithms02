#include <vector>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

template<typename T>
void printVector(vector<T> vec);

int main() {
	vector<int> emptyVecInt;
	vector<int> randVecInt;
	vector<string> emptyVecString;
	vector<int> specificVecInt;
	vector<int> copyVecInt;

	printVector(emptyVecInt);

	srand(time(0));
	for (int i = 0; i < 3; i++)
	{
		emptyVecString.push_back("");
		randVecInt.push_back(rand() % 100);
	}
	printVector(randVecInt);
	printVector(emptyVecString);

	specificVecInt.push_back(23);
	specificVecInt.push_back(42);
	specificVecInt.push_back(76);
	printVector(specificVecInt);

	copyVecInt = specificVecInt;
	printVector(copyVecInt);

	vector<int>::iterator first = copyVecInt.begin();
	vector<int>::iterator last = copyVecInt.end();
	*first = 76;
	*(last - 1) = 23;
	printVector(copyVecInt);

	copyVecInt.resize(2);
	printVector(copyVecInt);

	copyVecInt.resize(3);
	printVector(copyVecInt);

	copyVecInt.resize(3);
	printVector(copyVecInt);

	copyVecInt.push_back(12);
	printVector(copyVecInt);

	copyVecInt.pop_back();
	printVector(copyVecInt);

	copyVecInt.clear();
	printVector(copyVecInt);

	cout << copyVecInt.max_size() << endl;

	copyVecInt.swap(specificVecInt);
	printVector(copyVecInt);

	system("PAUSE");
}

template<typename T>
void printVector(vector<T> vec){
	cout << "{ ";
	for (vector<T>::iterator curr = vec.begin(); curr < vec.end(); curr++)
	{
		cout << *curr;
		if (curr < vec.end() - 1){
			cout << ", ";
		}
	}
	cout << "}" << endl;
}