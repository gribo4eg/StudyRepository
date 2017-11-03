using System;
using System.Threading;
using System.Collections.Generic;

namespace Lab2
{
    public class Zoo<T> 
        where T: IAnimal
    {

        static Zoo<T> instance = null;
        Watchman watchman = null;
        Centaur guardian = null;
        readonly string name;

        readonly LinkedList<T> animals;

        Zoo(string name)
        {
            this.name = name;
            animals = new LinkedList<T>();
        }

        public static Zoo<T> getInstance(string name)
        {
            if (instance == null)
                instance = new Zoo<T>(name);
            return instance;
        }

        public void addWatchman(Watchman w)
        {
            if (w.Name.Length < 2 || w.Name.Length > 10 || w.Age < 18 || w.IQ < 110)
            {
                throw new WatchmanException(w);
            }
            else
            {
                watchman = w;
                Console.WriteLine("In Zoo \"{0}\" new Watchman: {1}!", name, watchman.Name);
            }
        }

        public void addGuardian(Centaur c)
        {
            guardian = c;
        }

        public void staffTrain()
        {
            Console.WriteLine("Zoo staff begin training!");
            guardian.Training();
            watchman.Training();
            Thread.Sleep(2000);
            Console.WriteLine("After training: Watchman - {0} kg, Guardian - {1} kg", watchman.Weight, guardian.Weight);
        }

        public void staffBrain()
        {
            Console.WriteLine("Zoo staff begin brainstorm!");
            guardian.BrainStorm();
            watchman.BrainStorm();
            Thread.Sleep(2000);
            Console.WriteLine("After brainstorm: Watchman - {0} IQ, Guardian - {1} IQ", watchman.IQ, guardian.IQ);
        }

        public string Name
        {
            get{ return name; }
        }

        public int Count
        {
            get{ return animals.Count; }
        }

        public bool addAnimal(T animal)
        {
            if (watchman == null)
                throw new ZooException(watchman);
            else
            {
                watchman.WatchmanFeedingEvent += animal.Feed;
                animals.AddLast(animal);
                return true;
            }
        }

        public bool removeAnimal(T animal)
        {
            if (watchman == null)
                throw new ZooException(watchman);
            else
            {
                watchman.WatchmanFeedingEvent -= animal.Feed;
                return animals.Contains(animal) && animals.Remove(animal);
            }
        }

        public void Filter()
        {
            Dictionary<string, int> mytypes = new Dictionary<string, int>();

            foreach (T an in animals)
            {
                string type = an.GetType().ToString().Remove(0, 5);
                if (mytypes.ContainsKey(type))
                {
                    mytypes[type]++;
                }
                else
                {
                    mytypes[type] = 1;
                }

            }

            Console.WriteLine("In Zoo \"" + this.name + "\" now live:\n");

            foreach (string t in mytypes.Keys)
            {
                Console.WriteLine("{0} - {1}", t, mytypes[t]);
            }


                
        }
            
    }
}

