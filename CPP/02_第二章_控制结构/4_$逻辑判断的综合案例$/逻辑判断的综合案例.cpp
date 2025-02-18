#include "iostream"
#include "random"
using namespace std;
/*
 * 案例需求（猜扑克牌）:
 * 随机产出3份信息：
 * 第一份信息：1~10的数字，代表扑克牌1~10
 * 第二份信息：字符串，红色或黑色，代表扑克牌的花色
 * 第三份信息：字符串，如果是红色产出红桃或方块，如果是黑色产出黑桃或梅花
 * 案例要求:
 * 通过嵌套判断，并结合判断语句猜测上述信息，如
 * 先猜数字，成功后猜颜色，再成功猜测具体的花型
 */


/**
 * 生成指定范围内的随机数
 *
 * min 随机数范围的最小值
 * max 随机数范围的最大值
 * return 返回指定范围内的一个随机数
 *
 * 本函数使用C++标准库中的随机数引擎和均匀分布来生成随机数
 * 通过这种方式，可以确保生成的随机数在给定的范围内均匀分布
 */
int get_random_num(int min, int max)
{
    // 初始化随机数设备
    random_device rd;
    // 使用随机数设备种子初始化MT19937随机数引擎
    mt19937 gen(rd());

    // 定义一个均匀分布的整数随机数生成器，范围为[min, max]
    uniform_int_distribution<> dis(min, max);
    // 使用定义的分布和随机数引擎生成一个随机数
    int random_number = dis(gen);
    // 返回生成的随机数
    return random_number;
}


// 主函数
int main()
{
    // 声明其他变量，用于后续的猜测和随机数生成
    int num2, num3, num4;
    int guess;
    string str1, str2;

    // 无限循环，直到用户选择结束游戏
    while (1)
    {
        // 初始化第一个随机数，范围在1到10之间
        int num = get_random_num(1, 10);

        // 作弊
        cout << num << endl;

        // 提示用户输入猜测的数字
        cout << "输入猜的数字是（1-10）：" << endl;
        cin >> guess;

        // 如果用户猜中了数字
        if (guess == num)
        {
            // 生成第二个随机数，决定颜色
            num2 = get_random_num(0, 1);
            str1 = num2 ? "红色" : "黑色";

            // 作弊
            cout << str1 << endl;

            // 提示用户输入猜测的颜色
            cout << "成功猜中数字，现在请输入猜的颜色为（红色、黑色）：" << endl;
            string guess_str;
            cin >> guess_str;

            // 如果用户猜中了颜色
            if (guess_str == str1)
            {
                // 生成第三个随机数，决定花色
                num3 = get_random_num(1, 2);
                if (num3 == 1 && str1 == "红色")
                {
                    str2 = "红桃";
                }
                else if (num3 == 1 && str1 == "黑色")
                {
                    str2 = "黑桃";
                }
                else if (num3 == 2 && str1 == "红色")
                {
                    str2 = "方块";
                }
                else if (num3 == 2 && str1 == "黑色")
                {
                    str2 = "梅花";
                }

                // 作弊
                cout << str2 << endl;

                // 提示用户输入猜测的花色
                cout << "成功猜中颜色，现在请输入猜的花色为（红桃、方块、梅花、黑桃）：" << endl;
                string guess_str2;
                cin >> guess_str2;

                // 如果用户猜中了花色
                if (guess_str2 == str2)
                {
                    // 用户成功猜中所有环节
                    cout << "恭喜你全部猜对了！扑克牌为：" << str1 << " " << str2 << num << endl;
                }
                else
                {
                    // 用户猜错了花色
                    cout << "很遗憾，你猜错了！正确花色为：" << str2 << endl;
                }
            }
            else
            {
                // 用户猜错了颜色
                cout << "很遗憾，你猜错了！正确颜色为：" << str1 << endl;
            }
        }
        else
        {
            // 用户猜错了数字
            cout << "很遗憾，你猜错了！正确数字为：" << num << endl;
        }

        // 提示用户输入0以结束游戏
        cout << "输入0结束游戏" << endl;
        cin >> num4;

        // 如果用户输入0，则结束循环
        if (num4 == 0)
        {
            break;
        }
    }

    return 0;
}
