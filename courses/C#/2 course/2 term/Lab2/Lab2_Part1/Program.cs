using System;
using System.Collections.Generic;

namespace Lab2_Part1
{
    public class Client
    {
        public string Name { get; set; }
        public ServicePackage Package { get; set; }

        public Client(string name)
        {
            Name = name;
            Package = ServicePackage.NoPackage;
        }
    }

    internal class Program
    {
        public static void Main(string[] args)
        {
            ProxyBank bank = new ProxyBank("I. Am. BANK!");
            Client bob = new Client("Bob");
            Client max = new Client("Max");
            Client fred = new Client("Fred");

            bank.AddClient(bob);
            bank.AddClient(max);
            bank.SetPackageToClient(max, ServicePackage.Top);
            bank.AddClient(fred);

            bank.GetAccountReport(bob);
            bank.GetAccountReport(max);
            bank.GetAccountReport(fred);

            bank.RemoveCLient(fred);

            bank.GetAccountReport(fred);
        }
    }
}