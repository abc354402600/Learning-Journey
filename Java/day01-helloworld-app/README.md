## 使用Java写出第一个程序
### 输出Hello World
public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello World!");

        System.out.println("--------------------------------");
        printHelloWorld();

        System.out.println("--------------------------------");
        System.out.println(sum(1, 2));
    }

    // 打印3行HelloWorld
    public static void printHelloWorld() {
        System.out.println("Hello World!");
        System.out.println("Hello World!");
        System.out.println("Hello World!");
    }
	
### 一些小测试
    // 我要求任意两个整数的和
    public static int sum(int a, int b) {
        return a + b;
    }
}