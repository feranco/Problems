#include <queue>
#include <array>
#include <utility>

using std::queue;
using std::array;

template <typename T>
class StackFromQueues {
  array<queue<T>,2> queues;
  size_t pushQueue, popQueue;

public:
  StackFromQueues () : pushQueue(0), popQueue(1){}
  void push (const T& item) {
    queues[pushQueue].push(item);
  }

  T pop () {
    while (queues[pushQueue].size() > 1) {
      queues[popQueue].push(queues[pushQueue].front());
      queues[pushQueue].pop();
    }

    T popValue = queues[pushQueue].front();
    queues[pushQueue].pop();
    std::swap(pushQueue,popQueue);
    return popValue;
  }
};
