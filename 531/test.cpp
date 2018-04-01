#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX(X, Y) (X > Y ? X : Y)
#define SIZE 10000
#define UP 1
#define UP_LEFT 2
#define LEFT 3
using namespace std;

int LCS[SIZE][SIZE];
int pre[SIZE][SIZE];

int main(){
	string buffer;
	vector<string> s1;
	vector<string> s2;
	vector<string> output;
	int a, b;
	while(1){
		s1.clear();
		s2.clear();
		output.clear();
		while(cin >> buffer && buffer[buffer.size() - 1] != '#'){
			s1.push_back(buffer);
		}
		while(cin >> buffer && buffer[buffer.size() - 1] != '#'){
			s2.push_back(buffer);
		}
		if(cin.eof()){
			exit(0);
		}
		cerr << s1.size() << ", " << s2.size() << endl;
		for(int i = 0; i < s1.size(); ++i){
			cerr << s1[i] << " ";
		}
		cerr << endl;
		for(int i = 0; i < s2.size(); ++i){
			cerr << s2[i] << " ";
		}
		cerr << endl;

		for(int i = 0; i <= s1.size(); ++i){
			for(int j = 0; j <= s2.size(); ++j){
				if(i == 0 || j == 0){
					LCS[i][j] = 0;
				}else if(s1[i - 1] == s2[j - 1]){
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
					pre[i][j] = UP_LEFT;
				}else if(s1[i - 1] != s2[j - 1]){
					LCS[i][j] = MAX(LCS[i - 1][j], LCS[i][j - 1]);
					pre[i][j] = LCS[i - 1][j] > LCS[i][j - 1] ? UP : LEFT;
				}
			}
		}
		cerr << "LCS = " << LCS[s1.size()][s2.size()] << endl;

		a = s1.size();
		b = s2.size();
		while(a > 0 && b > 0){
			cerr << a << ", " << b << endl;
			if(s1[a - 1] == s2[b - 1]){
				output.push_back(s1[a - 1]);
			}
			switch(pre[a][b]){
				case UP:
					--a;
					break;
				case LEFT:
					--b;
					break;
				case UP_LEFT:
					--a;
					--b;
					break;
			}
		}
		reverse(output.begin(), output.end());
		cout << output[0];
		for(int i = 1; i < output.size(); ++i){
			cout << " " << output[i];
		}
		cout << endl;
	}
}
