/*
 *串的最长公共子序列（LCS）算法
 *定义串Xm和Yn，求其LCS
 *算法分为两步：1.求LCS的长度，定义l[m][n]，时间Θ(mn)
 *2.逆序求LCS，时间Θ(m+n)
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX_LENGTH 100
void COMPUTE_LCS_TABLE(char *X, char *Y, 
					   int m,	int n, 
					   int l[][MAX_LENGTH])
{
	int i;
	//初始化l[m][n]第一行和第一列
	for (i = 0; i < m; i++)
		l[i][0] = 0;
	for (i = 0; i < n; i++)
		l[0][i] = 0;
	//计算l[m][n]
	int j;
	for (i = 1; i < m; i++) {
		for (j = 1; j < n; j++) {
			if (X[i] == Y[j])
				l[i][j] = l[i - 1][j - 1] + 1;
			else
				l[i][j] = max(l[i][j - 1], l[i - 1][j]);
		}//for
	}//for
}//COMPUTE_LCS_TABLE
void ASSEMBLE_LCS(char *X, char *Y, char *Z,
				int i,	int j,	int count_t,
								int l[][MAX_LENGTH])
{
	if (l[i][j] == 0) return;
	else if (l[i][j] >= 0 && i >= 0 && j >= 0&& count_t>=0) {
		if (X[i] == Y[j]) {
			Z[--count_t] = X[i];
			ASSEMBLE_LCS(X, Y, Z, i - 1, j - 1, count_t, l);
		}
		if (X[i] != Y[j]) {
			if (l[i][j - 1] > l[i - 1][j])
				ASSEMBLE_LCS(X, Y, Z, i, j - 1, count_t, l);
			else
				ASSEMBLE_LCS(X, Y, Z, i - 1, j, count_t, l);
		}//if
	}//else_if
	else exit(-1);
}//ASSEMBLE_LCS
char *LCS(char *X, char *Y)
{
	int m = strlen(X);
	int n = strlen(Y);
	int l[MAX_LENGTH][MAX_LENGTH];
	COMPUTE_LCS_TABLE(X, Y, m, n, l);
	int count_t = l[m - 1][n - 1];
	cout<<count_t<<endl;//输出LCS的长度
	char *Z = (char *)malloc(sizeof(char)*count_t);
	ASSEMBLE_LCS(X, Y, Z, m - 1, n - 1, count_t, l);
	return Z;
}//LCS
int main()
{//Χ,Υ字符串的零号单元未用
	char X[] = " XDEFRRRTGHASS";
	char Y[] = " EBSFRQQHUSS";
	char *Z = LCS(X, Y);
	cout << Z << endl;
}
