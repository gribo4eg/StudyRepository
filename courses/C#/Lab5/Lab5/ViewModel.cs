﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.Runtime.Serialization;
using System.Windows;
using System.Windows.Input;


namespace Lab5
{
    public class ViewModel
    {

        private DelegateCommand _exitCommand;
        private DelegateCommand _saveCommand;
        public WatchmanModel Watchmans { get; set; }
        public string WatchmanNameToAdd { get; set; }
        public string WatchmanSurnameToAdd { get; set; }
        public int WatchmanAgeToAdd { get; set; }
        public int WatchmanWeightToAdd { get; set; }

        public string WatchmanNameUpdate { get; set; }
        public string WatchmanSurnameUpdate { get; set; }
        public int WatchmanAgeUpdate { get; set; }
        public int WatchmanWeightUpdate { get; set; }
        public ViewModel()
        {
            Watchmans = WatchmanModel.GetInstance;
        }

        public ICommand ExitCommand => _exitCommand ?? (_exitCommand = new DelegateCommand(Exit, CanExecuteCommand));

        public ICommand SaveCommand => _saveCommand ?? (_saveCommand = new DelegateCommand(Save, CanExecuteCommand));

        private void Exit(object parameter)
        {
            Save(parameter);
            Application.Current.Shutdown();
        }

        private void Save(object parameter)
        {
            Watchmans.SaveInstance();
        }

        private ICommand _addWatchmanCommand;

        public ICommand AddWatchmanCommand => _addWatchmanCommand ?? (_addWatchmanCommand = new DelegateCommand(AddWatchman, CanExecuteCommand));

        private void AddWatchman(object parameter)
        {
            WatchmanNameToAdd.Trim();

            Watchmans.AddWatchman(WatchmanNameToAdd, WatchmanSurnameToAdd, 
                WatchmanAgeToAdd, WatchmanWeightToAdd);
        }

        public void DeleteWatchman(object parameter)
        {
            Watchmans.Remove((Watchman)parameter);
        }

        public void UpdateWatchman(object parameter)
        {
            
        }

        public bool CanExecuteCommand(object parameter)
        {
            return true;
        }
    }

    public class DelegateCommand : ICommand
    {
        public delegate void ICommandOnExecute(object parameter);
        public delegate bool ICommandOnCanExecute(object parameter);

        private ICommandOnExecute _execute;
        private ICommandOnCanExecute _canExecute;

        public DelegateCommand(ICommandOnExecute onExecuteMethod, ICommandOnCanExecute onCanExecuteMethod)
        {
            _execute = onExecuteMethod;
            _canExecute = onCanExecuteMethod;
        }

        #region ICommand Members

        public event EventHandler CanExecuteChanged
        {
            add { CommandManager.RequerySuggested += value; }
            remove { CommandManager.RequerySuggested -= value; }
        }

        public bool CanExecute(object parameter)
        {
            return _canExecute.Invoke(parameter);
        }

        public void Execute(object parameter)
        {
            _execute.Invoke(parameter);
        }

        #endregion
    }

    public class Validator
    {
        private static int _minNameLenght = 5;
        private static int _minAge = 18;
        private static int _maxAge = 99;
        private static double _maxWeight = 200.0;

        public static bool Valid(string name, string surname, int age, int weight)
        {
            name.Trim();

            StringBuilder SB = new StringBuilder();
            if (name == "")
            {
                SB.Remove(0, SB.Length);
                SB.Append("Please type in a name for the student.");
                //throw new ArgumentException(SB.ToString());
                return false;
            }
            if (name.Length < _minNameLenght)
            {
                SB.Remove(0, SB.Length);
                SB.Append("Watchers name must contain 5 symb");
                //throw new ArgumentException(SB.ToString());
                return false;
            }
            if (surname.Length < _minNameLenght)
            {
                SB.Remove(0, SB.Length);
                SB.Append("Watchers surname must contain 5 symb");
                //throw new ArgumentException(SB.ToString());
                return false;
            }
            if (age < _minAge)
            {
                SB.Remove(0, SB.Length);
                SB.Append("Watcher is too little");
                //throw new ArgumentException(SB.ToString());
                return false;
            }
            if (weight <= _minAge)
            {
                SB.Remove(0, SB.Length);
                SB.Append("Watcher is too little");
                //throw new ArgumentException(SB.ToString());
                return false;
            }
            if (age > _maxAge || weight > _maxWeight)
            {
                SB.Remove(0, SB.Length);
                SB.Append("Invalid data(too big data for age or weight)");
                //throw new ArgumentException(SB.ToString());
                return false;
            }
            return true;
        }

    }
}
