using System;
using System.Runtime.Serialization;

namespace Lab3
{
    [DataContract]
    class Cat : Animal, IAnimal, IDisposable
    {

        private const string CAT_SOUND = "MEOW";

        public Cat()
        {
            sound = CAT_SOUND;
            age = START_AGE;
            food = FoodType.All;
        }

        public Cat(string name)
            :this()
        {
            this.name = name;
        }

        public Cat(string name, int age)
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

        //jumpOnTable

        public override void MakeSound()
        {
            base.MakeSound();
            Console.WriteLine("Cat says " + sound);
        }

        public void Feed(Watchman w)
        {
            Console.WriteLine("Cat " + this.name + " was feeded by" +
                " watchman " + w.Name);
        }



        ~Cat()
        {
            Console.WriteLine("~Cat()");
            Dispose();
        }
    }
}

