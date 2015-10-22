
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {

	//ofstream out("output.csv");
	//for (int i = 0; i < 10; ++i) {
	//	for (int j = 0; j < 5; ++j) {
	//		out << i*j << ",";
	//	}
	//	out << endl;
	//}
	//out.close();

	ifstream in("output.csv");
	string str;
	double n[10][5];
	int count = 0;

	while (in.good()) {
		getline(in, str);
		istringstream iss(str);
		string token;
		while (getline(iss, token, ',')) {
			double x = stod(token);
			n[count/5][count%5] = x;
			cout << x << "\t";
			count++;
		}
		cout << endl;
	}

	return 0;
}