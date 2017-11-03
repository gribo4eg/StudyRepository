using System;
using System.Collections.Generic;

//TODO Single ton, make a ZOO with private constructor 

namespace Lab1
{
    class MainClass
    {
        public static void Main()
        {
            
            List<Animal> animals = new List<Animal>();

            animals.Add(new Dog());
            animals.Add(new Cat());
            animals.Add(new Bird());
            animals.Add(new Fox());

            foreach (var a in animals)
                a.makeSound();
            


            Bird bird = new Bird("Kitchi", "KAR KAR");
            Console.WriteLine(bird.Habitat);


            Dog dog = new Dog("Spike");
            Console.WriteLine(dog.Habitat);
            dog.makeSound();
            dog.sleep();

            Console.WriteLine(bird.Name);
            bird.makeSound();
            bird.Sound = "MEOW";
            bird.makeSound();

            Zoo zoo = Zoo.getInstance("zoo");

            Console.WriteLine(zoo.Name);

            zoo.addAnimal(bird);
            Console.WriteLine(zoo.Count);
            Console.WriteLine(zoo.removeAnimal(bird));
            Console.WriteLine(zoo.Count);

        }
    }
}
