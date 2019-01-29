namespace Serializer {
    class Worker {
        [ShOneXml("Attribute")]
        public string Id;

        [ShOneXml("Element")]
        public string Name;

        //[ShOneXml("Element")]     if there is no attribute, then the field will be sterilized as an element
        public string Salary;  

        public Worker(string Id, string Name, string Salary) {
            this.Id = Id;
            this.Name = Name;
            this.Salary = Salary;
        }
    }
}
