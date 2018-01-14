//#include<iostream>
//#include<vector>
//using namespace std;
//
//// use NNNNNN connection to solve the problem,use 2D vector to save the order
//// 38ms,beat 22%
//string convert(string s, int numRows) {
//	int sz = s.size();
//	if (sz <= numRows || numRows==1) {
//		return s;
//	}
//
//
//	vector<vector<int>> temps(numRows);		// numRows is defined as the row of the vector
//	string result = "";
//
//	int pointer = 0;
//	// save to numRows-row-vector
//	for (int i = 0; i < sz; i++) {
//		pointer = i % (2 * (numRows - 1));
//		if (pointer >= numRows) {
//			pointer = 2 * (numRows - 1) - pointer;
//		}
//		temps[pointer].push_back(s[i]);
//	}
//
//	// order the vector temp to a string
//	for (int i = 0; i < numRows; i++) {
//		sz = temps[i].size();
//		for (int j = 0; j < sz; j++) {
//			result += temps[i][j];
//		}
//	}
//
//	return result;
//}