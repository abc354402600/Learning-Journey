#include "iostream"
using namespace std;


int main()
{
    // !
//    int num = 0;
//    if (!num) {
//        cout << "if被执行" << endl;
//    }else{
//        cout << "else 被执行" << endl;
//    };
    // &&
    int age, height;
    cout << "请输入你的年龄：" << endl;
    cin >> age;
    cout << "请输入你的身高(cm)：" << endl;
    cin >> height;

    // 必须同时满足年龄小于18 并且身高小于120cm 才可免费
//    if (age < 18 && height < 120) {
//        cout << "免费游玩！" << endl;
//    } else {
//        cout << "不可以免费游玩！" << endl;
//    }

    // ||满足年龄小于18 或者 身高小于120cm 才可免费
    if (age < 18 || height < 120) {
        cout << "免费游玩！" << endl;
    } else {
        cout << "不可以免费游玩！" << endl;
    }
    return 0;
}
