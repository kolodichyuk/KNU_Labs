using System;
using System.IO;
using System.Xml.Linq;
using System.Reflection;

namespace Serializer {
    // The main class, which provides serialization and deserialization
    public delegate void AsyncDelegate();
    public sealed class ShOneXml {
        private Random rand = new Random();
        private string path; // Main .xml file
        private string pathNew;
        private static bool state = true;

        public ShOneXml(string path) {
            this.path = path;
        }

        #region Serialization
        public void Serialization(dynamic xmlObject) {
            while (true) {
                if (state) {
                    state = false;
                    Action<dynamic> action = AsyncSerialization;
                    IAsyncResult asyncResult = action.BeginInvoke(xmlObject, null, null);
                    break;
                }
            }
        }
        public void AsyncSerialization(dynamic xmlObject) {
            Type type;
            // Generation of .xml file node names
            string PilotName = NameGeneration(xmlObject.GetType().ToString()), RootName = PilotName + "s";
            FileStream file = new FileStream(path, FileMode.Create);
            using (var writer = new StreamWriter(file)) {
                writer.WriteLine(EncryptionLine("<?xml version=\"1.0\"?>"));
                writer.WriteLine(EncryptionLine(string.Format("<{0}>", RootName)));
                string RetReat = "   ", elementEncrypt = "";
                for (int i = 0; i < xmlObject.Count; i++) {
                    elementEncrypt = "";
                    // Obtaining a list item type
                    type = xmlObject[i].GetType();
                    // Obtaining the list item's fields
                    FieldInfo[] ClassFields = type.GetFields(); 
                    elementEncrypt += string.Format("<{0}", PilotName);
                    foreach (var ClassField in ClassFields) {
                        ShOneXmlAttribute attribut = (ShOneXmlAttribute)ClassField.GetCustomAttribute(typeof(ShOneXmlAttribute), false);
                        if (attribut != null) {
                            if (attribut.PositionAttribute == "Attribute") {
                                elementEncrypt += string.Format(" {0}=\"{1}\"", ClassField.Name, ClassField.GetValue(xmlObject[i]));
                            }
                        }
                    }
                    elementEncrypt += ">";
                    writer.WriteLine(RetReat + EncryptionLine(elementEncrypt));
                    RetReat += "  ";
                    foreach (var ClassField in ClassFields) {
                        ShOneXmlAttribute attribut = (ShOneXmlAttribute)ClassField.GetCustomAttribute(typeof(ShOneXmlAttribute), false);
                        if (attribut == null || attribut.PositionAttribute == "Element") {
                            elementEncrypt = string.Format("<{0}>{1}</{2}>", ClassField.Name, ClassField.GetValue(xmlObject[i]), ClassField.Name);
                            writer.WriteLine("{0}{1}", RetReat, EncryptionLine(elementEncrypt));
                        }
                    }
                    RetReat = RetReat.Remove(0, 2);
                    writer.WriteLine(RetReat + EncryptionLine(string.Format("</{0}>", PilotName)));
                }
                writer.WriteLine(EncryptionLine(string.Format("</{0}>", RootName)));
            }
            state = true;
        }
        // Generation of .xml file node names
        private string NameGeneration(string FullName) {
            int indexOfDot = FullName.LastIndexOf(".");
            FullName = FullName.Remove(0, indexOfDot + 1);
            FullName = FullName.Remove(FullName.Length - 1);
            return FullName;
        }
        #endregion

        #region Deserialization
        public void Deserialization()  {
            // Organize file access
            while (true) {
                if (state) {
                    state = false;
                    AsyncDelegate action = AsyncDeserialization;
                    IAsyncResult asyncResult = action.BeginInvoke(null, null);
                    break;
                }
            }
        }
        public void AsyncDeserialization() {
            Decryption();
            XDocument xmlDoc = XDocument.Load(pathNew);
            File.Delete(pathNew);
            foreach (XElement mainElement in xmlDoc.Root.Elements()) {
                Console.WriteLine("{0}: ", mainElement.Name);
                if (mainElement.Attributes() != null) {
                    foreach (XAttribute attribute in mainElement.Attributes()) {
                        Console.WriteLine("    {0} = \"{1}\"", attribute.Name, attribute.Value);
                    }
                }
                foreach (XElement pilotElement in mainElement.Elements()) {
                    Console.WriteLine("    {0} = \"{1}\"", pilotElement.Name, pilotElement.Value);
                }
                Console.WriteLine(new string('-', 30));
            }
            state = true;
        }
        #endregion

        #region Decription
        private string EncryptionLine(string elementEncrypt) {
            string elementEncryptResult = "";
            int key;
            while ((key = rand.Next(-1, 1)) == 0) { }
            for (int i = 0; i < elementEncrypt.Length; i++) {
                char symbol = elementEncrypt[i];
                symbol = (char)((int)symbol + key);
                elementEncryptResult += symbol;
            }
            return elementEncryptResult; 
        }
        private void Decryption() {
            pathNew = path.Substring(0, path.Length - 5) + "temp.xml";
            FileStream fileWriter = new FileStream(pathNew, FileMode.Create);
            FileStream fileReader = new FileStream(path, FileMode.Open);
            using (var reader = new StreamReader(fileReader)) {
                using (var writer = new StreamWriter(fileWriter)) {
                    int key = 0, value = 60;
                    string elementDecrypt = null, line = null;
                    while ((line = reader.ReadLine()) != null) {
                        if (line != "") {
                            int index = 0;
                            for (int i = 0; ; i++) {
                                if (line[i] != 32) {
                                    index = i;
                                    break;
                                }
                                elementDecrypt += " ";
                            }
                            key = -(line[index] - value);
                            for (int i = index; i < line.Length; i++) {
                                if (line[i] != 32)
                                    elementDecrypt += (char)(key + (int)line[i]);
                                else elementDecrypt += " ";
                            }
                            writer.WriteLine(elementDecrypt);
                            elementDecrypt = null;
                        }
                    }
                }
            }
        }
        #endregion
    }
}
