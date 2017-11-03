using System;

namespace Lab1
{
    class Fox : Animal
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
    }
}

