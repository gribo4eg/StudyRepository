using System;
using System.Runtime.Serialization;

namespace Lab3
{
    [DataContract]
    class Bird : Animal, IAnimal, IDisposable
    {

        private const string BIRD_SOUND = "TWEET";



        public Bird()
        {
            sound = BIRD_SOUND;
            age = START_AGE;
            food = FoodType.Grass;
        }

        public Bird(string name)
            :this()
        {
            this.name = name;
        }

        public Bird(string name, int age)
            :this(name)
        {
            this.age = age;

        }

        public Bird(string name, int age, string sound)
            :this(name, age)
        {
            this.sound = sound;
        }

        public Bird(string name, string sound)
            :this(name)
        {
            this.sound = sound;
        }

        [DataMember]
        public override FoodType Food
        {
            get { return food; }
            set
            {
                if (value.Equals(FoodType.Grass)) food = value;
            }
        }

        [DataMember]
        public string Sound
        {
            get{ return sound; }
            set
            {
                if (value.Length > 2 && value.Length <= 10)
                    sound = value;
            }
        }

        public override void MakeSound()
        {
            Console.WriteLine("Bird says " + sound);
        }

        public void Feed(Watchman w)
        {
            Console.WriteLine("Bird " + this.name + " was feeded by" +
                " watchman " + w.Name);
        }

        ~Bird()
        {
            Console.WriteLine("~Bird()");
            Dispose(false);
        }
    }
}

