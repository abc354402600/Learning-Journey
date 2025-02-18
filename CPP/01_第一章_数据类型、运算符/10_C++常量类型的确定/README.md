## 1.C++中，字面量的类型是自动确定的
	整数默认int，范围不足会自动扩容，顺序为：
	int -> uint -> long -> ulong -> long long -> u long long
	浮点数默认为double，范围不足会扩充到long double
	
## 2.可以给字面量添加后缀
	U		无符号数
	L 		整数long、浮点数long double
	UL 		unsigned long
	UUL		unsigned long long
	F		float
	D  		double