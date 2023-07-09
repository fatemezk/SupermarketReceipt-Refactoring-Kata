#ifndef CPP_RECEIPT_H
#define CPP_RECEIPT_H

#include <vector>
#include "Discount.h"
#include "ReceiptItem.h"

class Receipt {
public:
    std::vector<ReceiptItem> getItems() const;

    std::vector<Discount> getDiscounts() const;

    double getTotalPrice() const;

    void addDiscount(const Discount& discount);

    void addProduct(const Product& product, double quantity, double price, double totalPrice);

private:
    std::vector<ReceiptItem> items;
    std::vector<Discount> discounts;
};

// NullReceipt class
class NullReceipt : public Receipt {
public:
    std::vector<ReceiptItem> getItems() const override;
    std::vector<Discount> getDiscounts() const override;
    double getTotalPrice() const override;
    void addDiscount(const Discount& discount) override;
    void addProduct(const Product& product, double quantity, double price, double totalPrice) override;
};

#endif //CPP_RECEIPT_H
