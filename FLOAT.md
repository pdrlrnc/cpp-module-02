***Understanding and Using Floating Point Numbers***

Floating numbers are weird. Given enough bits, you can always represent a integer in binary. Yet, for floating numbers, that is not the case. 

 *Accuracy vs Precision*\
    Accuracy is how close you are to the target, precision is how much information you have about a quantity\
![accuracy_vs_precision](./images/accuracy_vs_precision.png)\
**Integers** have full accuracy. If I have a integer "2", it is exactly on the dot, not much, not less than the real mathematical *2*. However, integers lack precision. *5/2* and *4/2* give us both *2*.\
**Floats** are the opposite. They can be really precise, since they don't deliberately discard information to represent your number, but they are really poor when it comes to accuracy since not every fraction can be represented exactly in binary, no finite decimal digit representation (e.g. *0.333333*) can ever be equal to *1/3*.




***RESOURCES***\
URLs:
- 
- [Jeff Bezanson for Cprogramming - Understanding and Using Floating Point Numbers](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html)

