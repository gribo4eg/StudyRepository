using System;

namespace Lab2
{
    public delegate void Feeding(Watchman w);

    public class Watchman:IHuman 
    {
        public event Feeding WatchmanFeedingEvent;
        double iq;
        double weight;

        public Watchman(string name, int age)
        {
            Name = name;
            Age = age;
            iq = 100.0;
            weight = 73.4;
        }

        public double IQ{get {return iq;}}

        public double Weight{get{ return weight; }}

        public void BrainStorm()
        {
            iq += 0.8;
            weight += 0.3;
        }

        public void Training()
        {
            weight -= 0.3;
            iq -= 0.4;
        }

        public string Name
        {get;set;}

        public int Age
        {get;set;}

        public void Feeding()
        {
            Console.WriteLine("Watchman "+ this.Name + " is going to " +
                "feed animals!");
            if (WatchmanFeedingEvent != null)
                WatchmanFeedingEvent(this);
        }

    }
        
}

