import pickle
from order import Order, Orders
from product import Product, Products


class Menu:

    def start(self):

        products = self.load_products()
        orders = self.load_orders()

        while True:
            choice = input('\n'+self.show_menu() + "\n\n>>>\t")

            if choice == '1':
                print(products)

            elif choice == '2':
                try:
                    name = input("\nProduct name = ")
                    cost = float(input("Product cost = "))

                    product = products.add(name, cost)
                    print(product)
                except ValueError:
                    print("Bad value!")

            elif choice == '3':
                pid = input("\nWhich one?(id)\n>>> ")
                product = products.delete(pid)
                self.print_if_not_none(product)

            elif choice == '4':
                print(orders)

            elif choice == '5':
                oid = input("\nWhich one?(id)\n>>> ")
                order = orders.get_order_by_id(oid)
                self.print_if_not_none(order)

            elif choice == '6':
                pids = str(input("\nWhich products include to order?(write their id in format:"
                                 " id1;id2;id3;...;idN)\n>>> "))
                idlist = pids.split(sep=';')
                plist = []
                for s in idlist:
                    plist.append(s.replace(' ', ''))

                order = orders.add(plist)
                print(order)

            elif choice == '7':
                #todo: add product to order
                pass

            elif choice == '8':
                #todo: remove product from order
                #todo: add checking for 0 products in order, if TRUE - delete this order
                pass

            elif choice == '10':
                #todo: Find products in orders with cost more then 100
                pass

            elif choice == '11':
                oid = input("\nWhich one?(id)\n>>> ")
                order = orders.delete(oid)
                self.print_if_not_none(order)

            elif choice == '9':
                break

            self.save_products(products)
            self.save_orders(orders)

    def print_if_not_none(self, obj):
        if obj is not None:
            print(obj)
        else:
            print("No such Object in db!")

    def show_menu(self):
        with open('./db/menu.txt', 'r') as m:
            menu = m.read()
        return menu

    def load_products(self):
        with open('./db/products.db', 'rb') as p:
            products = pickle.load(p)
        return products

    def load_orders(self):
        with open('./db/orders.db', 'rb') as o:
            orders = pickle.load(o)
        return orders

    def save_products(self, products):
        with open('./db/products.db', 'wb') as p:
            pickle.dump(products, p)

    def save_orders(self, orders):
        with open('./db/orders.db', 'wb') as o:
            pickle.dump(orders, o)
