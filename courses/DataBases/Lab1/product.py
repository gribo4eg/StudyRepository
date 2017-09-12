class Product:
    def __init__(self, id, name, cost):
        self.id = id
        self.name = name
        self.cost = cost

    def __str__(self):
        return "Product: id = %d, name = %s, cost = %d" % (self.id, self.name, self.cost)


class Products:

    def __init__(self):
        self.products = list()

    def add(self, product):
        self.products.append(product)

    def delete(self, product):
        if product in self.products:
            self.products.remove(product)

    def __str__(self):
        res = ""
        for product in self.products:
            res += product.__str__() + "\n"
        return res
