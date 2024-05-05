#include <iostream>
using namespace std;

/*
装饰模式
装饰模式指的是在不必改变原类文件和使用继承的情况下，动态地扩展一个对象的功能。
它是通过创建一个包装对象，也就是装饰来包裹真实的对象。
*/


//稳定
//抽象茶类 
class Tea {
public:
	Tea() {}
	virtual string teaName() = 0;
	virtual float teaPrice() = 0;
};
//奶茶
class MilkTea :public Tea {
public:
	MilkTea() {}
	string teaName() override{
		return "奶茶";
	}
	float teaPrice() override {
		return 9.5f;
	}
};
//红茶
class RedTea :public Tea {
public:
	RedTea() {}
	string teaName() override {
		return "红茶";
	}
	float teaPrice() override {
		return 5.0f;
	}
};
//绿茶
class GreenTea :public Tea {
public:
	GreenTea() {}
	string teaName() override {
		return "绿茶";
	}
	float teaPrice() override {
		return 6.0f;
	}
};

//变化
//装饰品
class Decorator : public Tea {
protected:
	Tea* m_tea;
public:
	Decorator(Tea *tea) : m_tea(tea){}
};
//糖
class Sugar : public Decorator {
public:
	Sugar(Tea *tea): Decorator(tea) {}
	virtual string teaName() override{
		return m_tea->teaName() + "+一勺糖";
	}
	virtual float teaPrice() override {
		return m_tea->teaPrice() + 1.0f;
	}
};
//巧克力
class Chocolate : public Decorator {
public:
	Chocolate(Tea* tea) : Decorator(tea) {}
	virtual string teaName() override {
		return m_tea->teaName() + "+一块巧克力";
	}
	virtual float teaPrice() override {
		return m_tea->teaPrice() + 2.0f;
	}
};
//酸
class Acid : public Decorator {
public:
	Acid(Tea* tea) : Decorator(tea) {}
	virtual string teaName() override {
		return m_tea->teaName() + "+一勺酸";
	}
	virtual float teaPrice() override {
		return m_tea->teaPrice() + 0.5f;
	}
};



int main() {
	//点一杯奶茶
	MilkTea *milktea = new MilkTea();
	cout << milktea->teaName() << "的价格： " << milktea->teaPrice() << endl;
	//一杯奶茶+一勺糖
	Sugar* sugar = new Sugar(milktea);
	cout << sugar->teaName() << "的价格： " << sugar->teaPrice() << endl;
	//一杯奶茶+一勺糖+一块巧克力
	Chocolate* chocolate = new Chocolate(sugar);
	cout << chocolate->teaName() << "的价格： " << chocolate->teaPrice() << endl;
	return 0;
}
