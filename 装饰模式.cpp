#include <iostream>
using namespace std;

/*
װ��ģʽ
װ��ģʽָ�����ڲ��ظı�ԭ���ļ���ʹ�ü̳е�����£���̬����չһ������Ĺ��ܡ�
����ͨ������һ����װ����Ҳ����װ����������ʵ�Ķ���
*/


//�ȶ�
//������� 
class Tea {
public:
	Tea() {}
	virtual string teaName() = 0;
	virtual float teaPrice() = 0;
};
//�̲�
class MilkTea :public Tea {
public:
	MilkTea() {}
	string teaName() override{
		return "�̲�";
	}
	float teaPrice() override {
		return 9.5f;
	}
};
//���
class RedTea :public Tea {
public:
	RedTea() {}
	string teaName() override {
		return "���";
	}
	float teaPrice() override {
		return 5.0f;
	}
};
//�̲�
class GreenTea :public Tea {
public:
	GreenTea() {}
	string teaName() override {
		return "�̲�";
	}
	float teaPrice() override {
		return 6.0f;
	}
};

//�仯
//װ��Ʒ
class Decorator : public Tea {
protected:
	Tea* m_tea;
public:
	Decorator(Tea *tea) : m_tea(tea){}
};
//��
class Sugar : public Decorator {
public:
	Sugar(Tea *tea): Decorator(tea) {}
	virtual string teaName() override{
		return m_tea->teaName() + "+һ����";
	}
	virtual float teaPrice() override {
		return m_tea->teaPrice() + 1.0f;
	}
};
//�ɿ���
class Chocolate : public Decorator {
public:
	Chocolate(Tea* tea) : Decorator(tea) {}
	virtual string teaName() override {
		return m_tea->teaName() + "+һ���ɿ���";
	}
	virtual float teaPrice() override {
		return m_tea->teaPrice() + 2.0f;
	}
};
//��
class Acid : public Decorator {
public:
	Acid(Tea* tea) : Decorator(tea) {}
	virtual string teaName() override {
		return m_tea->teaName() + "+һ����";
	}
	virtual float teaPrice() override {
		return m_tea->teaPrice() + 0.5f;
	}
};



int main() {
	//��һ���̲�
	MilkTea *milktea = new MilkTea();
	cout << milktea->teaName() << "�ļ۸� " << milktea->teaPrice() << endl;
	//һ���̲�+һ����
	Sugar* sugar = new Sugar(milktea);
	cout << sugar->teaName() << "�ļ۸� " << sugar->teaPrice() << endl;
	//һ���̲�+һ����+һ���ɿ���
	Chocolate* chocolate = new Chocolate(sugar);
	cout << chocolate->teaName() << "�ļ۸� " << chocolate->teaPrice() << endl;
	return 0;
}
