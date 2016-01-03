/*
    Example of  Template Method pattern.
    @author: Liu Weijie
    @data: 2016-01-03

    需求:
        一个支持在屏幕上绘图的类View。一个view获得焦点之后才能设置特定的图形设备环境（如颜色、字体等），因而只有获得焦点后才能绘图。
*/
#include <iostream>


using namespace std;


// AbstractTemplate
class View{

public:

    virtual void set_focus(void){
        cout << "this is set_focus()!" << endl;
    }

    virtual void reset_focus(void){
        cout << "this is reset_focus()!" << endl;
    }

    virtual void do_display(void){
        cout << "this do_display()!" << endl;
    }

    virtual void display(void){
        set_focus();
        do_display();
        reset_focus();
    }
};


class MyView: public View{

protected:

    virtual void do_display(void){
        cout<< "this is my display code!" << endl;
    }
};

int main(){
    View* my_view = new MyView();
    my_view->display();
    return 0;
}
