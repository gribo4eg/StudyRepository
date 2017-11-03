using System;
using System.Collections;

namespace Lab3
{
    public static class Extensions
    {
        public static void Show(this AnimalCollection an)
        {
            foreach (IAnimal animal in an)
            {
                Console.WriteLine("Type: {0}; Name: {1}; Age: {2}; Food: {3}",
                    animal.GetType().ToString().Remove(0,5), animal.Name, animal.Age, animal.Food);
            }
            Console.WriteLine('\n');
        }
    }

    public class AnimalCollection : IEnumerable, IEnumerator
    {
        private IAnimal[] _animals;
        private int _pos = -1;
        private int _count = 0;

        public AnimalCollection(int n)
        {
            _animals = new IAnimal[n];
        }

        public void Reset()
        {
            _pos = -1;
        }

        public IAnimal this[string name]
        {
            get
            {
                foreach (var animal in _animals)
                {
                    if (animal.Name == name) return animal;
                }
                return null;
            }

            set { this[name] = value;  }
        }

        public IAnimal this[int index]
        {
            get { return _animals[index]; }
            set
            {
                _animals[index] = value;
                _count++;
            }
        }

        public int Count => _count;

        private void AddSize()
        {
            IAnimal[] temp = _animals;
            _animals = new IAnimal[temp.Length + 5];
            for (int i = 0; i < temp.Length-1; i++)
            {
                _animals[i] = temp[i];
            }
        }

        public IAnimal Remove(IAnimal a)
        {
            IAnimal temp;
            foreach (var an in _animals)
            {
                if (a.Equals(an))
                {
                    temp = an;
                    int index = GetIndex(an);
                    _animals[index] = null;
                    _count--;
                    return temp;
                }
            }
            return null;
        }


        private int GetIndex(IAnimal a)
        {
            for (int i = 0; i < _animals.Length-1; i++)
            {
                if (_animals[i].Equals(a)) return i;
            }
            return -1;
        }

        public  IEnumerator GetEnumerator()
        {
            return (IEnumerator)this;
        }

        public bool MoveNext()
        {
            if (_pos < _animals.Length - 1)
            {
                _pos++;
                return true;
            }
            return false;
        }

        public bool MoveBack()
        {
            if (_pos > -1)
            {
                _pos--;
                return true;
            }
            return false;

        }

        public object Current => _animals[_pos];

        public void SortName()
        {
            string[] names = new string[_animals.Length];
            for (int i = 0; i < _animals.Length - 1; i++)
            {
                names[i] = _animals[i].Name;
            }
            Array.Sort(names);
            Array.Sort(this._animals, names);
            this.Reset();
        }


    }

}