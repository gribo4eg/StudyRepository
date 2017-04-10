using System;

namespace Lab5_Part1
{
    public abstract class Handler
    {
        protected double StartTime;
        protected double EndTime;

        public Handler Successor { get; set; }
        public abstract void DoWork(double time, string work);
    }

    public class FirstChange : Handler
    {
        public FirstChange()
        {
            StartTime = 6;
            EndTime = 15;
        }

        public override void DoWork(double time, string work)
        {
            if (time >= StartTime && time < EndTime - 1)
            {
                Console.WriteLine("First change is going to do work: "+work);
            }
            else
            {
                Successor?.DoWork(time, work);
            }
        }
    }

    public class SecondChange : Handler
    {
        public SecondChange()
        {
            StartTime = 14;
            EndTime = 23;
        }

        public override void DoWork(double time, string work)
        {
            if (time >= StartTime && time < EndTime - 1)
            {
                Console.WriteLine("Second change is going to do work: "+work);
            }
            else
            {
                Successor?.DoWork(time, work);
            }
        }
    }

    public class ThirdChange : Handler
    {
        public ThirdChange()
        {
            StartTime = 22;
            EndTime = 7;
        }

        public override void DoWork(double time, string work)
        {
            if (time >= StartTime && time < EndTime - 1)
            {
                Console.WriteLine("Third change is going to do work: "+work);
            }
            else
            {
                Successor?.DoWork(time, work);
            }
        }
    }
}