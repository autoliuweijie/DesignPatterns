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

private:

    ContainerImp* _implement;

};


// ConcreteAbstractionA
class Stack: public Container{

public:

    Stack(ContainerImp* implment_in){
        set_implement(implment_in);
        position = 0;
    }

    // void add(char char_in){
    //     implement->add_at_postion(char_in, position);
    //     position++;
    // }

private:

    int position = 0;
};



int main(){

    return 0;
}



































