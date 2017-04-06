using System.Collections.Generic;
using System.Linq;

namespace Lab3_Part1
{
    public interface IFile
    {
        IFile Clone();
        string Name { get; set; }
        int Size();
        void Rename(string newName);
    }

    public class File : IFile
    {
        public string Info { get; set; }
        public string Name { get; set; }


        public File(string name)
        {
            Name = name;
        }

        public void Rename(string newName) => Name = newName;

        public int Size() => Info.Length;

        public IFile Clone() => MemberwiseClone() as IFile;
        // OR return new File(this.Name);
    }

    public class Folder : IFile
    {
        public List<IFile> Files { get; set; }

        public string Name { get; set; }

        public Folder(string name)
        {
            Name = name;
            Files = new List<IFile>();
        }

        public IFile GetByName(string name) => Files.FirstOrDefault(file => file.Name == name);

        public IFile CopyFile(string name) => (from file in Files where file.Name == name select file.Clone()).FirstOrDefault();

        public List<IFile> CopyAllFiles() => Files.Select(file => file.Clone()).ToList();

        public void Rename(string newName) => Name = newName;

        public int Size() => Files.Sum(file => file.Size());

        public IFile Clone() => new Folder(Name) {Files = Files.Select(file => file.Clone()).ToList()};
    }
}