#include "Product1.h"
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTests
{
    TEST_CLASS(ProductTests)
    {
    public:

        TEST_METHOD(FilterWorks)
        {
            vector<Product> products = {
                {"Coffee", 50, 10},
                {"Tea", 30, 0},
                {"Cake", 70, 5}
            };

            Product::filterZeroQuantity(products);

            Assert::AreEqual((size_t)2, products.size());
        }

        TEST_METHOD(AllZero)
        {
            vector<Product> products = {
                {"Tea", 30, 0},
                {"Milk", 20, 0}
            };

            Product::filterZeroQuantity(products);

            Assert::AreEqual((size_t)0, products.size());
        }

        TEST_METHOD(NoZero)
        {
            vector<Product> products = {
                {"Coffee", 50, 10},
                {"Cake", 70, 5}
            };

            Product::filterZeroQuantity(products);

            Assert::AreEqual((size_t)2, products.size());
        }
    };
}

