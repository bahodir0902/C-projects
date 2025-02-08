#include <iostream>
#include <string>
using namespace std;

class Image {
public:
    class Pixel {
    private:
        int red;
        int green;
        int blue;
    public:
        Pixel(int red, int green, int blue) 
        {
            this->red = red;
            this->green = green;
            this->blue = blue;
        }
        string GetInfo() 
        {
            return "Red pixel: " + to_string(red) + ", " + "Green pixel: " + to_string(green) + 
                ", " + "Blue pixel: "  + to_string(blue);
        }

    };
    static const int length = 5;
    Pixel pixels[length]
    {
        Pixel(0,4,64),
        Pixel(4,14,164),
        Pixel(48,43,244),
        Pixel(75,103,184),
        Pixel(3,34,200),
    };
    
public:
    void getImageInfo() {
        for (int i = 0; i < length; i++)
        {
            cout <<"#" << i << ' ' << pixels[i].GetInfo() << endl;
            
        }
    }
};

int main()
{
    Image img; 
    img.getImageInfo();
    cout << endl << endl << "Entered pixel: " << endl;
    Image::Pixel pixel(45,97,34); // When inner class is in public space!
    cout << pixel.GetInfo() << endl; // inner class in public place
    
}
