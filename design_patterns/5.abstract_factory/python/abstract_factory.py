# coding: utf-8
"""
    Example of  Abstract Factory pattern.
    @author: Liu Weijie
    @data: 2015-12-19

    需求:
        高级显示驱动配高级打印驱动.
        低级显示驱动配低级打印驱动.
"""


class DisplayDriver(object):
    """ AbstractProductA """

    def line(self):
        pass

    def point(self):
        pass


class LRDD(DisplayDriver):
    """ ProductA1 低级产品 """

    def line(self):
        print "I am LRDD line()!\n"

    def point(self):
        print "I am LRDD point()!\n"


class HRDD(DisplayDriver):
    """ ProductA2 高级产品 """

    def line(self):
        print "I am HRDD line()!\n"

    def point(self):
        print "I am HRDD point()!\n"


class PrintDriver(object):
    """ AbstractProductB """

    def line(self):
        pass

    def point(self):
        pass


class LRPD(PrintDriver):
    """ ProductB1 低级产品 """

    def line(self):
        print "I am LRPD line()!\n"

    def point(self):
        print "I am LRPD point()!\n"


class HRPD(PrintDriver):
    """ ProductB2 高级产品 """

    def line(self):
        print "I am HRPD line()!\n"

    def point(self):
        print "I am HRPD point()!\n"


class CreateRD(object):
    """ AbstractFactory """

    def create_display_driver(self):
        pass

    def create_print_driver(self):
        pass


class CreateLRD(CreateRD):
    """ ConcreteFactory1 生产低级产品 """

    def create_display_driver(self):
        return LRDD()

    def create_print_driver(self):
        return LRPD()


class CreateHRD(CreateRD):
    """ ConcreteFactory2 """

    def create_display_driver(self):
        return HRDD()

    def create_print_driver(self):
        return HRPD()

if __name__ == "__main__":
    new_factory = CreateHRD()
    new_DD = new_factory.create_display_driver()
    new_DD.line()
    new_PD = new_factory.create_print_driver()
    new_PD.point()
