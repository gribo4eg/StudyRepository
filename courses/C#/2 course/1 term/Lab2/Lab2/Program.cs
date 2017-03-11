using System;
using System.Threading;

namespace Lab2
{
    class MainClass
    {
        public static void Main()
        {
            var bird1 = new Bird("Chiki");
            var dog1 = new Dog("Spike");
            int age;
            string name;
            Watchman watchman;

            Console.WriteLine("Input watchman name:");
            name = Console.ReadLine();
            Console.WriteLine("Input watchman age:");
            age = Int32.Parse(Console.ReadLine());
            Centaur centaur = new Centaur("Heran", 112);

            watchman = new Watchman(name, age);

            Zoo<IAnimal> zoo = Zoo<IAnimal>.getInstance("ZOO");
            zoo.addGuardian(centaur);

            try
            {
                zoo.addAnimal(bird1);
            }
            catch(ZooException ex)
            {
                ZooExceptionMessage(ex);
            }



            while (true)
            {
                try
                {
                    zoo.addWatchman(watchman);
                    break;
                }
                catch (WatchmanException ex)
                {
                    WatchmanExceptionMessage(ex);
                }
                finally
                {
                    if (watchman.Name.Length < 2 || watchman.Name.Length > 10)
                    {
                        Console.WriteLine("Input watchman new name:");
                        watchman.Name = Console.ReadLine();
                    }
                    else if (watchman.Age < 18)
                    {
                        Console.WriteLine("Input watchman new age:");
                        watchman.Age = Int32.Parse(Console.ReadLine());
                    }
                    else if (watchman.IQ < 110)
                    {
                        Console.WriteLine("Hey, make BrainStorm");
                        Console.WriteLine("**********************");
                        while (watchman.IQ < 110)
                        {
                            watchman.BrainStorm();
                            Console.WriteLine("Now watchmans IQ is {0}!\n//Press any key to continue ", watchman.IQ);
                            Console.ReadKey();
                        }
                        Console.WriteLine("**Now watcher is clever, mb...********\n\n");
                    }
                }
            }

            Horse horse1 = new Horse("Sara");
            Horse horse2 = new Horse("Johny");

            try
            {
                zoo.addAnimal(horse1);
                zoo.addAnimal(horse2);
                zoo.addAnimal(bird1);
                zoo.addAnimal(dog1);
            }
            catch(ZooException ex)
            {
                ZooExceptionMessage(ex);
            }

            zoo.Filter();

            Console.WriteLine("***********EVENT**********");
            watchman.Feeding();
            Console.WriteLine("**************************\n\n");

            zoo.staffBrain();
            zoo.staffTrain();
        }

        static void WatchmanExceptionMessage(WatchmanException ex)
        {
            Console.WriteLine("********************************");
            Console.WriteLine("ERROR: {0}", ex.info());
            Console.WriteLine("********************************\n\n");
        }

        static void ZooExceptionMessage(ZooException ex)
        {
            Console.WriteLine("********************************");
            Console.WriteLine("ERROR: {0}", ex.info());
            Console.WriteLine("********************************\n\n");
        }

    }
}
