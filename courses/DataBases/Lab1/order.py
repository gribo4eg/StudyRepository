from file import Files

class Order:

    def __init__(self, id, products):
        self.id = id
        self.products = products

    def add_product(self, product):
        if product.id not in self.products:
            self.products.append(product.id)

    def delete_product(self, product):
        if product.id in self.products:
            self.products.remove(product.id)

    def __str__(self):
        res = "Order id = %s\n\tProducts:\n\t\t" % self.id
        productsList = Files.load_products()
        for p in self.products:
            prod = [item for item in productsList.products if str(item.id) == str(p)]
            if prod:
                res += prod[0].__str__() + "\n\t\t"
        return res


class Orders:

    def __init__(self):
        self.orders = list()

    def add(self, pids):
        allProducts = Files.load_products()
        products = []
        for pid in pids:
            prod = [item for item in allProducts.products if str(item.id) == str(pid)]
            if prod:
                products.append(pid)

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

    def add_product_to_order(self, order, product):
        order.add_product(product)

    def remove_product_from_order(self, order, product):
        order.delete_product(product)
        if order.products.__len__() == 0:
            self.orders.remove(order)
            return None
        else:
            return order

    def orders_with_spec_products(self):
        res = ""
        allProducts = Files.load_products()
        for order in self.orders:
            targets = [item for item in allProducts.products if str(item.id) in order.products and item.cost >= 100]
            if targets:
                res += "Order id: %s\n\t\t" % order.id
                for target in targets:
                    res += target.__str__() + "\n\t\t"

        if res == "": return None
        else: return res

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
                res += order.__str__() + '\n'
        else:
            res = "Can't find orders in db!"
        return res
