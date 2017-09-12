from product import Products


class Order(object):

    def __init__(self, id, products):
        self.id = id
        self.products = products

    def __str__(self):
        return "Order id = %d\n\tProducts:\n\t\t%s" % (self.id, self.products.__str__())
