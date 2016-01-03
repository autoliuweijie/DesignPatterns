# coding: utf-8
"""
    Example of  Facade pattern.
    @author: Liu Weijie
    @data: 2015-12-15

    需求:
        设计一个傻瓜相机, 只要选好拍照模式(白天模式或夜间模式), 即可自动完成各参数的设定.
"""


class FlashLight(object):
    """ SubSystem1 """

    def __init__(self, is_open_in=False):
        self.is_open = is_open_in

    def open(self):
        self.is_open = True

    def close(self):
        self.is_open = False


class Shutter(object):
    """ SubSystem2 """

    def action(self):
        print "action!"


class Focus(object):
    """ SubSystem3 """

    def __init__(self, value_in=0):
        self.focue_value = value_in

    def set_focus_value(self, value):
        self.focue_value = value


class Aperture(object):
    """ SubSystem4 """

    def __init__(self, value_in=0):
        self.aperture_value = value_in

    def set_aperture_value(self, value):
        self.aperture_value = value


class Camera(object):
    """ Facade """

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
