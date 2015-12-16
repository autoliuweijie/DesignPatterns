/*
    For facade pattern.
    @author: Liu Weijie
    @date: 2015-12-16
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
    Circle* new_circle = new Circle();
    new_circle->display();
    return 0;
}




































