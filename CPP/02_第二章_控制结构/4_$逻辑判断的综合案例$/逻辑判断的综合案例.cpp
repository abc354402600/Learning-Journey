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

int get_random_num(int min, int max)
{
    // 创建一个随机数生成器
    random_device rd;
    mt19937 gen(rd());


    // 定义一个均匀分布的整数范围
    uniform_int_distribution<> dis(min, max);

    // 生成一个随机数并输出
    int random_number = dis(gen);
    return random_number;
}

int main()
{
//    int num = get_random_num(1, 10);
//    cout << num << endl;

    // 第一份信息：1~10的数字，代表扑克牌1~10
    int num = get_random_num(1, 10);
    // 第二份信息：字符串，红色或黑色，代表扑克牌的花色
    string color = get_random_num(0, 1)? "红色" : "黑色";
    // 第三份信息：字符串，如果是红色产出红桃或方块，如果是黑色产出黑桃或梅花
    string suit;
    if (color == "红色") {
        suit = get_random_num(0, 1)? "红桃" : "方块";
    }else {
        suit = get_random_num(0, 1)? "黑桃" : "梅花";
    }
    cout << num << ":" << color << ":" << suit << endl;

    // 先猜数字，成功后猜颜色，再成功猜测具体的花型
    int guess_num;
    cout << "请输入猜测的扑克牌数字：" << endl;
    cin >> guess_num;
    if (guess_num == num) {
        // 数字对了就要猜颜色了
        cout << "请猜测颜色，红色输入1，黑色输入0：" << endl;
        int color_num;
        cin >> color_num;

        if ((color_num?"红色":"黑色") == color){
            // 颜色猜对了
            int suit_num;

            if (color == "红色") {
                // 要猜测是否是红桃或方块
                cout << "请猜测花型，红桃输入1，方块输入0：" << endl;
                cin >> suit_num;

                if ((suit_num?"红桃":"方块") == suit) {
                    // 花型正确
                    cout << "恭喜你游戏成功，花型猜测正确，游戏的花型是：" << suit << endl;
                } else {
                    cout << "游戏失败，花型猜测错误，游戏的正确花型是：" << suit << endl;
                }
            } else {
                // 要猜测是否是黑桃或梅花
                cout << "请猜测花型，黑桃输入1，梅花输入0：" << endl;
                cin >> suit_num;

                if ((suit_num?"黑桃":"梅花") == suit) {
                    // 花型正确
                    cout << "恭喜你游戏成功，花型猜测正确，游戏的花型是：" << suit << endl;
                } else {
                    cout << "游戏失败，花型猜测错误，游戏的正确花型是：" << suit << endl;
                }
            }

        } else {
            // 颜色猜错了
            cout << "颜色猜错了，游戏结束！！！" << endl;
        }

    } else {
        cout << "数字错误，游戏结束！！！" << endl;
    }


    return 0;
}
