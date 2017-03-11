using System;

namespace Lab2
{
    class WatchmanException:Exception
    {
        string message;

        public WatchmanException(Watchman w)
        {
            if (w.Name.Length < 2)
            {
                message = "Watchman name is too short!";
            }
            else if (w.Name.Length > 10)
            {
                message = "Watchman name is too long!";
            }
            else if (w.Age < 18)
            {
                message = "Watchman is too young!";
            }
            else if (w.IQ < 110)
            {
                message = "Stupid Watchman!";
            }
        }

        public string info()
        {
            return message;
        }
    }

    class ZooException:Exception
    {

        string exMessage;

        public ZooException(Watchman w)
        {
            if (w == null)
                exMessage = "Zoo dont have watcher";
        }

        public string info()
        {
            return exMessage;
        }
    }

}
