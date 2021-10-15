#include<iostream>
#include<math.h>    //数学工具的头文件声明
#include <iomanip>  //精度设定的头文件声明
using namespace std; //命名空间

//习题2.2
/*
int main()
{
   double PI = 3.1415926;
   double r1 = 40;
   int r2 = 928.335;
   double S1;
   int S2;
   S1 = pow(r1, 2) * PI;
   S2 = r2 * r2 * PI;
   cout << "半径为：" << r1 << "时" << endl;
   cout << "圆1的面积为：" << S1 << endl;
   cout << "半径为：" << r2 << "时" << endl;
   cout << "圆2的面积为：" << S2 << endl;
    return 0;
}
*/
//习题2.3
/*
int main()
{
    double M_e = 2.718281828;
    cout << "已知常数e=2.718281828" << endl;
    cout << "常数e小数点后10位有效数：" << endl;
    cout << fixed << setprecision(10) << M_e << endl;
    cout << "定点输出：";
    cout << setprecision(8) << fixed << M_e << endl;

    return 0;
}
*/
/*
int main()
{
    const double PI = 3.14;
    int x = 1, a = 1, c = 1;
    int x1,y,z;
    x1 = sqrt(pow(sin(x), 2.5));
    y = 0.5 * (a * x + ((a + x) / (a * 4)));
    z = pow(c, pow(x, 2)) / sqrt(2 * PI);
    

    return 0;
}
*/

//级数计算
/*
int f1(int a, int an=1)//a是输入的数，an为输出
{
    for (int i = 1; i < a; i++)
    {
        if (a == 0)
        {
            an = 1;
            break;
        }//这里如果是0！的话直接输出1
        an = i * an;

    }
    return an;
}

int main()//计算
{
    int n;
    int x;//计数
    float y = 0.00000000;
    cout << "请输入计算的次数n:";
    cin >> n;

    if (n >= 10000)//n的最大值计算
    {
        n = 10000;
    }

    if (n == 0)//n的最小指限制
    {
        cout << n << "次计算后的计算结果为：" << 1;
        return 0;
    }

    if (n<0) //次数不能小于0
    {
        cout << "error";
        return 0;
    }

    cout << "请输入x的值计算：";
    cin >> x;
    for (int i = 0; i <= n; i++)
    {
        int an = f1(i);
        y = y + (pow(-1, i + 1) * (pow(x, i) / an));
        //cout << y << endl;
    }
    cout << n <<"次计算后的计算结果为：" << y;

    return 0;
}
*/

//1
/*
int main()
{
    int a, b, c;
    int S;//面积
    int p;//半周长
    cout << "请输入三角形的第一条边：";
    cin >> a;
    cout << "请输入三角形的第二条边：";
    cin >> b;
    cout << "请输入三角形的第三条边：";
    cin >> c;
    if (a < 0 || b < 0 || c < 0)
    {
        cout << "错误，请输入正确的数值" << endl;
    }
    if (a + b > c && a + c > b && b + c > a)
    {
        cout << "该三边能构成三角形" << endl;
    }
    else
    {
        cout << "该三边不能构成一个三角形";
        return 0;
    }
    p = (a + b + c) / 2.00;
    S = sqrt(p * (p - a) * (p - b) * (p - c));
        cout << "该三角形的面积为:" << S;

    return 0;
}*/

//2
/*
int main()
{
    int n = 0;
    cout << "请输入年份:";
    cin >> n;
    if (n % 4 == 0 | n % 400 == 0)
    {
        cout << n << "年是闰年";
    }
    else
    {
        cout << n << "年不是闰年";
    }
    return 0;

}
*/

//3
int main()
{
    int BMI;
    int high, weight;
    cout << "请输入你的身高(m):";
    cin >> high;
    cout << "请输入你的体重（kg）";
    cin >> weight;

    BMI = weight / pow(high, 2);
    if (BMI < 18.5)
        cout << "偏瘦" << endl;
    if (BMI >= 18.5 && BMI <= 25)
        cout << "正常" << endl;
    if (BMI > 25 && BMI <= 30)
        cout << "超重" << endl;
    if (BMI > 30)
        cout << "肥胖" << endl;
    return 0;
}
