using System;

namespace Lab2
{
    abstract class Animal
    {
        
        protected string sound;
        protected string name;
        protected int age;

        protected const int START_AGE = 1;

        //Simple constructor
        protected Animal(){}

        //Override constructor
        protected Animal(string name)
        {
            this.name = name;
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

