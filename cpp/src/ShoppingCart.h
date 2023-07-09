#ifndef CPP_SHOPPINGCART_H
#define CPP_SHOPPINGCART_H


#include <vector>
#include <map>
#include "ProductQuantity.h"
#include "Offer.h"
#include "Receipt.h"
#include "SupermarketCatalog.h"

class ShoppingCart {
public:
    std::vector<ProductQuantity> getItems() const;

    std::map<Product, double> getProductQuantities() const;

    void addItem(const Product& product);

    void addItemQuantity(const Product& product, double quantity);

    Discount* ShoppingCart::discountCalculator(int x , int quantityAsInt , Offer offer , double unitPrice , double quantity , Product product);

    void handleOffers(Receipt& receipt, std::map<Product, Offer> offers, SupermarketCatalog* catalog);

private:
    std::vector<ProductQuantity> items;
    std::map<Product, double> productQuantities;
};


#endif //CPP_SHOPPINGCART_H
