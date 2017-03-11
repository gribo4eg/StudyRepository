using System;

namespace Lab3
{
    public interface IHuman
    {
        //double Iq{ get; }
        //double Weight{ get; }
        FoodType Food { get; set; }
        void FeedAnimalsInZoo();
    }
}

