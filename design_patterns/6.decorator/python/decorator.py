# coding: utf-8
"""
    Example of  Decorator pattern.
    @author: Liu Weijie
    @data: 2015-12-19

    需求:
        设计一个给发票对象添加新功能的装饰器:
            所有发票都有打印正文的功能, 但是有些发票有表头或页脚.
"""


class Component(object):
    """ VirtualComponent """

    def print_ticket(self):
        pass


class SalesTicket(Component):
    """ ConcreteComponet """

    def __init__(self, body_content_in):
        self.body_content = body_content_in

    def print_ticket(self):
        print "Content:\n", self.body_content


class SalesTicketDecorator(Component):
    """ Decorator """

    def __init__(self, sales_ticket_in):
        self.sales_ticket = sales_ticket_in

    def print_ticket(self):
        self.sales_ticket.print_ticket()


class AddHeader(SalesTicketDecorator):
    """ ConcreteDecoratorA """

    def __init__(self, sales_ticket_in, header_content_in):
        super(AddHeader, self).__init__(sales_ticket_in)
        self.header_content = header_content_in

    def print_header(self):
        print "Header:\n", self.header_content

    def print_ticket(self):
        self.print_header()
        self.sales_ticket.print_ticket()


class AddFooter(SalesTicketDecorator):
    """ ConcreteDecoratorB """

    def __init__(self, sales_ticket_in, footer_content_in):
        super(AddFooter, self).__init__(sales_ticket_in)
        self.footer_content = footer_content_in

    def print_footer(self):
        print "Footer:\n", self.footer_content

    def print_ticket(self):
        self.sales_ticket.print_ticket()
        self.print_footer()


if __name__ == "__main__":
    # init sales ticket
    print "--------------init sales ticket--------------------"
    new_sales_ticket = SalesTicket("I am body!")
    new_sales_ticket.print_ticket()
    print "---------------------------------------------------"

    print "------------sales ticket with header---------------"
    ST_with_header = AddHeader(new_sales_ticket, "I am header!")
    ST_with_header.print_ticket()
    print "---------------------------------------------------"

    print "-------sales ticket with header and footer---------"
    ST_with_header_and_footer = AddFooter(ST_with_header, "I am footer!")
    ST_with_header_and_footer.print_ticket()
    print "---------------------------------------------------"


