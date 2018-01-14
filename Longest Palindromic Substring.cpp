//#include<iostream>
//using namespace std;
//
//// naive one, beat 22.71%
//string longestPalindrome(string s) {
//	int sz = s.size();
//	int len = 1, start = 0;
//	string result = "";
//
//	if (s == "")
//		return "";
//
//	result = s.substr(0, 1);
//	
//	// odd situation
//	for (int i = 0; i < sz; i++) {
//		int j = i-1;
//		int mirror_j = i + 1;
//		int str_len = 1;
//		while (j >= 0 && mirror_j < sz) {
//			if (s.substr(j, 1) != s.substr(mirror_j, 1)) {
//				break;
//			}
//			j--;
//			mirror_j++;
//			str_len += 2;
//		}
//		if (str_len > len) {
//			start = j + 1;
//			len = str_len;
//		}
//	}
//
//	// even situation
//	for (int i = 1; i < sz; i++) {
//		int j = i - 1;
//		int mirror_j = i;
//		int str_len = 0;
//		while (j >= 0 && mirror_j < sz) {
//			if (s.substr(j, 1) != s.substr(mirror_j, 1)) {
//				break;
//			}
//			j--;
//			mirror_j++;
//			str_len += 2;
//		}
//		if (str_len > len) {
//			start = j + 1;
//			len = str_len;
//		}
//	}
//
//	return s.substr(start, len);
//}
//
//// strong one, manacher's alg. Beat 41.69%
//string longestPalindrome(string s) {
//	int sz = s.size();
//	int len = 0, start = 0;
//	string result = "";
//	string t = "";
//
//	if (s == "")
//		return "";
//
//	for (int i = 0; i < sz; i++) {
//		t += s[i];
//		t += '#';
//	}
//	sz = t.size();
//	// odd and even situation
//	for (int i = 0; i < sz; i++) {
//		int j = i - 1;
//		int mirror_j = i + 1;
//		int str_len = 1;
//		while (j >= 0 && mirror_j < sz) {
//			if (t[j] != t[mirror_j]) {
//				break;
//			}
//			j--;
//			mirror_j++;
//			str_len += 2;
//		}
//		if (str_len > len) {
//			start = j + 1;
//			len = str_len;
//		}
//	}
//	string p = t.substr(start, len);
//	for (int i = 0; i < len; i++) {
//		if (p[i] != '#') {
//			result += p[i];
//		}
//	}
//	return result;
//}