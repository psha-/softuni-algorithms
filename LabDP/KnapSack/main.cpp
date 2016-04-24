#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

namespace Knapsack {
    struct Item {
    public:
        int Weight;
        int Price;
        Item(int weight, int price):Weight(weight), Price(price)
        {}
    };

    vector<vector<int>> maxPrice = vector<vector<int>>();
    vector<vector<int>> itemTaken = vector<vector<int>>();

    vector<Item> Items;

    bool IsWorthIt(const Item &item, int i, int c) {
        auto remainingC = c - item.Weight;
        if( maxPrice[i-1][remainingC] + item.Price > maxPrice[i-1][c] ) {
            return true;
        }
        return false;
    }

    vector<Item> GetContents()
    {
        auto taken = vector<Item>();
        int c = maxPrice[0].size()-1;
        for( int i = maxPrice.size()-1; i >= 0 && c >= 0; i--) {
            if( itemTaken[i][c] ) {
                taken.push_back(Items[i]);
                c -= Items[i].Weight;
            }
        }
        return taken;
    }

    void PrintContents()
    {
        auto taken = GetContents();
        int price = 0;
        int weight = 0;
        cout << "Items taken:" << endl;
        for(auto it=taken.begin(); it != taken.end(); it++) {
            printf("Weight: %d, price: %d\n", it->Weight, it->Price);
            price += it->Price;
            weight += it->Weight;
        }
        cout << "Total weight: "  << weight << endl;
        cout << "Total price: "  << price << endl;
    }

    void Fill(const vector<Item> &items, int capacity)
    {
        Items = items;
        for(auto i=0; i<Items.size(); i++) {
            Knapsack::maxPrice.push_back(vector<int>());
            Knapsack::itemTaken.push_back(vector<int>());
        }

        for(int cap=0; cap<=capacity; cap++ ) {
            if( Items[0].Weight <= cap ) {
                maxPrice[0].push_back(Items[0].Price);
                itemTaken[0].push_back(true);
            }
            else {
                maxPrice[0].push_back(0);
                itemTaken[0].push_back(false);
            }
        }

        for( auto i=1; i<Items.size(); i++) {
            for( auto c=0; c<=capacity; c++) {
                maxPrice[i].push_back(maxPrice[i-1][c]);
                itemTaken[i].push_back(false);
                auto remainingC = c - Items[i].Weight;
                if( remainingC >= 0 && IsWorthIt(Items[i], i, c)) {
                    maxPrice[i][c] = maxPrice[i-1][remainingC] + Items[i].Price;
                    itemTaken[i][c] = true;
                }
            }
        }
    }

}

int main()
{
    auto items = vector<Knapsack::Item>({
                                  Knapsack::Item(5, 30),
                                  Knapsack::Item(8, 120),
                                  Knapsack::Item(7, 10),
                                  Knapsack::Item(0, 20),
                                  Knapsack::Item(4, 50),
                                  Knapsack::Item(5, 80),
                                  Knapsack::Item(2, 10),
                              });
    int capacity = 20;

    Knapsack::Fill(items, capacity);
    Knapsack::PrintContents();


    return 0;
}
