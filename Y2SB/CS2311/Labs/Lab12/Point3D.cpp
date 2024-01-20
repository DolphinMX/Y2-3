#include <cmath>
// add preprocessor here to make the program work



class Point3D{
private:
    double x;
    double y;
    double z;
public:
    /*
    Replace the two constructors with one default constructor in the form of initializer list
    */


    Point3D();
    // Overloaded constructor with three parameters
    Point3D(double x, double y, double z);
    //set (mutator) functions
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    //get (accessor) functions       
    double getX();
    double getY();
    double getZ();
    //overridden function, returns the distance from point (0,0,0)
    double calDistance();
    //friend function to overload the operator << for cout
    //complete the function declaration with two parameters (ostream& output, Point3D& point)
    

};

Point3D::Point3D(){
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Point3D::Point3D(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

void Point3D::setX(double x){
    this->x = x;
}
void Point3D::setY(double y){
    this->y = y;
}
void Point3D::setZ(double z){
    this->z = z;
}

double Point3D::getX(){
    return x;
}
double Point3D::getY(){
    return y;
}
double Point3D::getZ(){
    return z;
}

// complete this function
double Point3D::calDistance() {
    

}

// complete the function definition with two parameters (ostream & output, Point3D & point)
/* This function should print in accord with the format as follows 
This point is: (..., ..., ...)
The distance from (0, 0, 0) is ...
*/






int main() {
    cout << "Enter a 3D point's x, y, and z coordinatese in order: " << endl;
    // add code here
    




    return 0;
}