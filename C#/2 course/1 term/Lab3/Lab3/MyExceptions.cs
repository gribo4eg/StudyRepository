using System;

namespace Lab3
{
    class WatchmanException:Exception
    {
        private readonly string _message;

        public WatchmanException(Watchman w)
        {
            if (w.Name.Length < 2)
            {
                _message = "Watchman name is too short!";
            }
            else if (w.Name.Length > 10)
            {
                _message = "Watchman name is too long!";
            }
           /* else if (w.Age < 18)
            {
                _message = "Watchman is too young!";
            }
            else if (w.Iq < 110)
            {
                _message = "Stupid Watchman!";
            }*/
        }

        public string Info()
        {
            return _message;
        }
    }

    class ZooException:Exception
    {
        private readonly string _message;

        public ZooException(Watchman w)
        {
            if (w == null)
                _message = "Zoo dont have watcher";
        }

        public string info()
        {
            return _message;
        }
    }

}
