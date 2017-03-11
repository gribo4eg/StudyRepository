using System;

namespace Lab2
{
    class Bird : Animal, IAnimal
    {

        private const string BIRD_SOUND = "TWEET";



        public Bird()
        {
            sound = BIRD_SOUND;
            age = START_AGE;
        }

        public Bird(string name)
            :this()
        {
            this.name = name;
        }

        public Bird(string name, string sound)
            :this(name)
        {
            this.sound = sound;
        }


        public string Sound
        {
            get{ return sound; }
            set
            {
                if (value.Length > 2 && value.Length <= 10)
                    sound = value;
            }
        }

        public override void makeSound()
        {
            Console.WriteLine("Bird says " + sound);
        }

        public void Feed(Watchman w)
        {
            Console.WriteLine("Bird " + this.name + " was feeded by" +
                " watchman " + w.Name);
        }
    }
}

