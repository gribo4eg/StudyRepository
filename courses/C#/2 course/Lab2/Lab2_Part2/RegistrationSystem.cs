using System;
using System.Collections.Generic;
using System.Linq;

namespace Lab2_Part2
{
    public class User
    {
        public string Name { get; set; }
        public string Surname { get; set; }
        public string City { get; set; }
        public int Age { get; set; }
        public string Login { get; set; }
        public string KeyWord { get; set; }
        public string Password { get; set; }
        public string Mail { get; set; }

        public User(string name, string surname, string city,
            int age, string login, string pass, string keyword, string mail)
        {
            Name = name;
            Surname = surname;
            City = city;
            Age = age;
            Login = login;
            KeyWord = keyword;
            Password = pass;
            Mail = mail;
        }

        public void GetInfo()
        {
            Console.WriteLine("User: {0}\nName: {1}\nSurname: {2}\n" +
                              "Password: {3}\nAge: {4}\nCity: {5}\n" +
                              "Email: {6}\n", Login, Name, Surname, Password, Age, City, Mail);
        }
    }

    public class OldRegistrationSystem //Adaptee
    {
        private readonly List<User> _users;

        public OldRegistrationSystem()
        {
            _users = new List<User>();
        }

        public User AddUser(string name, string surname, string city,
            int age, string login, string pass, string keyword, string mail)
        {
            if (_users.Any(user => login == user.Login)) return null;
            var newUser = new User(name, surname, city, age, login,
                pass, keyword, mail);
            _users.Add(newUser);
            return newUser;
        }

        public User GetUser(string login)
        {
            return _users.FirstOrDefault(user => login == user.Login);
        }

        public void RemoveUser(string login)
        {
            _users.Remove(_users.FirstOrDefault(user => login == user.Login));
        }

        public void UserInfo(string login)
        {
            _users.FirstOrDefault(u => login == u.Login)?.GetInfo();
        }
    }

    internal interface ITarget
    {
        User AddUser(string name, string surname, string login,
            string pass, string keyword);
    }

    public class NewRegistrationSystem : ITarget
    {
        private readonly OldRegistrationSystem _system;
        private const string DefaultCity = "NoCity";
        private const string DefaultMail = "NoMail";
        private const int DefaultAge = 0;

        public NewRegistrationSystem()
        {
            _system = new OldRegistrationSystem();
        }

        public NewRegistrationSystem(OldRegistrationSystem system)
        {
            _system = system ?? new OldRegistrationSystem();
        }

        public User AddUser(string name, string surname, string login,
            string pass, string keyword)
        {
            return _system.AddUser(name, surname, DefaultCity, DefaultAge, login,
                pass, keyword, DefaultMail);
        }

        public User GetUser(string login)
        {
            return _system.GetUser(login);
        }

        public void RemoveUser(string login)
        {
            _system.RemoveUser(login);
        }

        public void UserInfo(string login)
        {
            _system.UserInfo(login);
        }
    }
}