﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.Runtime.Serialization;
using System.Collections.ObjectModel;
using System.IO;

namespace Lab5
{
    public class WatchmanModel: ObservableCollection<Watchman>
    {
        private static WatchmanModel _instance = null;
        public static WatchmanModel GetInstance
        {
            get
            {
                return _instance ?? (_instance = new WatchmanModel());
            }
        }
        
        public int Count
        {
            get
            {
                return _instance.Count;
            }
        }

        public int GetWatchmanIndex(Watchman watchman)
        {
            return IndexOf(watchman);
        }

        public void RemoveWatchman(Watchman watchman)
        {
            Remove(watchman);
        }
        private WatchmanModel()
        {
            Watchman[] result;
            
            using (Stream stream = new FileStream("watchmans.xml", FileMode.Open))
            {
                DataContractSerializer ser = new DataContractSerializer(typeof(Watchman[]));
                result = (Watchman[])ser.ReadObject(stream);
            }

            foreach (Watchman item in result)
            {
                Add(item);
            }
        }

        public void SaveInstance()
        {
            using (Stream stream = new FileStream("watchmans.xml", FileMode.Create))
            {
                DataContractSerializer ser = new DataContractSerializer(typeof(Watchman[]));
                ser.WriteObject(stream, _instance.ToArray());
            }
        }

        public void AddWatchman(string name, string surname, int age, int weight)
        {
            Add(new Watchman(name, surname, age, weight));
        }

        public void AddWathmanAtPosition(Watchman watch, int pos)
        {
            Insert(pos, watch);
        }
    }
}
