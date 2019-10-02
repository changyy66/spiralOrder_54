// spiralOrder_54.cpp : 定义控制台应用程序的入口点。
//
/*
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	if (matrix.size() == 0)return{};

	vector<int> res;
	int minR, maxR, minC, maxC;
	minR = 0;
	minC = 0;
	maxR = matrix.size();
	maxC = matrix[0].size();
	int n;
	while (1)
	{
		//left->right
		for (int i = minC; i < maxC; i++)
		{
			n = matrix[minR][i];
			res.push_back(n);
		}
		minR++;
		if (minR == maxR)return res;
		//up->down
		for (int i=minR;i<maxR;i++)
		{
			n = matrix[i][maxC-1];
			res.push_back(n);
		}
		maxC--;
		if (minC == maxC)return res;
		//right->left
		for (int i=maxC-1;i>=minC;i--)
		{
			n = matrix[maxR-1][i];
			res.push_back(n);
		}
		maxR--;
		if (minR == maxR)return res;
		//down->up
		for (int i=maxR-1;i>=minR;i--)
		{
			n = matrix[i][minC];
			res.push_back(n);
		}
		minC++;
		if (minC == maxC)return res;
	}
	
}

int main()
{
	vector<vector<int>> matrix = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	vector<int> res = spiralOrder(matrix);
	for each (auto var in res)
	{
		cout << var << " ";
	}
    return 0;
}

