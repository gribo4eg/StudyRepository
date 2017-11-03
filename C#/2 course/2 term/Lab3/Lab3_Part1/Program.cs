using System;

namespace Lab3_Part1
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            IFile file = new File("File1");
            var clonedFile = file.Clone();

            Console.WriteLine("File name: " + ((File)file).Name);
            Console.WriteLine("Cloned name: " + ((File)clonedFile).Name);

            file.Rename("KekLOL");

            Console.WriteLine("File name: " + ((File)file).Name);
            Console.WriteLine("Cloned name: " + ((File)clonedFile).Name);

            IFile folder = new Folder("Folder!");

            ((Folder)folder).Files.Add(file);

            ((File) file).Info = "ASASASA"; //7

            ((Folder)folder).Files.Add(new File("File2"));

            ((File) ((Folder) folder).GetByName("File2")).Info = "abrakadabra";//11

            Console.WriteLine("Folder size: " + ((Folder)folder).Size());

            clonedFile = folder.Clone();

            Console.WriteLine("Cloned folder Name: \"{0}\" & size: {1}", ((Folder)clonedFile).Name, ((Folder)clonedFile).Size());

            clonedFile = folder.Clone();

            Console.WriteLine(((Folder)clonedFile).GetByName("File2").Name);
        }
    }
}