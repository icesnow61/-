//秦九韶算法：求n次多项式f(x)的值就转化为求n个一次多项式的值
/*
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int main() {
    int n;
    cout << "请输入多项式的次数 ：";
    cin >> n;
    double* a = new double[n + 1];//n次多项式申请n+1大小的数组
    cout << "请输入多项式的系数（最高次项开始）:" << endl;
    for (int i = n; i >= 0; i--)
        cin >> a[i];//读入各项系数
    double x0, ans = a[n];
    cout << "请输入 X0 " << endl;
    cin >> x0;
    for (int i = n - 1; i >= 0; i--)
        ans = ans * x0 + a[i];//最高次项开始，往外展开
    cout << "多项式在X0出的函数值为：" << ans << endl;
    delete[]a;//释放动态内存
    return 0;
}
*/


//最小二乘法
/*
#include<iostream>
#include<fstream>
#include<vector>  
using namespace std;

class LeastSquare {
    double a, b;
public:
    LeastSquare(const vector<double>& x, const vector<double>& y)
    {
        double t1 = 0, t2 = 0, t3 = 0, t4 = 0;
        for (int i = 0; i < x.size(); ++i)
        {
            t1 += x[i] * x[i];
            t2 += x[i];
            t3 += x[i] * y[i];
            t4 += y[i];
        }
        a = (t3 * x.size() - t2 * t4) / (t1 * x.size() - t2 * t2);
        //b = (t4 - a*t2) / x.size();  
        b = (t1 * t4 - t2 * t3) / (t1 * x.size() - t2 * t2);
    }

    double getY(const double x) const
    {
        return a * x + b;
    }

    void print() const
    {
        cout << "y = " << a << "x + " << b << "\n";
    }

};

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Usage: DataFile.txt" << endl;
        return -1;
    }
    else
    {
        vector<double> x;
        ifstream in(argv[1]);
        for (double d; in >> d; )
            x.push_back(d);
        int sz = x.size();
        vector<double> y(x.begin() + sz / 2, x.end());
        x.resize(sz / 2);
        LeastSquare ls(x, y);
        ls.print();

        cout << "Input x : \n";
        double x0;
        while (cin >> x0)
        {
            cout << "y = "<< ls.getY(x0) << endl;
            cout << "Input x : \n";
        }
    }
}
*/