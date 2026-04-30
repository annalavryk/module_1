#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class Product
{
private:
    string name;
    int price;
    int quantity;

public:
    Product() : name(""), price(0), quantity(0) {}
    Product(string n, int p, int q) : name(n), price(p), quantity(q) {}

    string getName() const { return name; }
    int getPrice() const { return price; }
    int getQuantity() const { return quantity; }


    static bool readFromJson(const string& filename, vector<Product>& products) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Cannot open JSON file\n";
            return false;
        }

        json j;
        file >> j;

        for (const auto& item : j) {
            if (!item.contains("name") || !item.contains("price") || !item.contains("quantity")) {
                cout << "Invalid JSON structure\n";
                return false;
            }

            products.emplace_back(
                item["name"],
                item["price"],
                item["quantity"]
            );
        }

        return true;
    }


    static void filterZeroQuantity(vector<Product>& products) {
        products.erase(
            remove_if(products.begin(), products.end(),
                [](const Product& p) {
                    return p.quantity == 0;
                }),
            products.end()
        );
    }


    static bool writeToCSV(const string& filename, const vector<Product>& products) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Cannot open CSV file\n";
            return false;
        }

        file << "name,price,quantity\n";

        for (const auto& p : products) {
            file << p.name << "," << p.price << "," << p.quantity << "\n";
        }

        return true;
    }

  
    static void printAll(const vector<Product>& products) {
        cout << "Products:\n";
        for (const auto& p : products) {
            cout << p.name << " | " << p.price << " | " << p.quantity << endl;
        }
        cout << "-------------------\n";
    }
};