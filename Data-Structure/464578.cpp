#include <bits/stdc++.h>
using namespace std;

class Order
{
public:
    int order_id;
    int stock_id;
    double price;
    int quantity;
    char side;
    Order() : order_id {} {}
    Order(int id, int stock, double p, int qty, char s) : order_id(id), stock_id(stock), price(p), quantity(qty), side(s) {}

    void show()
    {
        printf("orderid: %04d, stockid:%04d, price: %6.1lf, quantity: %4d, b/s: %c\n",
               order_id, stock_id, price, quantity, side);
    }
};
struct OrderEntry
{
    int order_id;
    double price;
    char side;

    bool operator<(const OrderEntry &other) const
    {
        if (price != other.price)
        {
            if (side == other.side)
                return side == 'b' ? price > other.price : price < other.price;
            return side < other.side;
        }
        if (order_id != other.order_id)
            return order_id < other.order_id;
        return side < other.side;
    }
};

set<OrderEntry> buy_orders[10005];
set<OrderEntry> sell_orders[10005];
// vector<Order> orderBook;
Order orderBook[10005];
int order_counter = 1;

void matchOrders(set<OrderEntry> &buy_orders, set<OrderEntry> &sell_orders, char side)
{
    while (!buy_orders.empty() && !sell_orders.empty())
    {
        auto buy_it = buy_orders.begin();
        auto sell_it = sell_orders.begin();

        if (buy_it->price < sell_it->price)
            break;
        // 查找订单信息
        Order &buy_order = orderBook[buy_it->order_id];
        Order &sell_order = orderBook[sell_it->order_id];
        int deal_quantity = min(buy_order.quantity, sell_order.quantity);
        double deal_price = (buy_order.price + sell_order.price) / 2.0;
        printf("deal--price:%6.1lf  quantity:%4d  ", deal_price, deal_quantity);
        if (side == 'b')
            printf("buyorder:%04d  sellorder:%04d\n", buy_order.order_id, sell_order.order_id);
        else
            printf("sellorder:%04d  buyorder:%04d\n", sell_order.order_id, buy_order.order_id);

        // 更新订单剩余数量
        buy_order.quantity -= deal_quantity;
        sell_order.quantity -= deal_quantity;
        // 完全成交的订单需要从 set 中移除
        if (buy_order.quantity == 0)
            buy_orders.erase(buy_it);
        if (sell_order.quantity == 0)
            sell_orders.erase(sell_it);
    }
}

// 输出未成交订单

void printOrders(const set<OrderEntry> &buy_orders, const set<OrderEntry> &sell_orders)
{
    printf("buy orders:\n");
    for (const auto &entry : buy_orders)
    {
        auto order = orderBook[entry.order_id];
        if (order.quantity == 0)
            continue;
        order.show();
    }

    printf("sell orders:\n");
    for (const auto &entry : sell_orders)
    {
        auto order = orderBook[entry.order_id];
        if (order.quantity == 0)
            continue;
        order.show();
    }
}

void deleteOrders(const int &order_id)
{
    if (order_id < 1 || order_id > order_counter)
        return puts("not found"), void();
    auto order = orderBook[order_id];
    if (!order.order_id)
        return puts("not found"), void();
    int stock_id = order.stock_id;
    char side = order.side;
    auto &orders = side == 'b' ? buy_orders[stock_id] : sell_orders[stock_id];
    auto order_entry = (OrderEntry){order_id, order.price, side};
    if (orders.find(order_entry) == orders.end())
        puts("not found");
    else
    {
        orders.erase(orders.find(order_entry));
        printf("deleted order:");
        order.show();
    }
}
int main()
{
    while (true)
    {
        int command;
        scanf("%d", &command);
        if (command == 1)
        {
            double price;
            char side;
            int stock_id, quantity;
            scanf("%d %lf %d %c", &stock_id, &price, &quantity, &side);
            printf("orderid: %04d\n", order_counter);
            orderBook[order_counter] = (Order(order_counter, stock_id, price, quantity, side));
            if (side == 'b')
                buy_orders[stock_id].insert({order_counter, price, side});
            else if (quantity > 0)
                sell_orders[stock_id].insert({order_counter, price, side});
            matchOrders(buy_orders[stock_id], sell_orders[stock_id], side);
            order_counter++;
        }
        else if (command == 2)
        {
            int query_stock_id;
            scanf("%d", &query_stock_id);
            printOrders(buy_orders[query_stock_id], sell_orders[query_stock_id]);
        }
        else if (command == 3)
        {
            int query_order_id;
            scanf("%d", &query_order_id);
            deleteOrders(query_order_id);
        }
        else if (command == 0)
            break;
    }
}
