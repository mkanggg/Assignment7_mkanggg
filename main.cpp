#include <iostream>
#include <math.h>

using namespace std; // when print, write cout instead of "std::cout"


// Create a class for "Electric Field"
class electric_field
{
    private:
	    double *E;  // let E become a pointer, holding the memory address	
    
    public:
	    electric_field(); //  default constructor
	    electric_field(double x, double y, double z);  //  component constructor
	    ~electric_field();   // destructor

	    // getters return 1 components
	    double getX();
	    double getY();
	    double getZ();

	    // setters change one component
	    void setX(double x);
	    void setY(double y);
	    void setZ(double z);

	    double calculatemagnitude();  // length of the vector
	    double calculateinnerproduct();  // inner product of the vector with itself
};


// default constructor
electric_field::electric_field()
{
    E = new double[3];
    E[0] = 0;
    E[1] = 0;
    E[2] = 0;
}

// components constructor
electric_field::electric_field(double x, double y, double z)
{
    E = new double[3];
    E[0] = x;
    E[1] = y;
    E[2] = z;
}

// destructor
electric_field::~electric_field()
{
    delete[] E;
}

// getter to return the value
double electric_field::getX()
{
    return E[0];
}

double electric_field::getY()
{
    return E[1];
}

double electric_field::getZ()
{
    return E[2];
}


// setter to store the value to the new one
void electric_field::setX(double x)
{
    E[0] = x;
}

void electric_field::setY(double y)
{
    E[1] = y;
}

void electric_field::setZ(double z)
{
    E[2] = z;
}


// Calculate the Magnitude
double electric_field::calculatemagnitude()
{
    return sqrt(E[0] * E[0] + E[1] * E[1] + E[2] * E[2]);
}


// Calculate the inner product
double electric_field::calculateinnerproduct()
{
    return E[0] * E[0] + E[1] * E[1] + E[2] * E[2];
}



// Create a class "Magnetic Field"
class magnetic_field
{
    private:
	    double *B;
    
    public:
	    magnetic_field();   // default constructor
	    magnetic_field(double x, double y, double z);  //  components constructor
	    ~magnetic_field();  // destructor

	    // getters
	    double getX();
            double getY();
            double getZ();

	    // setters
            void setX(double x);
            void setY(double y);
            void setZ(double z);


            double calculatemagnitude();   // Calculate the magnitude
	    void unitvector(double &ux, double &uy, double &uz);  // calculate the unit vector
};


// default constructor
magnetic_field::magnetic_field()
{
    B = new double[3];
    B[0] = 0;
    B[1] = 0;
    B[2] = 0;
}


// components constructor
magnetic_field::magnetic_field(double x, double y, double z)
{
    B = new double[3];
    B[0] = x;
    B[1] = y;
    B[2] = z;
}


// destructor
magnetic_field::~magnetic_field()
{
    delete[] B;
}


// getter to return x,y,z (stored the value)
double magnetic_field::getX()
{
    return B[0];
}

double magnetic_field::getY()
{
    return B[1];
}

double magnetic_field::getZ()
{
    return B[2];
}


// setter to store value with new one
void magnetic_field::setX(double x)
{
    B[0] = x;
}

void magnetic_field::setY(double y)
{
    B[1] = y;
}

void magnetic_field::setZ(double z)
{
    B[2] = z;
}


// Calculate the Magnitude
double magnetic_field::calculatemagnitude()
{
    return sqrt(B[0] * B[0] + B[1] * B[1] + B[2] * B[2]);
}


//  Find the Unit Vector
void magnetic_field::unitvector(double &ux, double &uy, double &uz)   // let ux,uy,uz have the same variable ( B[0], B[1], B[2])
{
    double mag = calculatemagnitude();   // let mag = magnitude of magnetic field
    ux = B[0] / mag;  // x component unit vector
    uy = B[1] / mag;  // y component unit vector
    uz = B[2] / mag;  // z compoent unit vector
}



int main()
{
    electric_field E_default;   // default constructor for "electric field"
    electric_field E_components(1e5, 10.9, 1.7e2);  // constructor components for "electric field"
    
    // electric_field setters
    electric_field E_setters;
    E_setters.setX(2);   // setter x component
    E_setters.setY(5);   // setter y component
    E_setters.setZ(10);   // setter z component


    // print magnitude of each electric field
    cout << "\n\nMagnitude" << endl;
    cout << "\nE_default magnitude = " << E_default.calculatemagnitude() << endl;
    cout << "\nE_components magnitude = " << E_components.calculatemagnitude() << endl;
    cout << "\nE_setters magnitude = " << E_setters.calculatemagnitude() << endl;
   
    // print inner products of each electric field
    cout << "\n\nInner Products" << endl;
    cout << "\nE_default inner product = " << E_default.calculateinnerproduct() << endl;
    cout << "\nE_components inner product = " << E_components.calculateinnerproduct() << endl;
    cout << "\nE_setters inner product = " << E_setters.calculateinnerproduct() << endl;


    

    
    magnetic_field B_default;   // default constructor for magnetic field
    magnetic_field B_components(2,4,6);  // components constructor for magnetic field
    
    // magnetic field setters
    magnetic_field B_setters;
    B_setters.setX(1);
    B_setters.setY(9);
    B_setters.setZ(18);


    // print magnitude of each electric field
    cout << "\n\n\n\nMagnitude" << endl;
    cout << "\nB_default magnitude = " << B_default.calculatemagnitude() << endl;
    cout << "\nB_components magnitude = " << B_components.calculatemagnitude() << endl;
    cout << "\nB_setters magnitude = " << B_setters.calculatemagnitude() << endl;


    // print the unit vector
    double ux,uy,uz;

    cout << "\n\nUnit Vector" << endl;
    B_components.unitvector(ux,uy,uz);   // calculate unit vector for B_components
    cout << "\nB_components unit vector = (" << ux << ", " << uy << ", " << uz << ")" << endl;   // print each unit vector

    B_setters.unitvector(ux,uy,uz);   // calculate unit vector for B_setters
    cout << "\nB_setters unit vector = (" << ux << ", " << uy << ", " << uz << ")" << "\n" << endl;   // print each unit vector



    return 0;
}
