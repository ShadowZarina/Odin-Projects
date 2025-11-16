'''

class Rectangle:
    def __init__(self, length, width):
        self.length = length
        self.width = width
    
    def area(self):
        return self.length * self.width

r1 = Rectangle(5,3)
print("Area:", r1.area())

'''

'''
class House:
    def __init__ (self, color, rooms):
        self.color = color
        self.rooms = rooms

    def describe(self):
        print(f"This is a {self.color} house with {self.rooms} rooms.")

house = House("blue", 3)
print(house.describe())
'''

'''
class BankAccount:
    def __init__(self, balance):
        # Initialize with double underscores
        self.__balance = balance
    
    def deposit(self, amount):
        # Access with double underscores (indicate private property, limited to specific class)
        self.__balance += amount
        
    def get_balance(self):
        # Access with double underscores
        return self.__balance

account = BankAccount(100)
account.deposit(50)
print(account.get_balance()) # Output: 150
'''

'''
from abc import ABC, abstractmethod

# Parent Class
class Appliance(ABC):
    @abstractmethod
    # Abstraction simplifies complex systems by only exposing essential features
    def turn_on(self):
        pass

# Child Class
class Fan(Appliance):
    def turn_on(self):
        print("Fan starts spinning.")

class Light(Appliance):
    def turn_on(self):
        print("Light turns on.")
    
devices = [Fan(), Light()]
for device in devices:
    device.turn_on()

# ABC = Abstract Base Class 
# Abstract classes contain methods that each subclass MUST IMPLEMENT & cannot be instantiated 
# You must inherit from ABC to be able to use @abstractmethod decorator
'''

# Polymorphism 
# ability of different classes to be treated as instances of the SAME PARENT CLASS

class Animal:
    def speak(self):
        print("Animal sound")

class Dog(Animal):
    def speak(self):
        print("Woof!")

class Cat(Animal):
    def speak(self):
        print("Meow!")

animals = [Dog(), Cat()]
for animal in animals:
    animal.speak()

# OOP makes the program clean & easy to maintain