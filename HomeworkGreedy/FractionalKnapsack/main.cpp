#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

namespace Knapsack {
    struct Item {
        float Price;
        float Weight;
    };

    bool operator<(const Item &lhs, const Item &rhs)
    {
        return lhs.Price/lhs.Weight > rhs.Price/rhs.Weight;
    }

    int Capacity;
    float TotalPrice;

    vector<Item> AvailableItems;
    vector<pair<float, Item*>> Items;

    void Init()
    {
        int ItemNum;

        cout << "Capacity: ";
        cin >> Capacity;

        cout << "Items: ";
        cin >> ItemNum;

        AvailableItems = vector<Item>();
        AvailableItems.reserve(ItemNum);
        TotalPrice = 0;
        for( int i=0; i<ItemNum; i++ ) {
            auto item = Item();
            cin >> item.Price;
            cin.ignore(numeric_limits<streamsize>::max(), '>');
            //cin.ignore('>');
            cin >> item.Weight;
            AvailableItems.push_back(item);
        }
        sort(AvailableItems.begin(), AvailableItems.end());
    }

    void Print()
    {
        for( auto it = Items.begin(); it != Items.end(); it++ ) {
            cout << "Take " << fixed << setprecision(2) << (it->first * 100)
                 << "% of item with price " << it->second->Price
                 << " and weight " << it->second->Weight << endl;
        }
        cout << "Total price: " << fixed << setprecision(2) << TotalPrice << endl;
    }

    void Fill()
    {
        Items = vector<pair<float, Item*>>();
        float free = Capacity;
        auto item_it = AvailableItems.begin();
        while(free > 0) {
            if( item_it == AvailableItems.end() ) {
                break;
            }
            float fractionToTake = min(1.0f, free / item_it->Weight);
            free -= fractionToTake * item_it->Weight;
            TotalPrice += fractionToTake * item_it->Price;
            Items.push_back(pair<float, Item*>(fractionToTake, &(*item_it)));
            item_it++;
        }
    }

}

int main()
{
    Knapsack::Init();
    Knapsack::Fill();
    Knapsack::Print();

    return 0;
}

