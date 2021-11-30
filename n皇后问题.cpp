// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//多皇后问题
//要求：在n*n的国际象棋棋盘上摆放n个皇后，皇后之间不能相互"吃到"求几种摆法
/*
//递归法
#include<iostream>
using namespace std;
const int Normalsize = 9;   //常量，统一数组下标
int Num = 0;   //记录方案数（解法)
int Queen[9];  //记录8个皇后所占用的列号

bool C[9];  //bool型，判断该列是否可行
bool L[17]; //判断(i-j)对角线是否可行(L[2]-L[16])
bool R[17]; //判断（i+j）对角线是否可行(R[2]-R[16])

void check(int i)
{
	int j, k;
	for (j = 1; j <= 8; j++)
	{
		if ((C[j] == true) && (R[i + j] == true) && (L[i - j + Normalsize] == true))//表示第i行j列可行
		{
			Queen[i] = j;//占用（i，j）
			C[j] = false;
			L[i - j + Normalsize] = false;
			R[i + j] = false;
			if (i < 8)                                                      //判断是否放完8个皇后
			{
				check(i + 1);                                               //未完成则继续
			}
			else //已经放好皇后
			{
				Num++;
				cout << "解法" << Num << ":" << "\t";
				for (k = 1; k <= 8; k++)
				{
					cout << "( " << k << ", " << Queen[k] << " )"; //输出具体方案并
				}
				cout << endl;
			}
			C[j] = true;
			L[i - j + Normalsize] = true;
			R[i + j] = true;			
		}
	} //循环结束
}//check函数结束

int main()
{
	int i;
	Num = 0;//方案数清零
	for (i = 1; i < 9; i++)
	{
		C[i] = true;
	}
	for (i = 1; i < 17; i++)
	{
		L[i] = R[i] = true;
	}
	check(1);//放置皇后
	return 0;
}
*/

/*
//回溯法
#include <iostream>

#include <iomanip>

#include <string.h>

#include <math.h>

#include <stdlib.h>

using namespace std;



int queen[5]; //queen[i] 表示第i行的皇后，摆放在第queen[i]列



bool check(int x, int y) //判断（x,y）位置能否摆放皇后，如果可以，则返回true;

{

    int len = x;

    for (int i = 1; i < len; i++) //判断列，和对角线上有无冲突

        if (queen[i] == y || fabs(y - queen[i]) == fabs(x - i)) return false;

    return true;

}



void display()  //打印每个皇后的列的位置

{

    int i;

    cout << "[";

    for (i = 1; i <= 3; i++)

        cout << queen[i] << ",";

    cout << queen[i] << "]" << endl;

}



void search(int i)

{

    int flag;

    int count = 0;

    memset(queen, 0, sizeof(queen));

    while (i <= 4)

    {

        flag = 0;

        for (int j = queen[i] + 1; j <= 4; j++) //j = queen[i] + 1表示从第queen[i]列，

                                        //往后找另一个不冲突的位置，因为前面的已经找过了

        {

            if (check(i, j))     //如果(x,y)位置能否摆放皇后

            {

                queen[i] = j;  //将第i行的皇后摆放在第j列

                flag = 1;   //标记这一行可以摆放

                break;      //跳出这一层循环，开始摆放下一行的皇后

            }

        }

        if (flag == 0)  //如果循环完这一行，每个位置都冲突

        {

            queen[i] = 0; //将这一行的皇后位置重置为0;

            i--;       //返回到上一行

            if (i == 0)break; //如果已经返回到了第0行，说明所有情况都找完了

        }

        else

        {

            if (i == 4)  //如果找到了第4行，说明有满足条件的结果

            {

                display();  //输出结果

                count++;

            }

            else i++;

        }

    }

    cout << count << endl;

}

int main()

{

    search(1);

    system("pause");

    return 0;

}
*/

//快速排序
/*
#include <iostream>
using namespace std;


int Partition(int r[], int first, int end);


void Quick_Sort(int r[], int first, int end)
{
	if (first < end)
	{
		int pviot;
		pviot = Partition(r, first, end);//划分，pviot轴是序列中的位置
		Quick_Sort(r, first, pviot - 1);
		Quick_Sort(r, pviot + 1, end);
	}

}

int Partition(int r[], int first, int end)
{
	int i = first, j = end;         //初始化
	while (i < j)
	{
		while (i < j && r[i] <= r[j]) j--; //右侧扫描
		if (i < j) {
			swap(r[i], r[j]);            //将较小记录交换到前面
			i++;
		}
		while (i < j && r[i] <= r[j]) i++;  //左侧扫描
		if (i < j) {
			swap(r[j], r[i]);            //将较大记录交换到后面
			j--;
		}
	}
	return i;    // i为轴值记录的最终位置
}

int main()
{
	int r[] = { 1,3,4,6,8,5,54,25,63,98,45,24,89 };
	int size = sizeof(r) / sizeof(int);
	for (int m = 0; m <= size - 1; m++)
	{
		cout << r[m] << " ";
	}
	cout << endl;
	cout << "排序开始" << endl;
	Quick_Sort(r, 0, size - 1);
	for (int m = 0; m <= size - 1; m++)
	{
		cout << r[m] << " ";
	}
	return 0;
}
*/

/*
//堆排序
#include<iostream>
#include<algorithm>
using namespace std;
//声明区
void SiftHeap(int r[], int k, int n);
void InsertHeap(int r[], int k);

//函数区
//筛法调整堆
void SiftHeap(int r[], int k, int n)
{
	int i = 2 * n + 1;
	int j = 2 * n + 2;
	int maxIDx = n; //maxIDx是三个数中最大数的下标
	if (i<k && r[i]>r[maxIDx])
	{
		maxIDx = i;
	}
	if (j<k && r[j]>r[maxIDx])
	{
		maxIDx = j;
	}
	if (r[maxIDx] != r[n])
	{
		swap(r[maxIDx], r[n]);
		SiftHeap(r, k, n);//递归调整其他不满足性质的部分
	}
}
//插入法调整堆
void InsertHeap(int r[], int k)
{
	for (int i = k / 2 - 1; i >= 0; i--)
	{
		SiftHeap(r, k, i);
	}
	for (int i = k - 1; i >= 1; i--)
	{
		swap(r[0], r[i]); //将最大的放置到数组末尾
		SiftHeap(r, i, 0);
	}
}
int main()
{
	int r[] = { 8, 1, 14, 3, 21, 5, 7, 10 };
	int size = (int)sizeof(r) / sizeof(*r);
	//验证
	cout << "需要排序的数列: ";
	for (int i = 0; i <= size - 1; i++)
	{
		cout << r[i] << " ";
	}
	cout << endl;
	InsertHeap(r, size-1);
	//输出
	cout << "已排序好的数列: ";
	for (int i = 0; i <= size - 1; i++)
	{
		cout << r[i] << " ";
	}
	cout << endl;
	return 0;
}
*/

