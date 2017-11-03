using System;

namespace Lab2
{
    class Fox : Animal, IAnimal
    {

        private const string FOX_SOUND = "Hatee-hatee-hatee-ho!";

        public Fox()
        {
            sound = FOX_SOUND;
            age = START_AGE;
        }

        public Fox(string name)
            :this()
        {
            this.name = name;
        }


        public override void makeSound()
        {
            base.makeSound();
            Console.WriteLine("Fox says " + sound);
        }

        public void Feed(Watchman w)
        {
            Console.WriteLine("Fox " + this.name + " was feeded by" +
                " watchman " + w.Name);
        }
    }
}

