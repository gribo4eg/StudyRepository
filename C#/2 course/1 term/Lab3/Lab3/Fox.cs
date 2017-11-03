using System;
using System.Runtime.Serialization;

namespace Lab3
{
    [DataContract]
    class Fox : Animal, IAnimal, IDisposable
    {

        private const string FOX_SOUND = "Hatee-hatee-hatee-ho!";

        public Fox()
        {
            sound = FOX_SOUND;
            age = START_AGE;
            food = FoodType.Meat;
        }

        public Fox(string name)
            :this()
        {
            this.name = name;
        }

        public Fox(string name, int age)
            :this(name)
        {
            this.age = age;
        }

        public override FoodType Food
        {
            get { return food; }
            set
            {
                if (value.Equals(FoodType.Meat)) food = value;
            }
        }

        public override void MakeSound()
        {
            base.MakeSound();
            Console.WriteLine("Fox says " + sound);
        }

        public void Feed(Watchman w)
        {
            Console.WriteLine("Fox " + this.name + " was feeded by" +
                " watchman " + w.Name);
        }

        ~Fox()
        {
            Console.WriteLine("~Fox()");
            Dispose();
        }
    }
}

