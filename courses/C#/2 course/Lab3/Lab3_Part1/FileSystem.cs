using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;

namespace Lab3_Part1
{
    public interface IFile : ICloneable
    {
        Object Clone();
        string Name { get; set; }
        int Size();
        void Rename(string newName);
    }

    [Serializable]
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

        public Object Clone() => MemberwiseClone();
        // OR return new File(this.Name);
    }

    [Serializable]
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

        public Object CopyFile(string name) => (from file in Files where file.Name == name select file.Clone()).FirstOrDefault();

        public List<Object> CopyAllFiles() => Files.Select(file => file.Clone()).ToList();

        public void Rename(string newName) => Name = newName;

        public int Size() => Files.Sum(file => file.Size());

        public Object Clone()
        {
            object folder = null;
            using (MemoryStream tempStream = new MemoryStream())
            {
                BinaryFormatter binFormatter = new BinaryFormatter(null,
                    new StreamingContext(StreamingContextStates.Clone));

                        binFormatter.Serialize(tempStream, this);
                        tempStream.Seek(0, SeekOrigin.Begin);

                        folder = binFormatter.Deserialize(tempStream);
                    }
            return folder;
        }
    }
}