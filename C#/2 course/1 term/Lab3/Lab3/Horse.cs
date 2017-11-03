using System;
using System.Runtime.Serialization;

namespace Lab3
{
    class Horse: Animal, IAnimal, IHorse, IDisposable
    {
        const string HORSE_SOUND = "NEIGH";
        const int SPEED = 40;

        public Horse()
        {
            sound = HORSE_SOUND;
            age = START_AGE;
            Speed = SPEED;
            food = FoodType.Grass;
        }

        public Horse(string name)
            :this()
        {
            this.name = name;
        }

        public Horse(string name, int age)
            :this(name)
        {
            this.age = age;
        }

        //Run Training

        [DataMember]
        public int Speed { get; }

        public override FoodType Food
        {
            get{return food;}
            set{
                if (value.Equals(FoodType.Grass))
                {
                    food = value;
                }
            }
        }

        public override void MakeSound()
        {
            base.MakeSound();
            Console.WriteLine("Horse says " + sound);
        }

        public void Feed(Watchman w)
        {
            Console.WriteLine("Horse " + this.name + " was feeded by" +
                " watchman " + w.Name);
        }

        ~Horse()
        {
            Console.WriteLine("~Horse()");
            Dispose();
        }
    }
}

