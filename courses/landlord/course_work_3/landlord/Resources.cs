using System.ComponentModel;
using GalaSoft.MvvmLight;

namespace landlord
{
    public abstract class Resources
    {
        public string Name { get; set; }
        public int Count { get; set; }

        protected Resources()
        {
            Name = GetType().Name;
            Count = 1000;
        }
    }

    public class Wood : Resources {}

    public class Food : Resources {}

    public class Gold : Resources {}
}