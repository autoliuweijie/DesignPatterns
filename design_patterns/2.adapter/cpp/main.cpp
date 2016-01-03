/*
    Example of Adapter pattern.
    @author: Liu Weijie
    @data: 2015-12-16

    需求:
        别人已经编写好一个XXCirecle类可以满足我们的需求, 但是这个类的接口不符合Shape类的要求.
*/
#include <iostream>

// XX圆，已有的类，相当于Adaptee
class XXCircle{
public:
    void display(){
        std::cout<< "I am circle!\n";
    }
};

// 图形类的接口
class VirtualShape{
public:
    virtual void display()=0;
};

// 圆形, 相当于Adapter
class Circle:public VirtualShape{
public:
    virtual void display(){
        xx_circle->display();
    }
private:
    XXCircle* xx_circle = new XXCircle();
};


int main(int argc, const char * argv[]) {
    VirtualShape* new_circle = new Circle();
    new_circle->display();
    return 0;
}




































