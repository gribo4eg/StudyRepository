using System;
using System.Collections.Generic;

namespace Lab1
{
    class Zoo
    {
        static Zoo instance = null;
        readonly string name;

        readonly LinkedList<Animal> animals;

        Zoo(string name)
        {
            this.name = name;
            animals = new LinkedList<Animal>();
        }

        public static Zoo getInstance(string name)
        {
            if (instance == null)
                instance = new Zoo(name);
            return instance;
        }

        public string Name
        {
            get{ return name; }
        }

        public int Count
        {
            get{ return animals.Count; }
        }

        public bool addAnimal(Animal animal)
        {
            if (animal == null)
                return false;

            animals.AddLast(animal);
            return true;
        }

        public bool removeAnimal(Animal animal)
        {
            if (animal == null)
                return false;

            return animals.Contains(animal) && animals.Remove(animal);

        }

        public void feedAnimals()
        {
            Console.WriteLine("Yeehaw! FeelsGoodMan");
        }
    }
}

