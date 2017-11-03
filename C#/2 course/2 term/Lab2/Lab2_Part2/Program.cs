using System;
using System.Collections.Generic;

namespace Lab2_Part2
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            var system = new NewRegistrationSystem();

            system.AddUser("Alexander", "Bor", "Grib",
                "kulebyaka228", "mykeyword");

            system.AddUser("Yusuf", "ElConstantin", "DieHard",
                "hardpie", "YusufKeyword");

            system.UserInfo("Grib");
            system.UserInfo("DieHard");

            system.GetUser("Grib").Age = 18;
            system.GetUser("Grib").City = "SomeCity";

            system.UserInfo("Grib");
        }
    }
}