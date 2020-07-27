#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>

using namespace std;

bool isComplete(const set<int> &s, int n) {
	if (s.size() == n) return true;
	else return false;
}

int main() {
	// for each test cases
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		// input number of friends and pairs
		int n_friends, n_pairs;
		cin >> n_friends >> n_pairs;
		// input pair list
		vector<tuple<int, int>> pair_list;
		for (int i = 0; i < n_pairs; i++) {
			// pair_list initialization
			int first, second;
			cin >> first >> second;
			tuple<int, int> pair = make_tuple(first, second);
			pair_list.push_back(pair);
		}

		// seq_gen initialization : 1 * # of needed pairs, 0 * # of non needed pairs 
		vector<int> seq_gen;
		for (int i = 0; i < n_pairs; i++) {
			if (i < (n_friends / 2))
				seq_gen.push_back(1);
			else
				seq_gen.push_back(0);
		}
		sort(seq_gen.begin(), seq_gen.end());

		set<int> s;
		int total = 0;
		do {
			s.clear();
			for (int i = 0; i < n_pairs;i++) {
				if (seq_gen[i] == 1) {
					s.insert(get<0>(pair_list[i]));
					s.insert(get<1>(pair_list[i]));
				}
			}
			if (isComplete(s, n_friends)) total++;
		} while (next_permutation(seq_gen.begin(), seq_gen.end()));

		cout << total << endl;
	}

}