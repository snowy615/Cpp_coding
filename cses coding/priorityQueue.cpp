//#include <queue> <functional>
//priority_queue<int>pq
//priority_queue<int,vector<int>,greater<int>>pq;
//.push().pop().top().empty().size()

#include <functional>
#include <iostream>
#include <queue>
#include <string_view>
#include <vector>

template<typename T>
void pop_println(std::string_view rem, T& pq)
{
    std::cout << rem << ": ";
    for (; !pq.empty(); pq.pop())
        std::cout << pq.top() << ' ';
    std::cout << '\n';
}

template<typename T>
void println(std::string_view rem, const T& v)
{
    std::cout << rem << ": ";
    for (const auto& e : v)
        std::cout << e << ' ';
    std::cout << '\n';
}

int main()
{
    const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    println("data", data);

    std::priority_queue<int> max_priority_queue;

    // Fill the priority queue.
    for (int n : data)
        max_priority_queue.push(n);

    pop_println("max_priority_queue", max_priority_queue);

    // std::greater<int> makes the max priority queue act as a min priority queue.
    std::priority_queue<int, std::vector<int>, std::greater<int>>
            min_priority_queue1(data.begin(), data.end());

    pop_println("min_priority_queue1", min_priority_queue1);

    // Second way to define a min priority queue.
    std::priority_queue min_priority_queue2(data.begin(), data.end(), std::greater<int>());

    pop_println("min_priority_queue2", min_priority_queue2);

    // Using a custom function object to compare elements.
    struct
    {
        bool operator()(const int l, const int r) const { return l > r; }
    } customLess;

    std::priority_queue custom_priority_queue(data.begin(), data.end(), customLess);

    pop_println("custom_priority_queue", custom_priority_queue);

    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> lambda_priority_queue(cmp);

    for (int n : data)
        lambda_priority_queue.push(n);

    pop_println("lambda_priority_queue", lambda_priority_queue);
}