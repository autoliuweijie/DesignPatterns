# coding: utf-8
"""
    Example of Strategy pattern.
    @author: Liu Weijie
    @data: 2015-12-17

    需求:
        设计一个订单类, 既可以计算美国税或加拿大税, 也可以用微信或者阿里支付.
"""

class CalcTax(object):
    ''' Strategy1 '''

    def calc_tax(self):
        pass


class USTax(CalcTax):
    ''' Strategy1_A '''

    def calc_tax(self):
        print "calc tax in US!\n"


class CanTax(CalcTax):
    ''' Strategy1_B '''

    def calc_tax(self):
        print "calc tax in Canada!\n"


class Pay(object):
    ''' Strategy2 '''

    def pay_money(self):
        pass


class AliPay(Pay):
    ''' Strategy2_A '''

    def pay_money(self):
        print "pay in AliPay!\n"


class WeixinPay(Pay):
    ''' Strategy2_B '''

    def pay_money(self):
        print "pay in WeixinPay!\n"


class SalesOrder(object):
    ''' Context '''

    PAY_WAY = {
        "AliPay": AliPay(),
        "WeixinPay": WeixinPay(),
    }

    TAX_WAY = {
        'USTax': USTax(),
        'CanTax': CanTax(),
    }

    def __init__(self, pay_way_in="AliPay", tax_way_in="USTax"):
        self.pay_way = self.PAY_WAY[pay_way_in]
        self.tax_way = self.TAX_WAY[tax_way_in]

    def calc_tax(self):
        self.tax_way.calc_tax()

    def pay_money(self):
        self.pay_way.pay_money()


if __name__ == "__main__":
    new_salesorder = SalesOrder(pay_way_in="AliPay", tax_way_in="CanTax")
    new_salesorder.calc_tax()
    new_salesorder.pay_money()
























