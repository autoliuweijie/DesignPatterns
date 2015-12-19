/*
    Example of  Decorator pattern.
    @author: Liu Weijie
    @data: 2015-12-19

    需求:
        设计一个给发票对象添加新功能的装饰器:
            所有发票都有打印正文的功能, 但是有些发票有表头或页脚.
*/
#include <iostream>


// VirtualComponent
class Component{

public:

    virtual void print_ticket()=0;
};


// ConcreteComponent
class SalesTicket: public Component{

public:

    SalesTicket(char* body_content_in){
        _body_content = body_content_in;
    }

    virtual void print_ticket(){
        std::cout << "Content:\n"<<_body_content<<"\n";

    }

private:

    char* _body_content;
};


// Decorator
class SalesTicketDecorator: public Component{

public:

    SalesTicketDecorator(Component* sales_ticket_in){
        _sales_ticket = sales_ticket_in;
    }

    virtual void print_ticket(){
        _sales_ticket->print_ticket();
    }

    virtual void set_sales_ticket(Component* sales_ticket_in){
        _sales_ticket = sales_ticket_in;
    }

    virtual Component* get_sales_ticket(){
        return _sales_ticket;
    }

private:

    Component* _sales_ticket;

};


// ConcreteDecoratorA
class AddHeader: public SalesTicketDecorator{

public:

    AddHeader(Component* sales_ticket_in, char* header_content_in): SalesTicketDecorator(sales_ticket_in){
        _header_content = header_content_in;
    };

    virtual void print_ticket(){
        _print_header();
        get_sales_ticket()->print_ticket();
    }

private:

    char* _header_content;

    virtual void _print_header(){
        std::cout << "Header:\n"<<_header_content<<"\n";
    }
};


// ConcreteDecoratorB
class AddFooter: public SalesTicketDecorator{

public:

    AddFooter(Component* sales_ticket_in, char* footer_content_in): SalesTicketDecorator(sales_ticket_in){
        _footer_content = footer_content_in;
    }

    virtual void print_ticket(){
        get_sales_ticket()->print_ticket();
        _print_footer_content();
    }
private:

    char* _footer_content;

    virtual void _print_footer_content(){
        std::cout << "Footer:\n"<<_footer_content<<"\n";
    }
};


int main(){
    // init sales ticket
    std::cout << "init sales ticket:"<<"\n"<<"--------------------"<<"\n";
    Component* new_sales_ticket = new SalesTicket("here is body...");
    new_sales_ticket->print_ticket();
    std::cout << "--------------------"<<"\n"<<"\n";

    // sales ticket with header
    std::cout << "sales ticket with header:"<<"\n"<<"--------------------"<<"\n";
    Component* ST_with_header = new AddHeader(new_sales_ticket, "here is header...");
    ST_with_header->print_ticket();
    std::cout << "--------------------"<<"\n"<<"\n";

    // sales ticket with footer
    std::cout << "sales ticket with header and footer:"<<"\n"<<"--------------------"<<"\n";
    Component* ST_with_header_and_footer = new AddFooter(ST_with_header, "here is footer...");
    ST_with_header_and_footer->print_ticket();
    std::cout << "--------------------"<<"\n"<<"\n";
    return 0;
}