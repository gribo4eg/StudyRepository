import pickle


class Order:

    def __init__(self, id, products):
        self.id = id
        self.products = products

    def add_product(self, product):
        self.products.add(product)

    def delete_product(self, product):
        self.products.delete(product)

    def __str__(self):
        res = "Order id = %s\n\tProducts:\n\t\t" % self.id
        for p in self.products:
            res += p.__str__() + "\n\t\t"
        return res


class Orders:

    def __init__(self):
        self.orders = list()

    def add(self, pids):
        with open('./db/products.db', 'rb') as p:
            allProducts = pickle.load(p)
        products = []
        for pid in pids:
            prod = [item for item in allProducts.products if str(item.id) == str(pid)]
            if prod:
                products.append(prod[0])

        for i in range(1, self.orders.__len__() + 2):
            if not any(str(item.id) == str(i) for item in self.orders):
                order = Order(str(i), products)
                self.orders.append(order)
                return order

    def delete(self, oid):
        order = self.get_order_by_id(oid)
        if order is not None:
            self.orders.remove(order)
            return order
        else:
            return None

    def get_order_by_id(self, oid):
        order = [order for order in self.orders if str(order.id) == str(oid)]
        if order:
            return order[0]
        else:
            return None

    def __str__(self):
        res = ""
        if self.orders:
            for order in self.orders:
                res += "Order: id = %s\n" % order.id
        else:
            res = "Can't find orders in db!"
        return res
