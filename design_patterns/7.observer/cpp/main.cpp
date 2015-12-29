/*
    Example of  Observer pattern.
    @author: Liu Weijie
    @data: 2015-12-25

    需求:
        系统内有一个计时器（模型，没有界面），这个计时器驱动两个形式的时钟界面，一个数字时钟，一个模拟时钟.
*/
#include <iostream>
#include <list>
using namespace std;


class Observer;


// Subject
class Subject{

public:

    Subject(){}

    virtual void attach(Observer* observer_add){
        _observers->push_back(observer_add);
    }

    virtual void detach(Observer* observer_del){
        _observers->remove(observer_del);
    }

    virtual void notify(){

    }
protected:

    list<Observer*>* _observers;

};

// Observer
class Observer{

public:

    virtual void update(Subject* subject)=0;
};



int main(){

    Subject* new_subject = new Subject();
    Observer* new_observer = new Observer();
    new_subject->attach(new_observer);
    new_subject->notify();

    return 0;
}



