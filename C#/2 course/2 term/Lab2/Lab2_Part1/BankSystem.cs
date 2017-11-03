using System;
using System.Collections.Generic;

namespace Lab2_Part1
{
    public enum ServicePackage
    {
        NoPackage, Bottom, Middle, Top
    }

    interface IBankSystem
    {
        void AddClient(Client client);
        void RemoveCLient(Client client);
        void SetPackageToClient(Client client, ServicePackage package);
        void GetAccountReport(Client client);
    }

    public class Bank : IBankSystem
    {
        private readonly List<Client> _clients;
        private string Name { get; set; }

        public Bank(string name)
        {
            Name = name;
            _clients = new List<Client>();
        }

        public void GetAccountReport(Client client)
        {
            Console.WriteLine("HI! My name is {0} and this is my "+
                              "favorite bank {1}", client.Name, Name);
        }

        public void SetPackageToClient(Client client, ServicePackage package)
        {
            if(!_clients.Contains(client)) return;
            client.Package = package;
        }

        public void AddClient(Client client)
        {
            if (_clients.Contains(client)) return;
            _clients.Add(client);
            client.Package = ServicePackage.Bottom;
        }

        public void RemoveCLient(Client client)
        {
            if (!_clients.Contains(client)) return;
            client.Package = ServicePackage.NoPackage;
            _clients.Remove(client);
        }
    }

    public class ProxyBank : IBankSystem
    {
        private readonly Bank _bank;

        public ProxyBank(string name)
        {
            _bank = new Bank(name);
        }

        public void GetAccountReport(Client client)
        {
            if (client.Package.Equals(ServicePackage.Top))
            {
                _bank.GetAccountReport(client);
                Console.WriteLine("Your account contains {0} service package "+
                                  "You are more powerfull then others, {1}", client.Package, client.Name);
            }
            else if (client.Package.Equals(ServicePackage.Middle)
                     || client.Package.Equals(ServicePackage.Bottom))
            {
                _bank.GetAccountReport(client);
                Console.WriteLine("{0}, You have {1} service package, you can check some operations "+
                                  "but not all of them", client.Name, client.Package);
            }
            else
            {
                Console.WriteLine("You have no permission to this function, {0}", client.Name);
            }
        }

        public void AddClient(Client client)
        {
            this._bank.AddClient(client);
        }

        public void RemoveCLient(Client client)
        {
            _bank.RemoveCLient(client);
        }

        public void SetPackageToClient(Client client, ServicePackage package)
        {
            _bank.SetPackageToClient(client, package);
        }
    }

}