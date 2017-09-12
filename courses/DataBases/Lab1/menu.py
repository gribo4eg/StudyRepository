import pickle


class Menu:

    """def __init__(self, products, orders):
        self.products = products
        self.orders = orders
"""
    def start(self):

        products = self.load_products()
        orders = self.load_orders()

        while True:
            choice = input(self.show_menu() + "\n\n>>>\t")

            if choice == '1':
                print(products)
            elif choice == '2':
                pass
            elif choice == '9':
                break

        self.save_products(products)
        self.save_orders(orders)

    def show_menu(self):
        with open('menu.txt', 'r') as m:
            menu = m.read()
        return menu

    def load_products(self):
        with open('products.db', 'rb') as p:
            products = pickle.load(p)
        return products

    def load_orders(self):
        with open('orders.db', 'rb') as o:
            orders = pickle.load(o)
        return orders

    def save_products(self, products):
        with open('products.db', 'wb') as p:
            pickle.dump(products, p)

    def save_orders(self, orders):
        with open('orders.db', 'wb') as o:
            pickle.dump(orders, o)
