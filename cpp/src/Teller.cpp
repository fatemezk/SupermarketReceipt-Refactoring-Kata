#include "Teller.h"

Teller::Teller(SupermarketCatalog* catalog) : catalog(catalog) {}

void Teller::addSpecialOffer(SpecialOfferType offerType, const Product& product, double argument) {
    offers[product] = Offer(offerType, product, argument);
}

Receipt Teller::checksOutArticlesFrom(ShoppingCart& theCart) {
    std::vector<ProductQuantity> productQuantities = theCart.getItems();
    Receipt receipt = NullReceipt(); // Initialize with NullReceipt

    if (!productQuantities.empty()) {
        receipt = Receipt(); // Create a new Receipt

        for (const auto& pq : productQuantities) {
            Product p = pq.getProduct();
            double quantity = pq.getQuantity();
            double unitPrice = catalog->getUnitPrice(p);
            double price = quantity * unitPrice;
            receipt.addProduct(p, quantity, unitPrice, price);
        }

        theCart.handleOffers(receipt, offers, catalog);
    }

    return receipt;
}
