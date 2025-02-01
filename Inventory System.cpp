#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Product{
    private:
        string product_ID;
        string name;
        double cost;
        double price;
        double VAT;

    public:
        
        // Constructor with parameters
        Product(string ID, string name, double cost, double price, double VAT){
            product_ID = ID;
            this -> name = name;
            this -> cost = cost;
            this -> price = price;
            this -> VAT = VAT;
        }

        // Default constructor
        Product(){
            product_ID = "00000";
            name = "Unknown";
            cost = 0;
            price = 0;
            VAT = 0;
        }

        // Getter and setter for product name
        string get_productName(){
            return name;
        }

        void set_productName(string name){
            this -> name = name;
        }

        // Getter and setter for product ID
        string get_productID(){
            return product_ID;
        }

        void set_productID(string ID){
             product_ID = ID;
        }

        // Getter and setter for cost
        double get_cost(){
            return cost;
        }

        void set_cost(double cost){
            this -> cost = cost;
        }

        // Getter and setter for VAT
        double get_VAT(){
            return VAT;
        }

        void set_VAT(double VAT){
            if (VAT <= 0 || VAT >= 1){
                cout << "VAT must be between 0 and 1. Setting to 0!\n" << endl;
                this -> VAT = 0;
            }
            else{
                this -> VAT = VAT;
            }
        }

        // Method to calculate VAT amount
        double cal_vat(){
            double VAT_amt = get_VAT() * get_cost();
            return VAT_amt ;
        }

        // Method to calculate profit
        double profit(){
            double profit = price - (cost - cal_vat());
            return profit;
        }

        // Method to calculate markup percentage
        double markup(){
            double markup = (profit()/cost)*100;
            return markup;
        }

        // Method to display product details
        void display(){
            cout << "Name: " << get_productName() << endl;
            cout << "ID: " << get_productID() << endl;
            cout << "Cost:  R" << get_cost() << endl;
            cout << "Price: R" << price << endl;
            cout << "VAT Amount: R" << cal_vat() << endl;
            cout << "Profit: R" << profit() << endl;
            cout << setprecision(2) << fixed;
            cout << "Markup: " << markup() << "%" << endl;
        }

};

int main(){
    Product Cereal("11111", "Future Life", 60.0, 70.0, 0.14);
    Cereal.display();  

    return 0;
}