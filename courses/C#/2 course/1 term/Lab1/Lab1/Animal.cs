using System;

namespace Lab1
{
    class Animal
    {
        protected string sound;
        protected string name;
        protected int age;

        protected static string habitat;
        protected static short countOfEyes;

        


        protected const int START_AGE = 1;

        //Simple constructor
        public Animal(){}

        //Override constructor
        public Animal(string name)
        {
            this.name = name;
        }

        //Static constructor to initialize static variables
        static Animal()
        {
            Console.WriteLine("Static constructor Animal: done!");
            habitat = "Europe";
            countOfEyes = 2;
        }

        //Properties
        public string Habitat
        {
            get{ return habitat; }
        }

        public short Eyes
        {
            get{ return countOfEyes; }
        }


        public int Age
        {
            get{ return age; }
            set
            {
                if (value >= 1 && value <= 20)
                    age = value;
            }
        }

        public string Name
        {
            get{ return name; }
            set
            {
                if (value.Length > 2 && value.Length < 10)
                    name = value;
            }
        }

        //Virtual method which is used by inheritors
        public virtual void makeSound()
        {
            Console.WriteLine("Animal make sound!");
        }
    }
}

