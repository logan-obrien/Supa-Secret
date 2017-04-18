#include <iostream>
#include <fstream>
#include <queue>
#include <string>

#include "Circuit.h"
#include "Wire.h"
#include "Gate.h"

using namespace std;

/*
    Apparently he's fine with us leaking memory all over the place.
*/
/*
   Dr Shomper told me he wants this done by tomorrow night
*/
void parseCircuit(ifstream& in, Circuit& c)
{
	string inputString;
	int inputNumber;

	//skip first line of circuit file:
	in >> inputString;
	in >> inputString;

   while (!in.eof())
   {
	   //Check if there is another line??? If there is:
      in >> inputString;

	   if (inputString == "INPUT" || inputString == "OUTPUT") {
		   //Skip the letter. We don't need it do we?
         // We do. It's the name of the wire
         string name;
         int    wireNum;

         in >> name;
         in >> wireNum;
	   //} This one isn't necessary unless we differentiate between Input/Output wires
      //  in the circuit class. (Might be a good idea)
	   //else if (inputString == "OUTPUT") {

         c.addWire(new Wire(name, wireNum));

	   }
	   //else it is a gate
	   else {
		   //Either use if-else statements to determine which type of gate it is and then convert to enum,
		   //or use a switch statement based off of the first character of the gate. For the case that is 'N', 
		   //then use if-else statements to determine which one of the gates that begin with an "N" it is.

         string type;
         int    delay;
         int    inputA, inputB;
         int    output;

         cin >> type;
         cin >> delay;
         cin >> inputA;
         cin >> inputB;
         cin >> output;

         /*
            Check for internal wires

            I don't know if this will work, but I think it might.
         */
         if (c.getWire(inputA) == nullptr)
         {
            c.addWire(new Wire("INT", inputA), inputA);
         }

         if (c.getWire(inputB) == nullptr)
         {
            c.addWire(new Wire("INT", inputB), inputB);
         }

         if (c.getWire(output) == nullptr)
         {
            c.addWire(new Wire("INT", output), output);
         }

         c.addGate(new Gate(c.getWire(inputA), c.getWire(inputB), c.getWire(output), Gate::gateTypeFactory.at(type), delay));

	   }
   }

}

void parseVector(ifstream& in, const priority_queue<Event*>& eventContainer)
{

}

void runSimulation(const Circuit& c)
{

}

void generateOutput(const Circuit& c)
{

}

int main()
{

   Circuit* c = new Circuit();

   // Create the file stream
   ifstream in("circuit0.txt");

   // Parse the circuit file
   parseCircuit(in, *c);


   return 0;
}
