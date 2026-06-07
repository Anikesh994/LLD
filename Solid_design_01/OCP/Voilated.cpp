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

    ShopingCartStorage(ShoppingCart * c){
        this->cart =c;
    }

    void SavedTo_SQL(){
        cout << "Saving shopping cart to SQL database..." << endl;
    }

    void SavedTo_NOSQL(){
        cout << "Saving shopping cart to NO-SQL database..." << endl;
    }

    void SavedTo_Files(){
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

    ShopingCartStorage *db =new ShopingCartStorage(shop);
    db->SavedTo_SQL();

    return 0;
}
