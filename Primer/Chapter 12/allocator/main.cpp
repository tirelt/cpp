#include <memory>
#include <string>

using std::string;
using std::allocator;

int main(){
    int n(10);
    allocator<string> alloc; // object that can allocate strings
    auto const p = alloc.allocate(n); // allocate n unconstructed strings
    auto q = p; // q will point to one past the last constructed element
    alloc.construct(q++); // *q is the empty string
    alloc.construct(q++, 10, 'c'); // *q is cccccccccc
    alloc.construct(q++, "hi"); // *q is hi!
    while (q != p)
        alloc.destroy(--q); //We may destroy only elements that are actually constructed.
    alloc.deallocate(p, n); //free the memory bycalling deallocate

    //uninitialized_copy(b, e, b2)
    //uninitialized_copy_n(b, n, b2)
    //uninitialized_fill(b, e, t)
    //uninitialized_fill_n(b, n, t)
    return 0;
}
