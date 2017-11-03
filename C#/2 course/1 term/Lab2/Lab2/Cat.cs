using System;

namespace Lab2
{
    class Cat : Animal, IAnimal
    {

        private const string CAT_SOUND = "MEOW";

        public Cat()
        {
            sound = CAT_SOUND;
            age = START_AGE;
        }

        public Cat(string name)
            :this()
        {
            this.name = name;
        }

        public void jumpOnTable()
        {
            Console.WriteLine("Cat jumped on the table!");
        }

        public override void makeSound()
        {
            base.makeSound();
            Console.WriteLine("Cat says " + sound);
        }

        public void Feed(Watchman w)
        {
            Console.WriteLine("Cat " + this.name + " was feeded by" +
                " watchman " + w.Name);
        }
    }
}

