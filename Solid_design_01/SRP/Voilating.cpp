#include<bits/stdc++.h>
using namespace std;

class Product{
    public:
    string name;
    double price;

    Product(string name ,double price){
        this->name =name;
        this->price = price;
    }
};

class ShoppingCart{
    private:
    vector<Product*>products;

    public:

    void addProduct(Product * p){
        products.push_back(p);
    }

    const vector<Product *> getProduct(){
        return products;
    }

    double calculateTotal(){
        double sum=0;
        for(int i=0;i<products.size();i++){
            sum+=products[i]->price;
        }
        return sum;
    }


    void printInvoice(){
        for(auto it : products){
            cout<<"Product Name "<<it->name<<endl;
            cout<<"Product Price "<<it->price<<endl;
        }
    }

    void SaveToDB(){
        cout<<"Saved To DB"<<endl;
    }
};


int main(){
    ShoppingCart * shop = new ShoppingCart();
    shop->addProduct(new Product("Television",50000));
    shop->addProduct(new Product("desktop",30000));
    shop->addProduct(new Product("Ceiling Fan",20000));

    cout<<shop->calculateTotal()<<endl;
    shop->SaveToDB();
    shop->printInvoice();
}
