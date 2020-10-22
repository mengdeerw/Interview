http://www.vishalchovatiya.com/factory-design-pattern-in-modern-cpp/

Three Types of Design Patterns:
1. Creational
These patterns can be further categorized into Class-creational patterns and object-creational patterns. While class-creation patterns use inheritance effectively in the instantiation process, object-creation patterns use delegation effectively to get the job done.
Creational design patterns are the Factory Method, Abstract Factory, Builder, Singleton, Object Pool, and Prototype.

2. Structural
3. Behavioral

Factory Design Pattern:
Factory method is a creational design pattern, i.e., related to object creation. 
In Factory pattern, we create object without exposing the creation logic to client and the client use the same common interface to create new type of object.
The idea is to use a static member-function (static factory method) which creates & returns instances, hiding the details of class modules from user.

A factory pattern is one of the core design principles to create an object, allowing clients to create objects of a library(explained below) in a way such that it doesn’t have tight coupling with the class hierarchy of the library.

we have totally decoupled the selection of type for object creation from Client. The library is now responsible to decide which object type to create based on an input. Client just needs to make call to library’s factory Create method and pass the type it wants without worrying about the actual implementation of creation of objects

the essence of the Factory Method i.e. private constructor & static method.
