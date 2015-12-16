/*
    For facade pattern.
    @author: Liu Weijie
    @date: 2015-12-16
*/
#include <iostream>


// Strategy1
class CalcTax{
public:
    virtual void calc_tax()=0;
};


// Strategy1_A
class USTax: public CalcTax{
public:
    virtual void calc_tax(){
        std::cout << "calculate tax in US!\n";
    }
};


// Strategy1_B
class CanTax: public CalcTax{
public:
    virtual void calc_tax(){
        std::cout << "calculate tax in Canada!\n";
    }
};


// Strategy2
class Pay{
public:
    virtual void pay_money()=0;
};


// Strategy2_A
class AliPay: public Pay{
public:
    virtual void pay_money(){
        std::cout << "pay money by AliPay\n";
    }
};


// Strategy2_B
class WeixinPay: public Pay{
public:
    virtual void pay_money(){
        std::cout << "pay money by WeixinPay\n";
    }
};


// Context
class SalesOrder{
private:
    CalcTax* calc_tax_way;
    Pay* pay_way;

public:
    SalesOrder(CalcTax* calc_tax_in, Pay* pay_way_in){
        calc_tax_way = calc_tax_in;
        pay_way = pay_way_in;
    }

    void calc_tax(){
        calc_tax_way->calc_tax();
    }

    void pay_money(){
        pay_way->pay_money();
    }

};

int main(int argc, const char * argv[]) {

    SalesOrder* new_salesorder = new SalesOrder(new USTax(), new WeixinPay());
    new_salesorder->calc_tax();
    new_salesorder->pay_money();
    return 0;
}




































