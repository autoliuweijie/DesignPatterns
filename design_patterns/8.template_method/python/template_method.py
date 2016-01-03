# coding: utf-8
"""
    Example of  Template Method pattern.
    @author: Liu Weijie
    @data: 2016-01-03

    需求:
        一个支持在屏幕上绘图的类View。一个view获得焦点之后才能设置特定的图形设备环境（如颜色、字体等），因而只有获得焦点后才能绘图。
"""


class View(object):
    """ AbstractTemplate """

    def set_focus(self):
        print "this is set_focus()!"

    def reset_focus(self):
        print "this is reset_focus()!"

    def do_display(self):
        print "this is do_display()!"

    def display(self):
        self.set_focus()
        self.do_display()
        self.reset_focus()


class MyView(View):
    """ ConcreteTemplate """

    def do_display(self):
        """
            Write your display code here.
        """
        print "this is my display code!"


if __name__ == "__main__":
    my_view = MyView()
    my_view.display()