using System;

namespace Lab2
{
    class Horse: Animal, IAnimal, IHorse
    {
        const string HORSE_SOUND = "NEIGH";
        const int MIN_SPEED = 40;
        const int MAX_SPEED = 48;
        private int speed;

        public Horse()
        {
            sound = HORSE_SOUND;
            age = START_AGE;
            speed = MIN_SPEED;
        }

        public Horse(string name)
            :this()
        {
            this.name = name;
        }

        public void Run(int km)
        {
            Console.WriteLine("Horse {0} began to run with furious speed {1} km/h on distance {2} km", name, speed, km);
        }

        public int Speed
        {
            get{ return speed; }
        }

        public void Training()
        {
            if (speed != MAX_SPEED)
                ++speed;
        }

        public override void makeSound()
        {
            base.makeSound();
            Console.WriteLine("Horse says " + sound);
        }

        public void Feed(Watchman w)
        {
            Console.WriteLine("Horse " + this.name + " was feeded by" +
                " watchman " + w.Name);
        }
    }
}

