#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> grid(81,0);
vector<int> block(9,0);
vector<int> row(9,0);
vector<int> column(9,0);

int check(int pos, int num);
void readSudoku();
void solve(int pos, long long &cnt);
void printSudoku();

int main(int argc, char const *argv[]) {
	if (argc > 1) {
		ifstream ifs;
		ifs.open(argv[1]);
		if (!ifs) {
			cerr << "error: failed to open file " << argv[1] << endl;
			exit(2);
		}
		cin.rdbuf(ifs.rdbuf());
		readSudoku();
		printSudoku();
	} else {
		readSudoku();
	}
	cout << "---------" << endl;
	long long count;
	solve(0, count);
	cout << "total sudoku count: " << count << endl;
	return 0;
}

int check(int pos, int num) {
	int f = 1 << num;
	if (block[pos/27*3+pos%9/3] & f) {
		return 1;
	}
	if (row[pos/9] & f) {
		return 2;
	}
	if (column[pos%9] & f) {
		return 3;
	}
	return 0;
}

void readSudoku() {
	for (int i = 0; i < 9; i++) {
		string s;
		getline(cin, s);
		if (s.length() < 9) {
			cerr << "error: invalid input\n\t"
					 << "not enough length of input at row " << i
					 << endl;
			exit(1);
		}
		for (int j = 0; j < 9; j++) {
			if ('1' <= s[j] && s[j] <= '9') {
				int inum = s[j] - '0';
				int f = 1 << inum;
				int state = check(i*9+j, inum);
				if (state > 0) {
					if (state == 1) {
						cerr << "error: invalid input\n\t"
								 << inum << "(at " << i << ":" << j << ")"
								 << " has already appeared in block[" << i/3*3+j/3 << "]"
								 << endl;
					} else if (state == 2) {
						cerr << "error: invalid input\n\t"
								 << inum << "(at " << i << ":" << j << ")"
								 << " has already appeared in row[" << i << "]"
								 << endl;
					} else if (state == 3) {
						cerr << "error: invalid input\n\t"
								 << inum << "(at " << i << ":" << j << ")"
								 << " has already appeared in column[" << j << "]"
								 << endl;
					}
					exit(1);
				}
				grid[i*9+j] = inum;
				block[i/3*3+j/3] |= f;
				row[i] |= f;
				column[j] |= f;
			}
		}
	}
}

void solve(int pos, long long &cnt) {
	if (pos == 81) {
		cnt++;
		printSudoku();
		return;
	}
	if (grid[pos] > 0) {
		solve(pos+1, cnt);
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (check(pos, i) == 0) {
			int f = 1 << i;
			grid[pos] = i;
			block[pos/27*3+pos%9/3] |= f;
			row[pos/9] |= f;
			column[pos%9] |= f;
			solve(pos+1, cnt);
			grid[pos] = 0;
			block[pos/27*3+pos%9/3] ^= f;
			row[pos/9] ^= f;
			column[pos%9] ^= f;
		}
	}
}

void printSudoku() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << grid[i*9+j];
		}
		cout << "\n";
	}
	cout << endl;
}
