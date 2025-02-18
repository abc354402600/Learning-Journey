#include "iostream"
using namespace std;
/*
 * 通过cin输入猜想的数字
 * 通过if else等逻辑判断语句的嵌套 完成三次机会的猜测
 */

int main()
{
    // 1. 提供一个数字，供猜想使用
    int num = 5;
    // 2. 提供一个变量，记录猜想的数字
    int guess_num;
    // 3. 通过cin接收输入，输入猜想的数字
    cout << "请输入第一次猜想的数字：" << endl;
    cin >> guess_num;

    // 第一次判断猜想数字是否正确
    if (guess_num == num) {
        cout << "恭喜你，第一次就猜对了！" << endl;
    }else {
        cout << "不好意思，你猜错了，请第二次猜测：" << endl;
        cin >> guess_num;       // 第二次要求用户猜测数字

        // 第二次判断猜想是否正确
        if (guess_num == num) {
            cout << "恭喜你，第二次猜对了！" << endl;
        } else {
            cout << "不好意思，你第二次猜错了，请第三次猜测：" << endl;
            cin >> guess_num;       // 第三次要求用户猜测数字

            // 第三次判断猜想是否正确
            if (guess_num == num) {
                cout << "恭喜你，第三次猜对了！" << endl;
            } else {
                cout << "不好意思，三次机会用完，你都猜错了，我想的是：" << num << endl;
            }
        }
    }

    return 0;
}
