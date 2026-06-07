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

};


class ShopingCartPrinter{
    private:
    ShoppingCart * cart;

    public:

    ShopingCartPrinter(ShoppingCart *p){
        this->cart=p;
    }
    void printInvoice(){
        for(auto it : cart->getProduct()){
            cout<<"Product Name "<<it->name<<endl;
            cout<<"Product Price "<<it->price<<endl;
        }
    }

};



// The ShoppingCartStorage class violates the Open/Closed Principle because it directly implements multiple storage mechanisms (SQL, MongoDB, and File). Whenever a new storage type is required, the existing class must be modified by adding another save method. This means the class is not closed for modification. According to the Open/Closed Principle, new functionality should be added through extension rather than changing existing, tested code. A better design would use an abstraction (such as a Storage interface) and separate storage-specific classes, allowing new storage mechanisms to be introduced without modifying existing code


class ShopingCartStorage{
    private:
    ShoppingCart * cart;

    public:

    virtual void save(ShoppingCart * Cart) =0; // this is pure virtual function

};


class Store_to_SQL : public ShopingCartStorage{
    public:

    void save(ShoppingCart * cart) override{
        cout << "Saving shopping cart to SQL database..." << endl;
    }
};


class Store_to_NOSQL : public ShopingCartStorage{
    public:

    void save(ShoppingCart * cart) override{
        cout << "Saving shopping cart to NOSQL database..." << endl;
    }
};


class Store_to_FILES: public ShopingCartStorage{
    public:

    void save(ShoppingCart * cart) override{
        cout << "Saving shopping cart to Files database..." << endl;
    }
};


int main(){
    ShoppingCart * shop = new ShoppingCart();
    shop->addProduct(new Product("Television",50000));
    shop->addProduct(new Product("desktop",30000));
    shop->addProduct(new Product("Ceiling Fan",20000));

    ShopingCartPrinter * print1 = new ShopingCartPrinter(shop);
    print1->printInvoice();

    Store_to_SQL * A = new Store_to_SQL();
    Store_to_NOSQL * B = new Store_to_NOSQL();
    Store_to_FILES * C = new Store_to_FILES();

    A->save(shop);
    B->save(shop);
    C->save(shop);
    delete A,B,C,shop;

    return 0;
}
