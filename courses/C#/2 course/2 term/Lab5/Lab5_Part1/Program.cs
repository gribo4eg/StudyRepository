using System;
using System.Collections.Generic;

namespace Lab5_Part1
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Handler group1 = new FirstChange();
            Handler group2 = new SecondChange();
            Handler group3 = new ThirdChange();

            group1.Successor = group2;
            group2.Successor = group3;
            group3.Successor = group1;

            group1.DoWork(13, "work on 13 hours");

            group1.DoWork(14.29, "work on 14.29 ");

            group3.DoWork(7, "work on 7");
        }
    }
}