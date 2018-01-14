//#include<iostream>
//#include<vector>
//using namespace std;
//
//// naive solution .Beat 3.72% people
//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//	int len1 = nums1.size();
//	int len2 = nums2.size();
//
//	int len = len1 + len2;			
//	int tracer = 0;				// tracer of the position	
//	int old_tracer;
//	int limit_count;
//
//	// numbers of half of the length are needed. 
//	if (len % 2 == 0) {		// calculate the mean of two elements
//		limit_count = len / 2 + 1;
//		cal_tracers(nums1, nums2, tracer, old_tracer, limit_count, len1, len2);
//		return float(old_tracer + tracer) / 2;
//	}
//	else {					// search for the only median
//		limit_count = (len + 1) / 2;
//		cal_tracers(nums1, nums2, tracer, old_tracer, limit_count, len1, len2);
//		return tracer;
//	}
//	
//}
//
//void cal_tracers(vector<int>& nums1, vector<int>& nums2, int&tracer, int&old_tracer,int limit_count,int len1,int len2){
//	int count = 0, i = 0, j = 0;// position of two vectors and size of results
//	while (count < limit_count) {
//		old_tracer = tracer;
//		if (i == len1) {		// only nums2 remains
//			tracer = nums2[j];
//			j++;
//		}
//		else if (j == len2) {	// only nums1 remains
//			tracer = nums1[i];
//			i++;
//		}
//		else {
//			tracer = nums2[j];
//			j++;
//			if (nums1[i] < tracer) {
//				tracer = nums1[i];
//				i++;
//				j--;
//			}
//		}
//		count++;
//	}
//}
//
//
//// Further solution. Beat 47%
//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//	int m = nums1.size(), n = nums2.size();
//	if (m > n)
//		return findMedianSortedArrays(nums2, nums1);
//	int i, j, imin = 0, imax = m, half = (m + n + 1)>>1;
//	while (imin <= imax) {
//		i = (imin & imax) + ((imin ^ imax) >> 1);//(imin+imax)/2
//		j = half - i;
//		if (i > 0 && j < n && nums1[i - 1] > nums2[j]) 
//			imax = i - 1;
//		else if (j > 0 && i < m && nums2[j - 1] > nums1[i]) 
//			imin = i + 1;
//		else 
//			break;
//	}
//	int num1;
//	if (!i) 
//		num1 = nums2[j - 1];
//	else if (!j) 
//		num1 = nums1[i - 1];
//	else 
//		num1 = max(nums1[i - 1], nums2[j - 1]);
//	if ((m + n) & 1) return num1;
//	int num2;
//	if (i == m) 
//		num2 = nums2[j];
//	else if (j == n) 
//		num2 = nums1[i];
//	else 
//		num2 = min(nums1[i], nums2[j]);
//	return (num1 + num2) / 2.0;
//}
//int max(int num1, int num2) {
//	if (num1 > num2)
//		return num1;
//	return num2;
//}
//int min(int num1, int num2) {
//	if (num1 > num2)
//		return num2;
//	return num1;
//}