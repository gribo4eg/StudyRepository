import pickle

class Files:
    @staticmethod
    def load_products():
        with open('./db/products.db', 'rb') as p:
            products = pickle.load(p)
        return products

    @staticmethod
    def load_orders():
        with open('./db/orders.db', 'rb') as o:
            orders = pickle.load(o)
        return orders

    @staticmethod
    def save_products(products):
        with open('./db/products.db', 'wb') as p:
            pickle.dump(products, p)

    @staticmethod
    def save_orders(orders):
        with open('./db/orders.db', 'wb') as o:
            pickle.dump(orders, o)