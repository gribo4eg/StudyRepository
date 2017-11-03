using System;
using System.Runtime.Serialization;

namespace Lab3
{
    [DataContract]
    class Dog : Animal, IAnimal, IDisposable
    {
        //private const variable which used only in this class
        private const string DOG_SOUND = "WOOF";

        public Dog()
        {
            sound = DOG_SOUND;
            age = START_AGE;
            food = FoodType.All;
        }

        public Dog(string name)
            :this()
        {
            this.name = name;
        }

        public Dog(string name, int age)
            :this(name)
        {
            this.age = age;
        }

        public override FoodType Food
        {
            get { return food; }
            set
            {
                if (value.Equals(FoodType.All)) food = value;
            }
        }

       //sleep

        public override void MakeSound()
        {
            base.MakeSound();
            Console.WriteLine("Dog says " + sound);
        }

        public void Feed(Watchman w)
        {
            Console.WriteLine( "Dog " + this.name + " was feeded by" +
                " watchman " + w.Name);
        }

        ~Dog()
        {
            Console.WriteLine("~Dog()");
            Dispose();
        }
    }
}

