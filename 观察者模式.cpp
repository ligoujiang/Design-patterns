#include<iostream>
#include<list>
using namespace std;

/*
观察者模式
当对象间存在一对多关系时，则使用观察者模式（observer pattern）。
比如，当一个对象被修改时，则会自动通知发依赖它的对象。观察者模式属于行为型模式。
*/


//抽象的学生接口,抽象的观察者
class AbstractStudent {
public:
    virtual void Update() = 0;
};

//具体的学生，具体的观察者，可扩展，变化
class StudentA : public AbstractStudent {
public:
    StudentA() {
        cout << "学生A正在吵闹..." << endl;
    }
    virtual void Update() {
        cout << "学生A停止吵闹，立即坐正！" << endl;
    }
};

class StudentB : public AbstractStudent {
public:
    StudentB() {
        cout << "学生B正在吵闹..." << endl;
    }
    virtual void Update() {
        cout << "学生B停止吵闹，立即坐正！" << endl;
    }
};

class StudentC : public AbstractStudent {
public:
    StudentC() {
        cout << "学生C正在吵闹..." << endl;
    }
    virtual void Update() {
        cout << "学生C停止吵闹，立即坐正！" << endl;
    }
};



//观察目标，稳定
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
    //创建观察者
    AbstractStudent* studentA = new StudentA;
    AbstractStudent* studentB = new StudentB;
    AbstractStudent* studentC = new StudentC;
    //创建观察目标
    TeacherA* teacherA = new TeacherA;
    teacherA->addStudent(studentA);
    teacherA->addStudent(studentB);
    teacherA->addStudent(studentC);

    cout << "studentB去上厕所了..." << endl;
    teacherA->deleteStudent(studentB);

    cout << "teacherA老师来了！！" << endl;
    teacherA->notify();
}

int main() {
    test1();
    return 0;
}
