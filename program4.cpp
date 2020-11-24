#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <array>
#include <cmath>
#include <vector>
#include <chrono>

using namespace std;
int set = 0;
double weights[5][1001];
double profits[5][1001];
double ratios[5][1001];
int items[5];
int knapcaps[5];
vector<int> knapsack;

int main(int argc, char *argv[]) {
	
	
	string tempstring = argv[3];
	int alg = stoi(tempstring);
	
	
	fstream file(argv[1], fstream::in);
	ofstream output;
	output.open(argv[2]);
	
	if(file.is_open()){  
		while(!file.eof() && !file.fail()) {
			int item = 0;
			int knapcap = 0;
			file >> item;
			file >> knapcap;
			items[set] = item;
			knapcaps[set] = knapcap;
			for(int i = 1; i<=item; i++) {
				double w, p, r;
				file >> w;
				file >> p;
				r = p/w;
				weights[set][i] = w;
				//cout << " weight "<< weights[set][i] << endl;
				profits[set][i] = p;
				//cout << " profit" << profits[set][i] << endl;
				ratios[set][i] = r;
				//cout << "ratios " << ratios[set][i] << endl;
			}
	      		set++;
		}
	file.close();
	}
	for(int u = 0; u<set; u++) {
		chrono::steady_clock sc;
	  	auto start = sc.now();
		//dynamic programming
		double cap = knapcaps[u]+1;
		double n = items[u]+1;
		double darray[cap][n];
		for(int c = 0; c<cap; c++) {
			darray[0][c] = 0;	
		}
		for(int i = 0; i<n; i++) {
			darray[i][0] = 0;	
			for(int c = 1; c<cap; c++) {
				if(weights[u][i] <= c && (darray[i-1][c-weights[u][i]] + profits[u][i] > darray[i-1][c])) {
					darray[i][c] = darray[i-1][c-weights[u][i] + profits[u][i];
				}
				else {
					darray[i][c] = darray[i-1][c];	
				}
			}
		}						   
			
	}
	
output.close();
}