using System;
using System.Threading;
using System.Collections.Generic;

namespace Serializer {
    class Program {
        static void Main(string[] args) {
            List<Song> songsList = new List<Song>() {
                new Song("#1", "Die Antwoord", "Cookie thumper", "5:38"),
                new Song("#2", "Macklemore", "Thrift shopping", "3:52"),
                new Song("#3", "DJ Fresh", "Dibby sound", "3:19"),
                new Song("#4", "Three Days Grace", "Newer too late", "3:29")
            };

            List<Worker> workersList = new List<Worker>() {
                new Worker("#1", "Dima", "1000"),
                new Worker("#2", "Andrew", "1000")
            };

            ShOneXml shOneXml_songs = new ShOneXml("songs.xml");
            shOneXml_songs.Serialization(songsList);
            shOneXml_songs.Deserialization();

            ShOneXml shOneXml_workers = new ShOneXml("workers.xml");
            shOneXml_workers.Serialization(workersList);
            shOneXml_workers.Deserialization();

            Console.ReadKey();
        }
    }
}
