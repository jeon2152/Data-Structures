#include <iostream>		// header
using namespace std;

// ---- Define superclass - Item ---- //
class Item {

	friend ostream& operator<< (ostream&, Item&);			// this is to define operator<<

	// Define common attributes (1 - 10)
	protected:
		int _code;
		int _color;
		int _brand;
		double _height;
		double _length;
		double _width;
		double _weight;
		double _price;
		int _type;
		bool _feature;
	
	// Define constructors and methods
	public:
		// Constructors
		Item();									// empty constructor
		Item(int c, int cl, int b, double h,	// non-empty constructor
			double l, double w, double wt, 
			double p, int t, bool f);
		
		// Getter methods
		int getCode();
		int getColor();
		int getBrand();
		double getHeight();
		double getLength();
		double getWidth();
		double getWeight();
		double getPrice();
		int getType();
		bool getFeature();

		// Setter methods
		void setCode(int c);
		void setColor(int cl);
		void setBrand(int b);
		void setHeight(double h);
		void setLength(double l);
		void setWidth(double w);
		void setWeight(double wt);
		void setPrice(double p);
		void setType(int t);
		void setFeature(bool f);

		// Display method
		void display();
};

// ---- Now, define each constructor and method functions ---- //

// Item empty constructor
Item::Item() {}

// Item non-empty constructor
Item::Item(int c, int cl, int b, double h, double l, double w, double wt, double p, int t, bool f) {
	_code = c;
	_color = cl;
	_brand = b;
	_height = h;
	_length = l;
	_width = w;
	_weight = wt;
	_price = p;
	_type = t;
	_feature = f;
}

// Item getters
int Item::getCode() {return _code;}
int Item::getColor() {return _color;}
int Item::getBrand() {return _brand;}
double Item::getHeight() {return _height;}
double Item::getLength() {return _length;}
double Item::getWidth() {return _width;}
double Item::getWeight() {return _weight;}
double Item::getPrice() {return _price;}
int Item::getType() {return _type;}
bool Item::getFeature() {return _feature;}

// Item setters
void Item::setCode(int c) {_code = c;}
void Item::setColor(int cl) {_color = cl;}
void Item::setBrand(int b) {_brand = b;}
void Item::setHeight(double h) {_height = h;}
void Item::setLength(double l) {_length = l;}
void Item::setWidth(double w) {_width = w;}
void Item::setWeight(double wt) {_weight = wt;}
void Item::setPrice(double p) {_price = p;}
void Item::setType(int t) {_type = t;}
void Item::setFeature(bool f) {_feature = f;}

// Item display method
void Item::display() {}

// Following is for operator<<
ostream& operator<<(ostream& s, Item& item) {
	s << "Code: " << item._code << " Color: " << item._color << " Brand: " << item._brand
		<< " Height: " << item._height << " Length: " << item._length 
		<< " Width: " << item._width << " Weight: " << item._weight 
		<< " Price: " << item._price << " Type: " << item._type << " Feature: " << item._feature 
		<< endl;
	return s;
}


// ---- Define subclass - Pens ---- //
class Pens : public Item {

	// Define individual attribute (11)
	protected:
		int _packetSize;

	// Define constructors and methods
	public:
		// Constructors
		Pens();									// empty constructor
		Pens(int c, int cl, int b, double h,	// non-empty constructor 
			double l, double w, double wt, 
			double p, int t, bool f, int ps);
		//virtual ~Pens();						// destructor of the Pens class, if necessary

		// Getter and Setter methods
		int getPacketSize();					// getter method
		void setPacketSize(int ps);				// setter method

		// Display method
		void display();
};

// ---- Now, define each constructor and method functions ---- //

// Pens empty constructor
Pens::Pens() {}

// Pens non-empty constructor
Pens::Pens(int c, int cl, int b, double h, double l, double w, double wt, double p, int t, bool f, int ps) {
	_code = c;
	_color = cl;
	_brand = b;
	_height = h;
	_length = l;
	_width = w;
	_weight = wt;
	_price = p;
	_type = t;
	_feature = f;
	_packetSize = ps;
}

// Pens getter
int Pens::getPacketSize() {return _packetSize;}

// Pens setter
void Pens::setPacketSize(int ps) {_packetSize = ps;}

// Pens display method
void Pens::display() {

	// Describe the item, Pen
	cout << "This is a Pen. ";
	
	// Display Color
	cout << "It's color is ";
	if (_color == 1){
		cout << "Red; ";
	}
	else if (_color == 2) {
		cout << "Blue; ";
	}
	else if (_color == 3) {
		cout << "Green; ";
	}
	else if (_color == 4) {
		cout << "Black; ";
	}
	
	// Display Brand
	cout << "brand is ";
	if (_brand == 1) {
		cout << "Pilot; ";
	}
	else if (_brand == 2) {
		cout << "Paper mate; ";
	}
	else if (_brand == 3) {
		cout << "Uni-ball; ";
	}
	else if (_brand == 4) {
		cout << "Sharpie; ";
	}

	cout << "height is " << _height << " inches; ";		// display Height
	cout << "length is " << _length << " inches; ";		// display Length
	cout << "width is " << _width << " inches; ";		// display Width
	cout << "weight is " << _weight << " pounds; ";		// display Weight
	cout << "price is " << _price << " dollars; ";		// display Price
	
	// Display Type
	cout << "type is ";
	if (_type == 1) {
		cout << "Ball Point; ";
	}
	else if (_type == 2) {
		cout << "Roller Ball; ";
	}
	else if (_type == 3) {
		cout << "Fountain; ";
	}
	else if (_type == 4) {
		cout << "Calligraphy; ";
	}

	// Display Feature
	cout << "if it uses Assorted Ink, then ";
	if (_feature) {
		cout << "Yes; ";
	}
	else { cout << "No; "; }

	// Display Item Field (Special Feature)
	cout << "and it's Packet Size is " << _packetSize << "." << endl;
}


// ---- Define subclass - Printer ---- //
class Printer : public Item {
	// Define individual attribute (11)
	protected:
		int _trayCap;
	
	// Define constructors and methods
	public:
		// Constructors
		Printer();									// empty constructor
		Printer(int c, int cl, int b, double h,		// non-empty constructor 
			double l, double w, double wt, 
			double p, int t, bool f, int tc);
		//virtual ~Printer();						// destructor of the Printer class, if necessary

		// Getter and Setter methods
		int getTrayCap();							// getter method
		void setTrayCap(int tc);					// setter method

		// Display method
		void display();
};

// ---- Now, define each constructor and method functions ---- //

// Printer empty constructor
Printer::Printer() {}

// Printer non-empty constructor
Printer::Printer(int c, int cl, int b, double h, double l, double w, double wt, double p, int t, bool f, int tc) {
	_code = c;
	_color = cl;
	_brand = b;
	_height = h;
	_length = l;
	_width = w;
	_weight = wt;
	_price = p;
	_type = t;
	_feature = f;
	_trayCap = tc;
}

// Printer getter
int Printer::getTrayCap() {return _trayCap;}

// Printer setter
void Printer::setTrayCap(int tc) {_trayCap = tc;}

// Printer display method
void Printer::display() {

	// Describe the item, Printer
	cout << "This is a Printer. ";

	// Display Color
	cout << "It's color is ";
	if (_color == 1) {
		cout << "Black; ";
	}
	else if (_color == 2) {
		cout << "White; ";
	}

	// Display Brand
	cout << "brand is ";
	if (_brand == 1) {
		cout << "Dell; ";
	}
	else if (_brand == 2) {
		cout << "HP; ";
	}
	else if (_brand == 3) {
		cout << "Cannon; ";
	}
	else if (_brand == 4) {
		cout << "Brother; ";
	}

	cout << "height is " << _height << " inches; ";		// display Height
	cout << "length is " << _length << " inches; ";		// display Length
	cout << "width is " << _width << " inches; ";		// display Width
	cout << "weight is " << _weight << " pounds; ";		// display Weight
	cout << "price is " << _price << " dollars; ";		// display Price

	// Display Type
	cout << "type is ";
	if (_type == 1) {
		cout << "All-In-One; ";
	}
	else if (_type == 2) {
		cout << "Laser; ";
	}
	else if (_type == 3) {
		cout << "InlJet; ";
	}

	// Display Feature
	cout << "if it is connected to Network, then ";
	if (_feature) {
		cout << "Yes; ";
	}
	else { cout << "No; "; }

	// Display Item Field (Special Feature)
	cout << "and it's Tray Capacity is " << _trayCap << "." << endl;
}


// ---- Define subclass - SafeBox ----//
class SafeBox : public Item {
	// Define individual attribute (11)
	protected:
		bool _elecLock;

	// Define constructors and methods
	public:
		// Constructors
		SafeBox();									// empty constructor
		SafeBox(int c, int cl, int b, double h,		// non-empty constructor 
			double l, double w, double wt, 
			double p, int t, bool f, bool el);
		//virtual ~SafeBox();						// destructor of the SafeBox class, if necessary

		// Getter and Setter methods
		bool getElecLock();							// getter method
		void setElecLock(bool el);					// setter method

		// Display method
		void display();
};

// ---- Now, define each constructor and method functions ---- //

// SafeBox empty constructor
SafeBox::SafeBox() {}

// SafeBox non-empty constructor
SafeBox::SafeBox(int c, int cl, int b, double h, double l, double w, double wt, double p, int t, bool f, bool el) {
	_code = c;
	_color = cl;
	_brand = b;
	_height = h;
	_length = l;
	_width = w;
	_weight = wt;
	_price = p;
	_type = t;
	_feature = f;
	_elecLock = el;
}

// SafeBox getter
bool SafeBox::getElecLock() {return _elecLock;}

// SafeBox setter
void SafeBox::setElecLock(bool el) {_elecLock = el;}

// SafeBox display method
void SafeBox::display() {
	
	// Describe the item, Safe Box
	cout << "This is a Safe Box. ";

	// Display Color
	cout << "It's color is ";
	if (_color == 1) {
		cout << "Black; ";
	}
	else if (_color == 2) {
		cout << "Red; ";
	}

	// Display Brand
	cout << "brand is ";
	if (_brand == 1) {
		cout << "SentrySafe; ";
	}
	else if (_brand == 2) {
		cout << "First Alert; ";
	}
	else if (_brand == 3) {
		cout << "Honeywell; ";
	}

	cout << "height is " << _height << " inches; ";		// display Height
	cout << "length is " << _length << " inches; ";		// display Length
	cout << "width is " << _width << " inches; ";		// display Width
	cout << "weight is " << _weight << " pounds; ";		// display Weight
	cout << "price is " << _price << " dollars; ";		// display Price

	// Display Type
	cout << "type is ";
	if (_type == 1) {
		cout << "Water Proof; ";
	}
	else if (_type == 2) {
		cout << "Wall Mountable; ";
	}
	else if (_type == 3) {
		cout << "Desktop; ";
	}

	// Display Feature
	cout << "if it is Fire Resistant, then ";
	if (_feature) {
		cout << "Yes; ";
	}
	else { cout << "No; "; }

	// Display Item Field (Special Feature)
	cout << "and if it has Electronic Lock, then ";
	if (_elecLock) {
		cout << "Yes." << endl;
	}
	else { cout << "No." << endl; }
}


// ---- Main Function ---- //
int main() {

	cout << "===================================================" << endl;
	cout << "Interpretation of Input File" << endl;
	cout << "===================================================" << endl;

	Item* Bag[256];					// define an array of pointer, Bag
	
	// local variables to read data from the input file
	char command[100];
	int quantity, code, color, brand, type;
	double height, length, width, weight, price;
	bool feature;
	int packet, tray, itemField;
	bool lock;
	/*char data[1000];*/			// if the input file is read as a data set

	// assign the input data to Bag array
	int bagPos = 0;
	while (!cin.eof()) { // while end of line is not reached
		
		// read a line from input
		cin >> command >> quantity >> code >> color >> brand >>			// input file by elements
			height >> length >> width >> weight >> price >> type >>
			feature >> itemField;
		/*cin.getline(data, 1000);*/									// in case that input file as a data set
		
		/*cout << command << " " << quantity << " " << code << " " <<	// display input data, if necessary
			color << " " << brand << " " <<	height << " " << length << 
			" " << width << " " << weight << " " << price << " " << 
			type << " " << feature << " " << itemField << endl;*/
		/*cout << data << endl;*/										// in case that input file as a data set
		
		// create the object and store it to Bag array
		for (int i = 0; i < quantity; i++) {
			
			if (code == 1) {
				Bag[bagPos + i] = new Pens(code, color, brand, height, length, width, weight, price, type, feature, itemField);
			}
			else if (code == 2) {
				Bag[bagPos + i] = new Printer(code, color, brand, height, length, width, weight, price, type, feature, itemField);
			}
			else if (code == 3) {
				Bag[bagPos + i] = new SafeBox(code, color, brand, height, length, width, weight, price, type, feature, itemField);
			}
			/*cout << *(Bag[bagPos + i]) << endl;*/						// this is to check if the array is correctly assigned
		}
		bagPos = bagPos + quantity;
			
	} // end of while loop
	
	/*cout << *(Bag[0]) << endl;*/										// this is to check if the array is correctly assigned

	// call the elements from the Bag array
	int noItems = bagPos;

	// local variables to count the number of each item
	int noPens = 0;
	int noPrinter = 0;
	int noSafeBox = 0;
	for (int i = 0; i < noItems; i++) {
		switch ((*Bag[i]).getCode()) {
			case 1: {//Pens
						(static_cast<Pens*>(Bag[i]))->display();
						noPens++;		// this is to count the pen quantity
						break;
					}
			case 2: {//Printer
						(static_cast<Printer*>(Bag[i]))->display();
						noPrinter++;	// this is to count the printer quantity
						break;
					}
			case 3: {//Safe Box
						(static_cast<SafeBox*>(Bag[i]))->display();
						noSafeBox++;	// this is to count the safe box quantity
						break;
					}
			default: cout << "I do not recognize this Items in the Bag." << endl;
		}
	}
	
	// display summary information
	cout << "===================================================" << endl;
	cout << "Summary Information" << endl;

	// number of items in each item category
	cout << "===================================================" << endl;
	cout << "Number of pen: " << noPens << endl;
	cout << "Number of printer: " << noPrinter << endl;
	cout << "Number of safe box: " << noSafeBox << endl;

	// total price for each item category
	double penPrice = 0.0;
	double printerPrice = 0.0;
	double safeBoxPrice = 0.0;
	for (int i = 0; i < noItems; i++) {
		switch ((*Bag[i]).getCode()) {
		case 1: {//Pens
			penPrice = penPrice + (static_cast<Pens*>(Bag[i]))->getPrice();
			break;
		}
		case 2: {//Printer
			printerPrice = printerPrice + (static_cast<Printer*>(Bag[i]))->getPrice();
			break;
		}
		case 3: {//Safe Box
			safeBoxPrice = safeBoxPrice + (static_cast<SafeBox*>(Bag[i]))->getPrice();
			break;
		}
		default: cout << "I do not recognize this Items in the Bag." << endl;
		}
	}
	
	cout << "---------------------------------------------------" << endl;
	cout << "Total price of pen: " << penPrice << " dollars." << endl;
	cout << "Total price of printer: " << printerPrice << " dollars." << endl;
	cout << "Total price of safe box: " << safeBoxPrice << " dollars." << endl;

	// total value of all items
	cout << "---------------------------------------------------" << endl;
	cout << "Total value of all items: " << penPrice + printerPrice + safeBoxPrice << " dollars." << endl;
	cout << "===================================================" << endl;

	return 0;
	
} // end of main function

