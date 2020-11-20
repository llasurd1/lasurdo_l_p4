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


int upper(int depth, double weight, double profit, int capacity, int n, int sett) {
	//n is items[u]
	double bound = profit;
	double x[n];
	for(int i = depth; i<=n; i++) {
		x[i] = 0;
	}
	while((weight<capacity) && (depth<=n)) {
		if((weight + weights[sett][depth]) <=capacity) {
			x[depth] = 1;
			weight+=weights[sett][depth];
			bound+=profits[sett][depth];
		}
		else{
			x[depth] = (capacity - weight)/weights[sett][depth];
			weight = capacity;
			bound = bound + (profits[sett][depth]*x[depth]);
		}
		depth = depth + 1;
	}
	return bound;
}

void knap_sack(int depth, double weight, double profit, int capacity, double maxProfit, int numbest, int sett, int n, int bestset[], int include[]) {
	//cout << maxProfit << endl;
	if(weight <= capacity && profit>maxProfit){
		maxProfit = profit;
		numbest = depth;
		for(int i = 1; i<(sizeof(bestset)/sizeof(bestset[1])); i++) {
			bestset[i] = 0;	
		}
		for(int i = 1; i<(sizeof(include)/sizeof(include[1])); i++) {
			bestset[i] = include[i];
		}
	}
	int bound = upper(depth, weight, profit, capacity, n,  sett);
	if(weight<capacity&&bound>maxProfit) {
		include[depth+1] = 1;
		knap_sack(depth+1, (weight + weights[sett][depth+1]), (profit + profits[sett][depth+1]), capacity, maxProfit, numbest, sett, n, bestset, include);
		include[depth+1] = 0;
		knap_sack(depth+1, weight, profit, capacity, maxProfit, numbest, sett, n, bestset, include);

	}
}

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
		if(alg==0) {
		
			for(int i = 1; i<items[u]; i++) {
				for(int j = 1; j<=items[u]; j++) {
					if(ratios[u][j] > ratios[u][i]) {
						double temp = ratios[u][i];
						ratios[u][i] = ratios[u][j];
						ratios[u][j] = temp;
						
						temp = weights[u][i];
						weights[u][i] = weights[u][j];
						weights[u][j] = temp;
						
						temp = profits[u][i];
						profits[u][i] = profits[u][j];
						profits[u][j] = temp;
					}
				}
			}
			//for(int t = 0; t<3; t++) {
				//cout << ratios[u][t] << " " << weights[u][t] << " " << profits[u][t]<< endl;
			//}
			double totalWeight = 0;
			int maxProfit = 0;
			int iter = 1;
			while(totalWeight+weights[u][iter] <=knapcaps[u]) {
				totalWeight+=weights[u][iter];
				maxProfit+=profits[u][iter];
				knapsack.push_back(iter+1);
				iter++;
			}
			auto end = sc.now();
	 		auto time_span = static_cast<chrono::duration<double>>(end-start);
			output << items[u] << " "<< maxProfit<< " " << time_span.count();
			for(int i = 1; i<=iter; i++) {
				output << " " << i;	
			}
		}
		//greedy algorithm 2
		else if(alg==1) {
			for(int i = 1; i<=items[u]; i++) {
				for(int j = 1; j<=items[u]+1; j++) {
					if(ratios[u][j] > ratios[u][i]) {
						double temp = ratios[u][i];
						ratios[u][i] = ratios[u][j];
						ratios[u][j] = temp;
						
						temp = weights[u][i];
						weights[u][i] = weights[u][j];
						weights[u][j] = temp;
						
						temp = profits[u][i];
						profits[u][i] = profits[u][j];
						profits[u][j] = temp;
					}
				}
			}
			//for(int t = 0; t<3; t++) {
				//cout << ratios[u][t] << " " << weights[u][t] << " " << profits[u][t]<< endl;
			//}
			double totalWeight = 0;
			int maxProfit = 0;
			int iter = 1;
			while(totalWeight+weights[u][iter] <=knapcaps[u]) {
				totalWeight+=weights[u][iter];
				maxProfit+=profits[u][iter];
				knapsack.push_back(iter+1);
				iter++;
			}
			int pmax = 0;
			int id;
			for(int g = 0; g<=items[u]; g++) {
				if(profits[u][g] > pmax && weights[u][g] <=knapcaps[u]) {
					pmax = profits[u][g];
					id = g;
				}
			}
			auto end = sc.now();
	 		auto time_span = static_cast<chrono::duration<double>>(end-start);
			if(pmax>maxProfit){
				output << items[u] << " "<< pmax<< " " << time_span.count();
				
				for(int i = 1; i<=iter; i++) {
					output << " " << i;	
				}
				output << "" << endl;
			}
			else {
				output << items[u] << " "<< maxProfit<< " " << time_span.count() << " " << id << endl;
			}
		}
		//backtracking
		else {
			/*for(int t = 0; t<10; t++) {
				cout << ratios[u][t] << " " << weights[u][t] << " " << profits[u][t]<< endl;
			}*/
			for(int i = 1; i<=items[u]; i++) {
				for(int j = 1; j<=items[u]; j++) {
					if(ratios[u][j] < ratios[u][i]) {
						double tempr = ratios[u][i];
						ratios[u][i] = ratios[u][j];
						ratios[u][j] = tempr;
						
						double tempw = weights[u][i];
						weights[u][i] = weights[u][j];
						weights[u][j] = tempw;
						
						double tempp = profits[u][i];
						profits[u][i] = profits[u][j];
						profits[u][j] = tempp;
					}
				}
			}
			
			/*for(int t = 1; t<=20; t++) {
				cout << ratios[u][t] << " " << weights[u][t] << " " << profits[u][t]<< endl;
			}*/
			int bestset[1001];
			int include[1001];
			int numbest = 0;
			double maxProfit = 0;
			//knap_sack(0, 0, 0, knapcaps[u], maxProfit, numbest, u, items[u], bestset, include);
			int v = sizeof(weights)/sizeof(weights[1]);
			double tempo = napsack(knapcaps[u], v, u);
			auto end = sc.now();
	 		auto time_span = static_cast<chrono::duration<double>>(end-start);
			output << items[u] << " "<< tempo << " " << time_span.count() << endl;
			
			/*cout << maxProfit << endl;
			for(int i = 1; i<=numbest; i++) {
				cout << bestset[i] <<endl;	
			}*/
		}	
	}
	
output.close();
}
