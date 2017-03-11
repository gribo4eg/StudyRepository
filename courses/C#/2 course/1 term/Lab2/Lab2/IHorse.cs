using System;

namespace Lab2
{
    public interface IHorse
    {
        void Run(int km);
        int Speed { get; }
        void Training();
    }
}

