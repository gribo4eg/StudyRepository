from file import Files

class Menu:

    def start(self):

        products = Files.load_products()
        orders = Files.load_orders()

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
                product = products.get_product_by_id(pid)
                self.print_if_not_none(product)
                if product is not None:
                    try:
                        newName = input("New name(Old: %s) = " % product.name)
                        newCost = float(input("New cost(Old: %f) = " % product.cost))

                        product = products.update(pid, newName, newCost)

                        self.print_if_not_none(product)

                    except ValueError:
                        print("Bad value!")

            elif choice == '4':

                pid = input("\nWhich one?(id)\n>>> ")
                product = products.delete(pid)
                self.print_if_not_none(product)

            elif choice == '5':

                print(orders)

            elif choice == '6':

                pids = str(input("\nWhich products include to order?(write their id in format:"
                                 " id1;id2;id3;...;idN)\n>>> "))
                idlist = pids.split(sep=';')
                plist = []
                for s in idlist:
                    plist.append(s.replace(' ', ''))

                if plist:
                    order = orders.add(plist)
                    self.print_if_not_none(order)
                else:
                    print("You can't create order without products!")

            elif choice == '7':

                orderId = input("Which order do you want to update?(id): ")
                order = orders.get_order_by_id(orderId)
                if order is not None:
                    productId = input("Which product do you want to add?(id): ")
                    product = products.get_product_by_id(productId)

                    if product is not None:
                        orders.add_product_to_order(order, product)
                        self.print_if_not_none(order)
                    else:
                        print("No such product in db!")
                else:
                    print("No such order in db")

            elif choice == '8':

                orderId = input("Which order do you want to update?(id): ")
                order = orders.get_order_by_id(orderId)
                if order is not None:
                    productId = input("Which product do you want to remove?(id): ")
                    product = products.get_product_by_id(productId)

                    if product is not None:
                        order = orders.remove_product_from_order(order, product)
                        if order is not None:
                            print(order)
                        else:
                            print("Order was deleted!")
                    else:
                        print("No such product in db!")
                else:
                    print("No such order in db!")

            elif choice == '9':

                print("Result:\n\t")
                print(orders.orders_with_spec_products())

            elif choice == '10':

                oid = input("\nWhich one?(id)\n>>> ")
                order = orders.delete(oid)
                self.print_if_not_none(order)

            elif choice == 'q':
                break

            Files.save_products(products)
            Files.save_orders(orders)

    def print_if_not_none(self, obj):
        if obj is not None:
            print(obj)
        else:
            print("No such Object in db!")

    def show_menu(self):
        with open('./db/menu.txt', 'r') as m:
            menu = m.read()
        return menu