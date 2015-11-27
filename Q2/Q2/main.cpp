// I declare that the work I am submitting for assessing by the Institute examiner(s) is entirely my own
// work, save for any portion(s) thereof where the author or source has been duly referenced and
// attributed.
// Signed: Niall Milsom (C00179300)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printWords(vector<string> words); // prints the contents of the vector

struct sortByLength { // functor for sorting strings by length
	bool operator()(string const & first, string const & second) {
		if (first.size() == second.size())
		{
			return first < second;
		}
		return first.size() < second.size();
	}
};

struct ifLengthEquals { // functor for counting if length == specified length
	int length;
	bool operator()(string const & first) {
		return first.size() == length;
	}
};

struct ifAlsoIn { // functor for removing elements of one vector from another
	vector<string> vec;
	bool operator()(string const & first) {
		return std::find(vec.begin(), vec.end(), first) != vec.end();
	}
};

int main() {
	// read words from a file
	vector<string> words;
	copy(istream_iterator<string>(ifstream("adfl.txt")), istream_iterator<string>(), back_inserter(words));
	
	// sort and print
	sort(words.begin(), words.end());
	printWords(words);

	// remove duplicates and print
	words.erase(unique(words.begin(), words.end()), words.end());
	printWords(words);

	// sort by length and print
	sortByLength byLength;
	sort(words.begin(), words.end(), byLength);
	printWords(words);

	// counts the number of elements with length 4
	ifLengthEquals equalsFour = { 4 };
	cout << count_if(words.begin(), words.end(), equalsFour) << endl << endl;

	// remove certain words and print
	vector<string> removes;
	copy(istream_iterator<string>(ifstream("removes.txt")), istream_iterator<string>(), back_inserter(removes));
	ifAlsoIn inRemoves = { removes };
	words.erase(remove_if(words.begin(), words.end(), inRemoves), words.end());
	printWords(words);

	system("PAUSE");
}

void printWords(vector<string> words){
	for (int i = 0; i < words.size(); i++)
	{
		cout << words[i] << ", ";
	}
	cout << endl << endl;
}