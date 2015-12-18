/*
    For bridge pattern.
    @author: Liu Weijie
    @date: 2015-12-16

    需求：
        设计一组容器：
            这些容器可能是数组，也可能是链表
            容器包括堆栈、队列
*/
#include <iostream>


// Implementor
class ContainerImp{

public:

    virtual void add_at_postion(char char_in, int postion)=0;

    virtual void fetch_at_postion(int postion)=0;
};


// ConcreteImplementorA
class Array: public ContainerImp{

public:

    void add_at_postion(char char_in, int postion){
        std:: cout<<"Add char_in at postion to Array successfuly!\n";
    }

    void fetch_at_postion(int postion){
        std:: cout<<"Fetch at postion to Array successfuly!\n";
    }
};


// ConcreteImplementorB
class Chain: public ContainerImp{

public:

    void add_at_postion(char char_in, int postion){
        std:: cout<<"Add char_in at postion to Chain successfuly!\n";
    }

    void fetch_at_postion(int postion){
        std:: cout<<"Fetch at postion to Chain successfuly!\n";
    }
};


// Abstraction
class Container{

public:

    virtual void add(char char_in)=0;

    virtual void fetch()=0;

    void set_implement(ContainerImp* implment_in){
        _implement = implment_in;
    }

    ContainerImp* get_implement(){
        return _implement;
    }

private:

    ContainerImp* _implement;
};


// ConcreteAbstractionA
class Stack: public Container{

public:

    Stack(ContainerImp* implment_in){
        set_implement(implment_in);
        _position = 0;
    }

    void add(char char_in){
        _position++;
        get_implement()->add_at_postion(char_in, _position);
    }

    void fetch(){
        get_implement()->fetch_at_postion(_position);
        _position--;
    }

private:

    int _position = 0;
};


// ConcreteAbstractionB
class Queue: public Container{

public:

    Queue(ContainerImp* implment_in){
        set_implement(implment_in);
        _position_head = 0;
        _position_tail = 0;
    }

    void add(char char_in){
        _position_head++;
        get_implement()->add_at_postion(char_in, _position_head);
    }

    void fetch(){
        get_implement()->fetch_at_postion(_position_tail);
        _position_tail--;
    }

private:

    int _position_head = 0;
    int _position_tail = 0;
};


int main(){
    ContainerImp* new_imp = new Array();
    Container* new_stack = new Stack(new_imp);
    new_stack->add('o');
    new_stack->fetch();
    return 0;
}



































