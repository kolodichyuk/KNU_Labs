using System;
using System.Drawing;
using System.Collections.Generic;

namespace ConvexHull {
    class Program {
        static void Main(string[] args) {
            // initial sequence of points
            var points = new List<Point> {new Point(2, 5), new Point(4, 2), new Point(4, 5), new Point(7, 5), new Point(9, 8),
                new Point(9, 3), new Point(2, 8), new Point(6, 11)}; 
            var convexHull = Graham_sA.ConvexHull(points);  // build convex hull
            foreach (var item in convexHull)
                Console.Write($"({item.X}, {item.Y}) ");
            Console.ReadLine();
        }
    }
}
