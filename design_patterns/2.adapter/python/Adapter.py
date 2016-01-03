# coding: utf-8
"""
    Example of Adapter pattern.
    @author: Liu Weijie
    @data: 2015-12-16

    需求:
        别人已经编写好一个XXCirecle类可以满足我们的需求, 但是这个类的接口不符合Shape类的要求.
"""


class XXCircle:
    """ XX圆， 已有的类，相当于Adeptee """

    def display(self):
        print "I am XXCircle!\n"


class Shape:
    """ 图形类的抽象接口 """

    def display(self):
        pass


class Circle:
    """ 圆，相当于Adapter """

    def __init__(self):
        self.XX_circle = XXCircle()

    def display(self):
        self.XX_circle.display()


if __name__ == "__main__":
    new_circle = Circle()
    new_circle.display()
