# coding: utf-8


class FlashLight(object):
    ''' 闪光灯 '''

    def __init__(self, is_open_in=False):
        self.is_open = is_open_in

    def open(self):
        self.is_open = True

    def close(self):
        self.is_open = False


class Shutter(object):
    ''' 快门 '''

    def action(self):
        print "action!"


class Focus(object):
    ''' 焦距 '''

    def __init__(self, value_in=0):
        self.focue_value = value_in

    def set_focus_value(self, value):
        self.focue_value = value


class Aperture(object):
    ''' 光圈 '''

    def __init__(self, value_in=0):
        self.aperture_value = value_in

    def set_aperture_value(self, value):
        self.aperture_value = value


class Camera(object):
    ''' 相机 就是Facade类 '''

    def __init__(self):
        self.flash_light = FlashLight()
        self.shutter = Shutter()
        self.focus = Focus()
        self.aperture = Aperture()

    def set_day_mode(self):
        self.flash_light.close()
        self.focus.set_focus_value(10)
        self.aperture.set_aperture_value(10)
        print "set to day model successfuly!"

    def set_night_mode(self):
        self.flash_light.open()
        self.focus.set_focus_value(50)
        self.aperture.set_aperture_value(80)
        print "set to night model successfuly!"

    def action(self):
        self.shutter.action()


if __name__ == "__main__":
    camera = Camera()
    camera.set_day_mode()
    camera.action()
    camera.set_night_mode()
    camera.action()
