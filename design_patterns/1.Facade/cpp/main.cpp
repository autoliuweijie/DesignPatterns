/*
    Example of  Facade pattern.
    @author: Liu Weijie
    @data: 2015-12-15

    需求:
        设计一个傻瓜相机, 只要选好拍照模式(白天模式或夜间模式), 即可自动完成各参数的设定.
*/
#include <iostream>

// SubSystem1
class FlashLight{
public:
    FlashLight(bool is_open_in=false){
        is_open = is_open_in;
    }

    void open(){
        is_open = true;
    }

    void close(){
        is_open = false;
    }

private:
    bool is_open;
};

// SubSystem2
class Shutter{
public:
    void action(){
        std::cout<<"action!\n";
    }
};

// SubSystem3
class Focus{
public:
    void set_focus_value(int value_in){
        focus_value = value_in;
    }

private:
    int focus_value;
};


// SubSystem4
class Aperture
{
public:
    Aperture(int value_in=0){
        aperture_value = value_in;
    };
    
    void set_aperture_value(int value_in){
        aperture_value =value_in;
    };

private:
    int aperture_value;
};

// Facade
class Camera{

public:
    Camera(){
        std::cout<<"create a camera successfully!\n";
    }

    void set_day_mode(){
        flash_light->close();
        focus->set_focus_value(10);
        aperture->set_aperture_value(10);
        std:: cout<<"set to day mode!";
    }

    void set_night_mode(){
        flash_light->close();
        focus->set_focus_value(10);
        aperture->set_aperture_value(90);
        std:: cout<<"set to night mode!";
    }

    void action(){
        shutter->action();
    }

private:
    FlashLight* flash_light = new FlashLight();
    Shutter* shutter = new Shutter();
    Focus* focus = new Focus();
    Aperture* aperture = new Aperture();

};

int main(int argc, const char * argv[]) {
    Camera* new_camera = new Camera();
    new_camera->set_day_mode();
    new_camera->action();
    new_camera->set_night_mode();
    return 0;
}




































