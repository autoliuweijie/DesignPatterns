/*
    Example of  Abstract Factory pattern.
    @author: Liu Weijie
    @data: 2015-12-19

    需求:
        高级显示驱动配高级打印驱动.
        低级显示驱动配低级打印驱动.
*/
#include <iostream>


// AbstractProductA
class DisplayDriver{

public:

    virtual void line()=0;

    virtual void point()=0;
};


// ProductA1 低级产品
class LRDD: public DisplayDriver{

public:

    virtual void line(){
        std::cout << "I am LRDD line()!\n";
    }

    virtual void point(){
        std::cout << "I am LRDD point()!\n";
    }
};


// ProductA2 高级产品
class HRDD: public DisplayDriver{

public:

    virtual void line(){
        std::cout << "I am HRDD line()!\n";
    }

    virtual void point(){
        std::cout << "I am HRDD point()!\n";
    }
};


// AbstractProductB
class PrintDriver{

public:

    virtual void line()=0;

    virtual void point()=0;
};


// ProductB1 低级产品
class LRPD: public PrintDriver{

public:

    virtual void line(){
        std::cout << "I am LRPD line()!\n";
    }

    virtual void point(){
        std::cout << "I am LRPD point()!\n";
    }
};


// ProductB2 高级产品
class HRPD: public PrintDriver{

public:

    virtual void line(){
        std::cout << "I am HRPD line()!\n";
    }

    virtual void point(){
        std::cout << "I am HRPD point()!\n";
    }
};


// AbstractFactory
class CreateRD{

public:

    virtual DisplayDriver* create_display_driver()=0;

    virtual PrintDriver* create_print_driver()=0;
};


// ConcreteFactory1 生产低级产品
class CreateLRD: public CreateRD{

public:

    virtual DisplayDriver* create_display_driver(){
        return new LRDD();
    }

    virtual PrintDriver* create_print_driver(){
        return new LRPD();
    }
};


// ConcreteFactory2 生产高级产品
class CreateHRD: public CreateRD{

public:

    virtual DisplayDriver* create_display_driver(){
        return new HRDD();
    }

    virtual PrintDriver* create_print_driver(){
        return new HRPD();
    }
};


int main(){
    CreateRD* new_factory = new CreateHRD();
    DisplayDriver* new_DD = new_factory->create_display_driver();
    new_DD->line();
    PrintDriver* new_PD = new_factory->create_print_driver();
    new_PD->point();
    return 0;
}
























































