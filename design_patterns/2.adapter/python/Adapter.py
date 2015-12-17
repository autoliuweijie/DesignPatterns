# coding: utf-8


class XXCircle:
    ''' XX圆， 已有的类，相当于Adeptee '''

    def display(self):
        print "I am XXCircle!\n"


class Shape:
    ''' 图形类的抽象接口 '''

    def display(self):
        pass


class Circle:
    ''' 圆，相当于Adapter '''

    def __init__(self):
        self.XX_circle = XXCircle()

    def display(self):
        self.XX_circle.display()


if __name__ == "__main__":
    new_circle = Circle()
    new_circle.display()
