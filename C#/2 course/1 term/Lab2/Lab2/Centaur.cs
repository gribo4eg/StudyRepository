using System;

namespace Lab2
{
    public class Centaur:IHorse, IHuman
    {
        
        const int MIN_SPEED = 40;
        const int MAX_SPEED = 48;
        int speed;
        double iq;
        double weight;

        public Centaur(string name, int age)
        {
            Name = name;
            Age = age;
            speed = MIN_SPEED;
            iq = 125.0;
            weight = 200.0;
        }

        public string Name{ get; set;}
        public int Age{ get; set;}
        public double IQ{ get{ return iq; } }
        public double Weight{ get{ return weight; }}

        public void Run(int km)
        {
            Console.WriteLine("Centaur {0} begin to run with furious speed {1} km/h on distance {2} km", Name, speed, km);
        }

        public int Speed
        {
            get{ return speed; }
        }

        public void Training()
        {
            if (speed != MAX_SPEED)
                ++speed;
            iq -= 0.3;
            weight -= 0.08;
        }

        public void BrainStorm()
        {
            iq++;
            weight += 0.1;
        }
            
    }
}

