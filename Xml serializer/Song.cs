namespace Serializer {
    class Song {
        [ShOneXml("Attribute")] 
        public string Id;          // id song

        [ShOneXml("Element")]
        public string Performen;   // name of the performen

        [ShOneXml("Element")]
        public string Name;        // name of the song

        //[ShOneXml("Element")]    if there is no attribute, then the field will be sterilized as an element
        public string Duration;    // song duration

        public Song(string Id, string Performen, string Name, string Duration) {
            this.Id = Id;
            this.Performen = Performen;
            this.Name = Name;
            this.Duration = Duration;
        }
    }
}
