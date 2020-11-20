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

int max(double a, double b) { 
	return (a > b) ? a : b; 
} 

int napsack(int weight, int n, int u) {
	if(n==0||weight==0) {
		return 0;	
	}
	if(weights[u][n] > weight) {
		return napsack(weight, n-1, u);	
	}
	else {
		return max(profits[u][n] + napsack(weight - weights[u][n], n - 1, u), napsack(weight, n - 1, u)); 
	}
}

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
		//greedy algorithm 1
			
	}
	
output.close();
}
