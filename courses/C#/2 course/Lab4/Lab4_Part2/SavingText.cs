using System;
using System.Linq;

namespace Lab4_Part2
{
    public class File
    {

        public IStrategy Strategy { get; set; }
        public string Data { get; set; }
        public int Size => Data.Length;

        public File(IStrategy strategy)
        {
            Strategy = strategy;
        }

        public void SetAndSaveData(string data)
        {
            Data = Strategy.Algorithm(data);
        }

        public void ShowData() => Console.WriteLine(Data);

    }

    public interface IStrategy
    {
        string Algorithm(string data);
    }

    public class SimpleSaving : IStrategy
    {
        public string Algorithm(string data) => data;
    }

    public class WithoutSpacesSaving : IStrategy
    {
        public string Algorithm(string data) => data.Replace(" ", "");
    }

    public class CodingSaving : IStrategy
    {
        public string Algorithm(string data) => data.Aggregate("", (current, c) => current + (int) c);
    }
}