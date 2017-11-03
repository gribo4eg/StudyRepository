using System;
using System.Collections.Generic;

namespace Lab3
{
    public class Zoo<T>:IDisposable
        where T: IAnimal
    {

        private bool _dispose;

        private static Zoo<T> _instance = null;
        private Watchman _watchman = null;

        private LinkedList<T> _animals;

        private Zoo(string name)
        {
            _dispose = false;
            Name = name;
            _animals = new LinkedList<T>();
        }

        public static Zoo<T> GetInstance(string name)
        {
            if (_instance == null)
                _instance = new Zoo<T>(name);
            return _instance;
        }

        public string Name { get; private set; }

        public int Count => _animals.Count;

        public void AddWatcherInZoo(Watchman newWatchman)
        {
            if (WatchmanIsNotValid(newWatchman))
            {
                throw new WatchmanException(newWatchman);
            }
            else
            {
                _watchman = newWatchman;
            }
        }

        private static bool WatchmanIsNotValid(Watchman watchman)
        {
            return (watchman.Name.Length < 2 || watchman.Name.Length > 20); //|| watchman.Age < 18);
        }


        public bool AddAnimalInZoo(T animal)
        {
            if (NoWatchman())
                throw new ZooException(_watchman);
            else
            {
                SubscribeOnFeeding(animal);
                _animals.AddLast(animal);
                return true;
            }
        }

        public bool RemoveAnimalFromZoo(T animal)
        {
            if (NoWatchman())
                throw new ZooException(_watchman);
            else
            {
                UnsubscribeFromFeeding(animal);
                return _animals.Contains(animal) && _animals.Remove(animal);
            }
        }

        private void SubscribeOnFeeding(IAnimal animal)
        {
            _watchman.WatchmanFeedingEvent += animal.Feed;
        }

        private void UnsubscribeFromFeeding(IAnimal animal)
        {
            _watchman.WatchmanFeedingEvent -= animal.Feed;
        }

        public bool NoWatchman()
        {
            return _watchman == null;
        }

        public void Filter()
        {
            Dictionary<string, int> mytypes = new Dictionary<string, int>();

            foreach (T an in _animals)
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

            Console.WriteLine("In Zoo \"" + this.Name + "\" now live:\n");

            foreach (string t in mytypes.Keys)
            {
                Console.WriteLine("{0} - {1}", t, mytypes[t]);
            }
        }


        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        protected void Dispose(bool disposing)
        {
            if (!_dispose)
            {
                if (disposing)
                {
                    Name = null;

                    if (_animals != null)
                    {
                        foreach (var animal in _animals)
                            animal?.Dispose();

                        _animals.Clear();
                        _animals = null;
                    }

                    _watchman?.Dispose();
                    _instance = null;

                    GC.Collect();
                    GC.WaitForPendingFinalizers();

                }

                _dispose = true;
            }
        }

        ~Zoo()
        {
            Console.WriteLine("~Zoo()");
            Dispose();
        }

    }
}

