#include <iostream>
#include <algorithm>
#include <cmath>

class PersegiPanjang {
private:
    double xmin, xmax, ymin, ymax;

public:
    PersegiPanjang(double xc, double yc, double panjang, double lebar) {
        xmin = xc - panjang / 2;
        xmax = xc + panjang / 2;
        ymin = yc - lebar / 2;
        ymax = yc + lebar / 2;
    }

    // Operator +
    PersegiPanjang operator+(const PersegiPanjang& other) const {
        if (!isOverlapping(other)) {
            std::cerr << "Error: Persegi panjang tidak saling beririsan." << std::endl;
            return *this;
        }

        double new_xmin = std::min(xmin, other.xmin);
        double new_xmax = std::max(xmax, other.xmax);
        double new_ymin = std::min(ymin, other.ymin);
        double new_ymax = std::max(ymax, other.ymax);

        double new_xc = (new_xmin + new_xmax) / 2;
        double new_yc = (new_ymin + new_ymax) / 2;
        double new_length = new_xmax - new_xmin;
        double new_width = new_ymax - new_ymin;

        return PersegiPanjang(new_xc, new_yc, new_length, new_width);
    }
    
    // Operator - 
    PersegiPanjang operator-(const PersegiPanjang& other) const {
        if (!isOverlapping(other)) {
            std::cerr << "Error: Persegi panjang tidak saling beririsan." << std::endl;
            return *this;
        }

        double new_xmin = std::max(xmin, other.xmin);
        double new_xmax = std::min(xmax, other.xmax);
        double new_ymin = std::max(ymin, other.ymin);
        double new_ymax = std::min(ymax, other.ymax);

        double new_xc = (new_xmin + new_xmax) / 2;
        double new_yc = (new_ymin + new_ymax) / 2;
        double new_length = new_xmax - new_xmin;
        double new_width = new_ymax - new_ymin;

        return PersegiPanjang(new_xc, new_yc, new_length, new_width);
    }

    // Operator ++ 
    PersegiPanjang operator++() {
        double new_length = (xmax - xmin) * sqrt(2);
        double new_width = (ymax - ymin) * sqrt(2);
        double new_xc = (xmin + xmax) / 2;
        double new_yc = (ymin + ymax) / 2;

        return PersegiPanjang(new_xc, new_yc, new_length, new_width);
    }

    // Operator -- 
    PersegiPanjang operator--() {
        double new_length = (xmax - xmin) / sqrt(2);
        double new_width = (ymax - ymin) / sqrt(2);
        double new_xc = (xmin + xmax) / 2;
        double new_yc = (ymin + ymax) / 2;

        return PersegiPanjang(new_xc, new_yc, new_length, new_width);
    }

    // Getter untuk xmin
    double getXmin() const {
        return xmin;
    }

    // Getter untuk xmax
    double getXmax() const {
        return xmax;
    }

    // Getter untuk ymin
    double getYmin() const {
        return ymin;
    }

    // Getter untuk ymax
    double getYmax() const {
        return ymax;
    }

    double area() const {
        return (xmax - xmin) * (ymax - ymin);
    }

    bool isOverlapping(const PersegiPanjang& other) const {
        return !(xmin > other.xmax || xmax < other.xmin || ymin > other.ymax || ymax < other.ymin);
    }

    // Operator == 
    bool operator==(const PersegiPanjang& other) const {
        return isOverlapping(other);
    }

    void printInfo() const {
        std::cout << "Persegi Panjang:" << std::endl;
        std::cout << "xmin: " << xmin << std::endl;
        std::cout << "xmax: " << xmax << std::endl;
        std::cout << "ymin: " << ymin << std::endl;
        std::cout << "ymax: " << ymax << std::endl;
        std::cout << "Area: " << area() << std::endl;
    }
};

int main() {
    PersegiPanjang pp1(0.0, 0.0, 4.0, 2.0); 
    PersegiPanjang pp2(1.0, 1.0, 3.0, 2.0); 
    PersegiPanjang pp3(6.0, 6.0, 3.0, 2.0); 

    std::cout << "Persegi Panjang 1:" << std::endl;
    pp1.printInfo();
    std::cout << std::endl;

    std::cout << "Persegi Panjang 2:" << std::endl;
    pp2.printInfo();
    std::cout << std::endl;

    std::cout << "Persegi Panjang 3:" << std::endl;
    pp3.printInfo();
    std::cout << std::endl;

    if (pp1 == pp2) {
        PersegiPanjang ppSum = pp1 + pp2;
        std::cout << "Hasil Penambahan Persegi Panjang 1 dan 2:" << std::endl;
        ppSum.printInfo();
    } else {
        std::cout << "Persegi panjang 1 dan 2 tidak saling beririsan." << std::endl;
    }

    if (pp1 == pp3) {
        PersegiPanjang ppSum = pp1 + pp3;
        std::cout << "Hasil Penambahan Persegi Panjang 1 dan 3:" << std::endl;
        ppSum.printInfo();
    } else {
        std::cout << "\nPersegi panjang 1 dan 3 tidak saling beririsan." << std::endl;
    }

    // Operasi ++
    std::cout << "\nOperasi ++ pada Persegi Panjang 1:" << std::endl;
    PersegiPanjang pp1Plus = ++pp1;
    pp1Plus.printInfo();

    // Operasi --
    std::cout << "\nOperasi -- pada Persegi Panjang 1:" << std::endl;
    PersegiPanjang pp1Minus = --pp1;
    pp1Minus.printInfo();

    return 0;
}


