using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Serializer {
    [AttributeUsage(AttributeTargets.Field, AllowMultiple = false)]
    class ShOneXmlAttribute : System.Attribute {
        private readonly string Position;
        public ShOneXmlAttribute(string Position) {
            this.Position = Position;
        }
        public string PositionAttribute {
            get { return Position; }
        }
    }
}
