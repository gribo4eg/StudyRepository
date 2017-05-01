using System;
using System.Collections.Generic;

namespace Lab5_Part2
{
    //RECEIVER
    public class Array
    {
        private readonly List<int> _array;

        public Array()
        {
            _array = new List<int>();
        }

        public void Add(int value)
        {
            _array.Add(value);
            Console.WriteLine(value + " added to array on index: " +_array.IndexOf(value));
        }

        public void Remove(int value)
        {
            Console.WriteLine(value + " removed from array from index: "+_array.IndexOf(value));
            _array.Remove(value);
        }

        public void Modify(int index, int newValue)
        {
            Console.WriteLine("Value {0} on index {1} was changed on {2}",
                _array[index], index, newValue);
            _array[index] = newValue;
        }

        public void Show() => _array.ForEach(Console.WriteLine);
    }

    #region Commands

    public interface ICommand
    {
        void Execute(int value);
        void Execute(int index, int value);
    }

    public class AddToArrayCommand : ICommand
    {
        private readonly Array _array;

        public AddToArrayCommand(Array array)
        {
            _array = array;
        }

        public void Execute(int value) => _array.Add(value);

        public void Execute(int index, int value)
        {}
    }

    public class RemoveFromArrayCommand : ICommand
    {
        private readonly Array _array;

        public RemoveFromArrayCommand(Array array)
        {
            _array = array;
        }

        public void Execute(int value) => _array.Remove(value);

        public void Execute(int index, int value)
        {}
    }

    public class ModifyInArrayCommand : ICommand
    {
        private readonly Array _array;

        public ModifyInArrayCommand(Array array)
        {
            _array = array;
        }

        public void Execute(int value)
        {}

        public void Execute(int index, int value) => _array.Modify(index, value);
    }

    #endregion

    //INVOKER
    public class Menu
    {
        public ICommand AddCommand { get; set; }
        public ICommand RemoveCommand { get; set; }
        public ICommand ModifyCommand { get; set; }

        public void AddNumber(int number) => AddCommand.Execute(number);
        public void RemoveNumber(int number) => RemoveCommand.Execute(number);
        public void ModifyNumber(int index, int number) => ModifyCommand.Execute(index, number);
    }

}