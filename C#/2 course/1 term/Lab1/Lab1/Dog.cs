using System;

namespace Lab1
{
    class Dog : Animal
    {
        //private const variable which used only in this class
        private const string DOG_SOUND = "WOOF";

        public Dog()
        {
            sound = DOG_SOUND;
            age = START_AGE;
        }

        public Dog(string name)
            :this()
        {
            this.name = name;
        }

        public void sleep()
        {
            Console.WriteLine("Dog sleeps");
        }

        public override void makeSound()
        {
            base.makeSound();
            Console.WriteLine("Dog says " + sound);
        }
    }
}

