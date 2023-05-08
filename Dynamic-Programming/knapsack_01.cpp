#include <iostream>

using namespace std;

class Item{
    private:
        int weight;
        int cost;

    public:
        Item(int weight = 0, int cost = 0){
            this->weight = weight;
            this->cost = cost;
        }

        int get_weight(){return this->weight;}
        int get_cost(){return this->cost;}
};

int knapsack(int weight, int no_items, Item items[]){
    int values[weight+1][no_items + 1];

    for (int i = 0; i <= weight; i++){
        values[i][0] = 0;
    }
    for (int i = 0; i <= no_items; i++){
        values[0][i] = 0;
    }

    for (int i = 1; i <= weight; i++){
        for (int j = 1; j <= no_items; j++){
            if (items[j-1].get_weight() <= i){
                values[i][j] = max(values[i][j-1] , items[j-1].get_cost() + values[i - items[j-1].get_weight()][j-1]);
            }
            else{
                values[i][j] = values[i][j-1];
            }
        }
    }

    for (int i = 0; i <= weight; i++){
        for (int j = 0; j <= no_items; j++){
            cout << values[i][j] << " ";
        }
        cout << endl;
    }

    return values[weight][no_items];
}

int main(){
    int n;
    int weight;

    int item_weight;
    int item_cost;
    
    Item current;
    Item* items;

    cout << "How many items are there ";
    cin >> n;

    cout << "What is the total capacity of the knapsack ";
    cin >> weight;
    items = new Item[n];

    for (int i = 0; i < n; i++){
        cout << "Enter the weight of item number " << i+1 << " ";
        cin >> item_weight;
        cout << "Enter the cost of item number " << i+1 << " ";
        cin >> item_cost;

        current = Item(item_weight , item_cost);
        items[i] = current;
    }

    cout << knapsack(weight , n , items) << endl;


    return 0;
}