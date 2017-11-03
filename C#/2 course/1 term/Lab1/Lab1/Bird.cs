using System;

namespace Lab1
{
    class Bird : Animal
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
            base.makeSound();
            Console.WriteLine("Bird says " + sound);
        }
    }
}

