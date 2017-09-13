class Product:
    def __init__(self, id, name, cost):
        self.id = id
        self.name = name
        self.cost = cost

    def __str__(self):
        return "Product: id = %s, name = %s, cost = %.2f" % (self.id, self.name, self.cost)


class Products:
    def __init__(self):
        self.products = list()

    def add(self, name, cost):
        for i in range(1, self.products.__len__() + 2):
            if not any(str(item.id) == str(i) for item in self.products):
                product = Product(str(i), name, cost)
                self.products.append(product)
                return product

    def update(self, pid, newName, newCost):
        product = self.get_product_by_id(pid)
        if product is not None:
            product.name = newName
            product.cost = newCost
        return product

    def get_product_by_id(self, pid):
        product = [item for item in self.products if str(item.id) == str(pid)]
        if product:
            return product[0]
        else:
            return None

    def delete(self, pid):
        delete = [item for item in self.products if str(item.id) == str(pid)]
        if delete:
            self.products.remove(delete[0])
            return delete[0]
        else:
            return None

    def __str__(self):
        res = ""
        if self.products:
            for product in self.products:
                res += product.__str__() + "\n"
        else:
            res = "Can't find products in db"
        return res
