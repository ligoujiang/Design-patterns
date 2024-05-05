#include<iostream>
#include<list>
using namespace std;

/*
�۲���ģʽ
����������һ�Զ��ϵʱ����ʹ�ù۲���ģʽ��observer pattern����
���磬��һ�������޸�ʱ������Զ�֪ͨ���������Ķ��󡣹۲���ģʽ������Ϊ��ģʽ��
*/


//�����ѧ���ӿ�,����Ĺ۲���
class AbstractStudent {
public:
    virtual void Update() = 0;
};

//�����ѧ��������Ĺ۲��ߣ�����չ���仯
class StudentA : public AbstractStudent {
public:
    StudentA() {
        cout << "ѧ��A���ڳ���..." << endl;
    }
    virtual void Update() {
        cout << "ѧ��Aֹͣ���֣�����������" << endl;
    }
};

class StudentB : public AbstractStudent {
public:
    StudentB() {
        cout << "ѧ��B���ڳ���..." << endl;
    }
    virtual void Update() {
        cout << "ѧ��Bֹͣ���֣�����������" << endl;
    }
};

class StudentC : public AbstractStudent {
public:
    StudentC() {
        cout << "ѧ��C���ڳ���..." << endl;
    }
    virtual void Update() {
        cout << "ѧ��Cֹͣ���֣�����������" << endl;
    }
};



//�۲�Ŀ�꣬�ȶ�
class TeacherA {
public:
    void addStudent(AbstractStudent* student) {
        PStudentList.push_back(student);
    }

    void deleteStudent(AbstractStudent* student) {
        PStudentList.remove(student);
    }

    void notify() {
        for (list<AbstractStudent*>::iterator it = PStudentList.begin(); it != PStudentList.end(); it++) {
            (*it)->Update();
        }
    }
private:
    list<AbstractStudent*> PStudentList;
};

void test1() {
    //�����۲���
    AbstractStudent* studentA = new StudentA;
    AbstractStudent* studentB = new StudentB;
    AbstractStudent* studentC = new StudentC;
    //�����۲�Ŀ��
    TeacherA* teacherA = new TeacherA;
    teacherA->addStudent(studentA);
    teacherA->addStudent(studentB);
    teacherA->addStudent(studentC);

    cout << "studentBȥ�ϲ�����..." << endl;
    teacherA->deleteStudent(studentB);

    cout << "teacherA��ʦ���ˣ���" << endl;
    teacherA->notify();
}

int main() {
    test1();
    return 0;
}
